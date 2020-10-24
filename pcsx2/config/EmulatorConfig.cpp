#include "PrecompiledHeader.h"

#include "EmulatorConfig.h"

#include <wx/stdpaths.h>
#include "Utilities/Path.h"
#include "App.h"

#include <wx/fileconf.h>

#include "EmulatorConfig.h"
#include "GS.h"
#include "gui/GSFrame.h"

YAML::Node TraceLogFilters::LoadSave()
{
	//ScopedIniGroup path( json, L"TraceLog" );

	//IniEntry( Enabled );

	// Retaining backwards compat of the trace log enablers isn't really important, and
	// doing each one by hand would be murder.  So let's cheat and just save it as an int:

	//json.push_back(EE);
	//json.push_back(IOP);

	return YAML::Node();
}

Pcsx2Config::SpeedhackOptions::SpeedhackOptions()
{
	DisableAll();

	WaitLoop = true;
	IntcStat = true;
	vuFlagHack = true;
}

Pcsx2Config::SpeedhackOptions& Pcsx2Config::SpeedhackOptions::DisableAll()
{
	EECycleRate = 0;
	EECycleSkip = 0;
	return *this;
}

void Pcsx2Config::SpeedhackOptions::load(std::shared_ptr<YamlConfigFile> configSection)
{
	YamlConfigFile* cfg = configSection.get();

	EECycleRate = cfg->getChar("EECycleRate");
	EECycleSkip = cfg->getChar("EECycleSkip");

	fastCDVD = cfg->getBool("fastCDVD");
	IntcStat = cfg->getBool("IntcStat");

	// Set recommended speedhacks to enabled by default. They'll still be off globally on resets.
	WaitLoop = cfg->getBool("WaitLoop", true);
	vuFlagHack = cfg->getBool("vuFlagHack", true);
	vuThread = cfg->getBool("vuThread", true);
}

std::shared_ptr<YamlConfigFile> Pcsx2Config::SpeedhackOptions::save()
{
	std::shared_ptr<YamlConfigFile> config = std::make_shared<YamlConfigFile>();
	YamlConfigFile* cfg = config.get();

	cfg->setChar("EECycleRate", EECycleRate);
	cfg->setChar("EECycleSkip", EECycleSkip);

	cfg->setBool("fastCDVD", fastCDVD);
	cfg->setBool("IntcStat", IntcStat);

	// Set recommended speedhacks to enabled by default. They'll still be off globally on resets.
	cfg->setBool("WaitLoop", WaitLoop);
	cfg->setBool("vuFlagHack", vuFlagHack);
	cfg->setBool("vuThread", vuThread);

	return config;
}

void Pcsx2Config::ProfilerOptions::load(std::shared_ptr<YamlConfigFile> configSection)
{
	YamlConfigFile* cfg = configSection.get();

	EnableProfiler = cfg->getBool("EnableProfiler");
	RecBlocks_EE = cfg->getBool("RecBlocks_EE");
	RecBlocks_IOP = cfg->getBool("RecBlocks_IOP");
	RecBlocks_VU0 = cfg->getBool("RecBlocks_VU0");
	RecBlocks_VU1 = cfg->getBool("RecBlocks_VU1");
}

std::shared_ptr<YamlConfigFile> Pcsx2Config::ProfilerOptions::save()
{
	std::shared_ptr<YamlConfigFile> config = std::make_shared<YamlConfigFile>();
	YamlConfigFile* cfg = config.get();

	cfg->setBool("EnableProfiler", EnableProfiler);
	cfg->setBool("RecBlocks_EE", RecBlocks_EE);
	cfg->setBool("RecBlocks_IOP", RecBlocks_IOP);
	cfg->setBool("RecBlocks_VU0", RecBlocks_VU0);
	cfg->setBool("RecBlocks_VU1", RecBlocks_VU1);

	return config;
}


Pcsx2Config::CpuOptions::CpuOptions()
{
	sseMXCSR.bitmask = DEFAULT_sseMXCSR;
	sseVUMXCSR.bitmask = DEFAULT_sseVUMXCSR;
}

void Pcsx2Config::CpuOptions::load(std::shared_ptr<YamlConfigFile> configSection)
{
	YamlConfigFile* cfg = configSection.get();

	sseVUMXCSR.DenormalsAreZero = cfg->getU32("VU.DenormalsAreZero");
	sseVUMXCSR.FlushToZero = cfg->getU32("VU.FlushToZero");
	sseVUMXCSR.RoundingControl = cfg->getU32("VU.RoundingControl");

	sseMXCSR.DenormalsAreZero = cfg->getU32("FPU.DenormalsAreZero");
	sseMXCSR.FlushToZero = cfg->getU32("FPU.FlushToZero");
	sseMXCSR.RoundingControl = cfg->getU32("FPU.RoundingControl");
}

std::shared_ptr<YamlConfigFile> Pcsx2Config::CpuOptions::save()
{
	std::shared_ptr<YamlConfigFile> config = std::make_shared<YamlConfigFile>();
	YamlConfigFile* cfg = config.get();

	cfg->setU32("VU.DenormalsAreZero", sseVUMXCSR.DenormalsAreZero);
	cfg->setU32("VU.FlushToZero", sseVUMXCSR.FlushToZero);
	cfg->setU32("VU.RoundingControl", sseVUMXCSR.RoundingControl);

	cfg->setU32("FPU.DenormalsAreZero", sseMXCSR.DenormalsAreZero);
	cfg->setU32("FPU.FlushToZero", sseMXCSR.FlushToZero);
	cfg->setU32("FPU.RoundingControl", sseMXCSR.RoundingControl);

	return config;
}

void Pcsx2Config::CpuOptions::ApplySanityCheck()
{
	sseMXCSR.ClearExceptionFlags().DisableExceptions();
	sseVUMXCSR.ClearExceptionFlags().DisableExceptions();

	Recompiler.ApplySanityCheck();
}

// Default GSOptions
Pcsx2Config::GSOptions::GSOptions()
{
	FrameLimitEnable = true;
	FrameSkipEnable = false;
	VsyncEnable = VsyncMode::Off;

	SynchronousMTGS = false;
	VsyncQueueSize = 2;

	FramesToDraw = 2;
	FramesToSkip = 2;

	LimitScalar = 1.0;
	FramerateNTSC = 59.94;
	FrameratePAL = 50.0;
}

void Pcsx2Config::GSOptions::load(std::shared_ptr<YamlConfigFile> configSection)
{
	YamlConfigFile* cfg = configSection.get();

	FrameLimitEnable = cfg->getBool("SynchronousMTGS", true);
	FrameSkipEnable = cfg->getBool("SynchronousMTGS", false);
	VsyncEnable = static_cast<VsyncMode>(cfg->getInt("VsyncEnable", enum_cast(VsyncMode::Off)));

	SynchronousMTGS = cfg->getBool("SynchronousMTGS", false);
	VsyncQueueSize = cfg->getU32("VsyncQueueSize", 2);

	FramesToDraw = cfg->getInt("FramesToDraw", 2);
	FramesToSkip = cfg->getInt("FramesToSkip", 2);

	LimitScalar = cfg->getFloat("LimitScalar", 1.0);
	FramerateNTSC = cfg->getFloat("LimitScalar", 59.94);
	FrameratePAL = cfg->getFloat("LimitScalar", 50.0);
}

std::shared_ptr<YamlConfigFile> Pcsx2Config::GSOptions::save()
{
	std::shared_ptr<YamlConfigFile> config = std::make_shared<YamlConfigFile>();
	YamlConfigFile* cfg = config.get();

	cfg->setBool("SynchronousMTGS", FrameLimitEnable);
	cfg->setBool("SynchronousMTGS", FrameSkipEnable);
	cfg->setInt("VsyncEnable", enum_cast(VsyncEnable));

	cfg->setBool("SynchronousMTGS", SynchronousMTGS);
	cfg->setU32("VsyncQueueSize", VsyncQueueSize);

	cfg->setInt("FramesToDraw", FramesToDraw);
	cfg->setInt("FramesToSkip", FramesToSkip);

	cfg->setFloat("LimitScalar", LimitScalar);
	cfg->setFloat("LimitScalar", FramerateNTSC);
	cfg->setFloat("LimitScalar", FrameratePAL);

	return std::shared_ptr<YamlConfigFile>();
}

int Pcsx2Config::GSOptions::GetVsync() const
{
	if (g_LimiterMode == Limit_Turbo || !FrameLimitEnable)
		return 0;

	// D3D only support a boolean state. OpenGL waits a number of vsync
	// interrupt (negative value for late vsync).
	switch (VsyncEnable)
	{
		case VsyncMode::Adaptive:
			return -1;
		case VsyncMode::Off:
			return 0;
		case VsyncMode::On:
			return 1;

		default:
			return 0;
	}
}

const wxChar* const tbl_GamefixNames[] =
	{
		L"VuAddSub",
		L"FpuCompare",
		L"FpuMul",
		L"FpuNegDiv",
		L"XGKick",
		L"IpuWait",
		L"EETiming",
		L"SkipMpeg",
		L"OPHFlag",
		L"DMABusy",
		L"VIFFIFO",
		L"VIF1Stall",
		L"GIFFIFO",
		L"GoemonTlb",
		L"ScarfaceIbit",
		L"CrashTagTeamRacingIbit",
		L"VU0Kickstart"};

const __fi wxChar* EnumToString(GamefixId id)
{
	return tbl_GamefixNames[id];
}

// all gamefixes are disabled by default.
Pcsx2Config::GamefixOptions::GamefixOptions()
{
	DisableAll();
}

void Pcsx2Config::GamefixOptions::load(std::shared_ptr<YamlConfigFile> configSection)
{
	YamlConfigFile* cfg = configSection.get();

	VuAddSubHack = cfg->getBool("VuAddSubHack");
	FpuCompareHack = cfg->getBool("FpuCompareHack");
	FpuMulHack = cfg->getBool("FpuMulHack");
	FpuNegDivHack = cfg->getBool("FpuNegDivHack");
	XgKickHack = cfg->getBool("XgKickHack");
	IPUWaitHack = cfg->getBool("IPUWaitHack");
	EETimingHack = cfg->getBool("EETimingHack");
	SkipMPEGHack = cfg->getBool("SkipMPEGHack");
	OPHFlagHack = cfg->getBool("OPHFlagHack");
	DMABusyHack = cfg->getBool("DMABusyHack");
	VIFFIFOHack = cfg->getBool("VIFFIFOHack");
	VIF1StallHack = cfg->getBool("VIF1StallHack");
	GIFFIFOHack = cfg->getBool("GIFFIFOHack");
	FMVinSoftwareHack = cfg->getBool("FMVinSoftwareHack");
	GoemonTlbHack = cfg->getBool("GoemonTlbHack");
	ScarfaceIbit = cfg->getBool("ScarfaceIbit");
	CrashTagTeamRacingIbit = cfg->getBool("CrashTagTeamRacingIbit");
}

std::shared_ptr<YamlConfigFile> Pcsx2Config::GamefixOptions::save()
{
	std::shared_ptr<YamlConfigFile> config = std::make_shared<YamlConfigFile>();
	YamlConfigFile* cfg = config.get();

	cfg->setBool("VuAddSubHack", VuAddSubHack);
	cfg->setBool("FpuCompareHack", FpuCompareHack);
	cfg->setBool("FpuMulHack", FpuMulHack);
	cfg->setBool("FpuNegDivHack", FpuNegDivHack);
	cfg->setBool("XgKickHack", XgKickHack);
	cfg->setBool("IPUWaitHack", IPUWaitHack);
	cfg->setBool("EETimingHack", EETimingHack);
	cfg->setBool("SkipMPEGHack", SkipMPEGHack);
	cfg->setBool("OPHFlagHack", OPHFlagHack);
	cfg->setBool("DMABusyHack", DMABusyHack);
	cfg->setBool("VIFFIFOHack", VIFFIFOHack);
	cfg->setBool("VIF1StallHack", VIF1StallHack);
	cfg->setBool("GIFFIFOHack", GIFFIFOHack);
	cfg->setBool("FMVinSoftwareHack", FMVinSoftwareHack);
	cfg->setBool("GoemonTlbHack", GoemonTlbHack);
	cfg->setBool("ScarfaceIbit", ScarfaceIbit);
	cfg->setBool("CrashTagTeamRacingIbit", CrashTagTeamRacingIbit);

	return config;
}

Pcsx2Config::GamefixOptions& Pcsx2Config::GamefixOptions::DisableAll()
{
	return *this;
}

// Enables a full list of gamefixes.  The list can be either comma or pipe-delimited.
//   Example:  "XGKick,IpuWait"  or  "EEtiming,FpuCompare"
// If an unrecognized tag is encountered, a warning is printed to the console, but no error
// is generated.  This allows the system to function in the event that future versions of
// PCSX2 remove old hacks once they become obsolete.
void Pcsx2Config::GamefixOptions::Set(const std::string& list, bool enabled)
{
	//wxStringTokenizer izer( list, L",|", wxTOKEN_STRTOK );

	//while( izer.HasMoreTokens() )
	//{
	//wxString token( izer.GetNextToken() );

	//GamefixId i;
	//for (i=GamefixId_FIRST; i < pxEnumEnd; ++i)
	//{
	//	if( token.CmpNoCase( EnumToString(i) ) == 0 ) break;
	//}
	//if( i < pxEnumEnd ) Set( i );
	//}
}

void Pcsx2Config::GamefixOptions::Set(GamefixId id, bool enabled)
{
	EnumAssert(id);
	switch (id)
	{
		case Fix_VuAddSub:
			VuAddSubHack = enabled;
			break;
		case Fix_FpuCompare:
			FpuCompareHack = enabled;
			break;
		case Fix_FpuMultiply:
			FpuMulHack = enabled;
			break;
		case Fix_FpuNegDiv:
			FpuNegDivHack = enabled;
			break;
		case Fix_XGKick:
			XgKickHack = enabled;
			break;
		case Fix_IpuWait:
			IPUWaitHack = enabled;
			break;
		case Fix_EETiming:
			EETimingHack = enabled;
			break;
		case Fix_SkipMpeg:
			SkipMPEGHack = enabled;
			break;
		case Fix_OPHFlag:
			OPHFlagHack = enabled;
			break;
		case Fix_DMABusy:
			DMABusyHack = enabled;
			break;
		case Fix_VIFFIFO:
			VIFFIFOHack = enabled;
			break;
		case Fix_VIF1Stall:
			VIF1StallHack = enabled;
			break;
		case Fix_GIFFIFO:
			GIFFIFOHack = enabled;
			break;
		case Fix_GoemonTlbMiss:
			GoemonTlbHack = enabled;
			break;
		case Fix_ScarfaceIbit:
			ScarfaceIbit = enabled;
			break;
		case Fix_CrashTagTeamIbit:
			CrashTagTeamRacingIbit = enabled;
			break;
		case Fix_VU0Kickstart:
			VU0KickstartHack = enabled;
			break;
			jNO_DEFAULT;
	}
}

bool Pcsx2Config::GamefixOptions::Get(GamefixId id) const
{
	EnumAssert(id);
	switch (id)
	{
		case Fix_VuAddSub:
			return VuAddSubHack;
		case Fix_FpuCompare:
			return FpuCompareHack;
		case Fix_FpuMultiply:
			return FpuMulHack;
		case Fix_FpuNegDiv:
			return FpuNegDivHack;
		case Fix_XGKick:
			return XgKickHack;
		case Fix_IpuWait:
			return IPUWaitHack;
		case Fix_EETiming:
			return EETimingHack;
		case Fix_SkipMpeg:
			return SkipMPEGHack;
		case Fix_OPHFlag:
			return OPHFlagHack;
		case Fix_DMABusy:
			return DMABusyHack;
		case Fix_VIFFIFO:
			return VIFFIFOHack;
		case Fix_VIF1Stall:
			return VIF1StallHack;
		case Fix_GIFFIFO:
			return GIFFIFOHack;
		case Fix_GoemonTlbMiss:
			return GoemonTlbHack;
		case Fix_ScarfaceIbit:
			return ScarfaceIbit;
		case Fix_CrashTagTeamIbit:
			return CrashTagTeamRacingIbit;
		case Fix_VU0Kickstart:
			return VU0KickstartHack;
			jNO_DEFAULT;
	}
	return false; // unreachable, but we still need to suppress warnings >_<
}

Pcsx2Config::DebugOptions::DebugOptions()
{
}

void Pcsx2Config::DebugOptions::load(std::shared_ptr<YamlConfigFile> configSection)
{
	YamlConfigFile* cfg = configSection.get();

	ShowDebuggerOnStart = cfg->getBool("ShowDebuggerOnStart", false);
	AlignMemoryWindowStart = cfg->getBool("AlignMemoryWindowStart", true);
	FontWidth = cfg->getChar("FontWidth", 8);
	FontHeight = cfg->getChar("FontHeight", 12);
	WindowWidth = cfg->getU32("WindowWidth", 0);
	WindowHeight = cfg->getU32("WindowHeight", 0);
	MemoryViewBytesPerRow = cfg->getU32("MemoryViewBytesPerRow", 16);
}

std::shared_ptr<YamlConfigFile> Pcsx2Config::DebugOptions::save()
{
	std::shared_ptr<YamlConfigFile> config = std::make_shared<YamlConfigFile>();
	YamlConfigFile* cfg = config.get();

	cfg->setBool("ShowDebuggerOnStart", ShowDebuggerOnStart);
	cfg->setBool("AlignMemoryWindowStart", AlignMemoryWindowStart);
	cfg->setChar("FontWidth", FontWidth);
	cfg->setChar("FontHeight", FontHeight);
	cfg->setU32("WindowWidth", WindowWidth);
	cfg->setU32("WindowHeight", WindowHeight);
	cfg->setU32("MemoryViewBytesPerRow", MemoryViewBytesPerRow);

	return config;
}

Pcsx2Config::RecompilerOptions::RecompilerOptions() {}

void Pcsx2Config::RecompilerOptions::ApplySanityCheck()
{
	bool fpuIsRight = true;

	if (fpuExtraOverflow)
		fpuIsRight = fpuOverflow;

	if (fpuFullMode)
		fpuIsRight = fpuOverflow && fpuExtraOverflow;

	if (!fpuIsRight)
	{
		// Values are wonky; assume the defaults.
		fpuOverflow = RecompilerOptions().fpuOverflow;
		fpuExtraOverflow = RecompilerOptions().fpuExtraOverflow;
		fpuFullMode = RecompilerOptions().fpuFullMode;
	}

	bool vuIsOk = true;

	if (vuExtraOverflow)
		vuIsOk = vuIsOk && vuOverflow;
	if (vuSignOverflow)
		vuIsOk = vuIsOk && vuExtraOverflow;

	if (!vuIsOk)
	{
		// Values are wonky; assume the defaults.
		vuOverflow = RecompilerOptions().vuOverflow;
		vuExtraOverflow = RecompilerOptions().vuExtraOverflow;
		vuSignOverflow = RecompilerOptions().vuSignOverflow;
		vuUnderflow = RecompilerOptions().vuUnderflow;
	}
}

void Pcsx2Config::RecompilerOptions::load(std::shared_ptr<YamlConfigFile> configSection)
{
	YamlConfigFile* cfg = configSection.get();

	EnableEE = cfg->getBool("EnableEE", true);
	EnableIOP = cfg->getBool("EnableIOP", true);
	EnableEECache = cfg->getBool("EnableEECache", false);
	EnableVU0 = cfg->getBool("EnableVU0", true);
	EnableVU1 = cfg->getBool("EnableVU1", true);

	vuOverflow = cfg->getBool("vuOverflow", true);
	vuExtraOverflow = cfg->getBool("vuExtraOverflow", false);
	vuSignOverflow = cfg->getBool("vuSignOverflow", false);
	vuUnderflow = cfg->getBool("vuUnderflow", false);

	fpuOverflow = cfg->getBool("fpuOverflow", true);
	fpuExtraOverflow = cfg->getBool("fpuExtraOverflow", false);
	fpuFullMode = cfg->getBool("fpuFullMode", false);

	StackFrameChecks = cfg->getBool("StackFrameChecks", false);
	PreBlockCheckEE = cfg->getBool("PreBlockCheckEE", false);
	PreBlockCheckIOP = cfg->getBool("PreBlockCheckIOP");
}

std::shared_ptr<YamlConfigFile> Pcsx2Config::RecompilerOptions::save()
{
	std::shared_ptr<YamlConfigFile> config = std::make_shared<YamlConfigFile>();
	YamlConfigFile* cfg = config.get();

	cfg->setBool("EnableEE", EnableEE);
	cfg->getBool("EnableIOP", EnableIOP);
	cfg->getBool("EnableEECache", EnableEECache);
	cfg->getBool("EnableVU0", EnableVU0);
	cfg->getBool("EnableVU1", EnableVU1);

	cfg->getBool("vuOverflow", vuOverflow);
	cfg->getBool("vuExtraOverflow", vuExtraOverflow);
	cfg->getBool("vuSignOverflow", vuSignOverflow);
	cfg->getBool("vuUnderflow", vuUnderflow);

	cfg->getBool("fpuOverflow", fpuOverflow);
	cfg->getBool("fpuExtraOverflow", fpuExtraOverflow);
	cfg->getBool("fpuFullMode", fpuFullMode);

	cfg->getBool("StackFrameChecks", StackFrameChecks);
	cfg->getBool("PreBlockCheckEE", PreBlockCheckEE);
	cfg->getBool("PreBlockCheckIOP", PreBlockCheckIOP);

	return config;
}

Pcsx2Config::Pcsx2Config()
{
	config = std::make_unique<YamlConfigFile>();
}

// TODO - bool for success?
void Pcsx2Config::loadFromFile(fs::path settingsFolder)
{
	// TODO - construct the right path
	YamlConfigFile* cfg = config.get();
	cfg->loadFromFile(settingsFolder);

	YamlConfigFile* coreCfg = cfg->getSection("Core").get();
	CdvdVerboseReads = coreCfg->getBool("CdvdVerboseReads");
	CdvdDumpBlocks = coreCfg->getBool("CdvdDumpBlocks");
	CdvdShareWrite = coreCfg->getBool("CdvdShareWrite");
	EnablePatches = coreCfg->getBool("EnablePatches", true);
	EnableCheats = coreCfg->getBool("EnableCheats");
	EnableWideScreenPatches = coreCfg->getBool("EnableWideScreenPatches");
#ifndef DISABLE_RECORDING
	EnableRecordingTools = coreCfg->getBool("EnableRecordingTools");
#endif
	ConsoleToStdio = coreCfg->getBool("ConsoleToStdio");
	HostFs = coreCfg->getBool("HostFs");
	BackupSavestate = coreCfg->getBool("BackupSavestate", true);
	McdEnableEjection = coreCfg->getBool("McdEnableEjection", true);
	McdFolderAutoManage = coreCfg->getBool("McdFolderAutoManage", true);
	MultitapPort0_Enabled = coreCfg->getBool("MultitapPort0_Enabled");
	MultitapPort1_Enabled = coreCfg->getBool("MultitapPort1_Enabled");

	Recompiler.load(cfg->getSection("Recompiler"));
	Speedhacks.load(cfg->getSection("SpeedHacks"));
	Gamefixes.load(cfg->getSection("GameFixes"));
	Profiler.load(cfg->getSection("Profiler"));
	Debugger.load(cfg->getSection("Debugger"));
	Cpu.load(cfg->getSection("Cpu"));
	GS.load(cfg->getSection("GS"));
}

void Pcsx2Config::saveToFile(fs::path settingsFolder)
{
	YamlConfigFile* cfg = config.get();
	YamlConfigFile* coreCfg = cfg->getSection("Core").get();

	coreCfg->setBool("CdvdVerboseReads", CdvdVerboseReads);
	coreCfg->setBool("CdvdDumpBlocks", CdvdDumpBlocks);
	coreCfg->setBool("CdvdShareWrite", CdvdShareWrite);
	coreCfg->setBool("EnablePatches", EnablePatches);
	coreCfg->setBool("EnableCheats", EnableCheats);
	coreCfg->setBool("EnableWideScreenPatches", EnableWideScreenPatches);
#ifndef DISABLE_RECORDING
	coreCfg->setBool("EnableRecordingTools", EnableRecordingTools);
#endif
	coreCfg->setBool("ConsoleToStdio", ConsoleToStdio);
	coreCfg->setBool("HostFs", HostFs);
	coreCfg->setBool("BackupSavestate", BackupSavestate);
	coreCfg->setBool("McdEnableEjection", McdEnableEjection);
	coreCfg->setBool("McdFolderAutoManage", McdFolderAutoManage);
	coreCfg->setBool("MultitapPort0_Enabled", MultitapPort0_Enabled);
	coreCfg->setBool("MultitapPort1_Enabled", MultitapPort1_Enabled);

	cfg->setSection("Recompiler", Recompiler.save());
	cfg->setSection("SpeedHacks", Speedhacks.save());
	cfg->setSection("GameFixes", Gamefixes.save());
	cfg->setSection("Profiler", Profiler.save());
	cfg->setSection("Debugger", Debugger.save());
	cfg->setSection("Cpu", Cpu.save());
	cfg->setSection("GS", GS.save());

	// Save to file
	config.get()->saveToFile(settingsFolder);
}

bool Pcsx2Config::MultitapEnabled(uint port) const
{
	pxAssert(port < 2);
	return (port == 0) ? MultitapPort0_Enabled : MultitapPort1_Enabled;
}
