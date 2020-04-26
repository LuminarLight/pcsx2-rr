#pragma once

#include "Pcsx2Types.h"
#include <wx/gdicmn.h>

class res_startPressed
{
public:
	static const uint Length = 676;
	static const u8 Data[Length];
	static wxBitmapType GetFormat() { return wxBITMAP_TYPE_PNG; }
};

const u8 res_startPressed::Data[Length] =
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,0x00,
	0x00,0x00,0x36,0x00,0x00,0x00,0x21,0x08,0x06,0x00,0x00,0x00,0x92,0x96,0x58,0xfe,0x00,
	0x00,0x02,0x6b,0x49,0x44,0x41,0x54,0x58,0x85,0xd5,0x99,0xcd,0x4b,0x54,0x51,0x18,0x87,
	0x1f,0x63,0x84,0xa1,0xb6,0x41,0x4b,0x89,0x14,0x6c,0xd3,0x5f,0x10,0xb9,0x68,0x13,0xed,
	0xa2,0x5a,0x07,0xad,0x83,0x4a,0xda,0xcf,0xde,0x4d,0xff,0x86,0x50,0xb8,0x28,0x2a,0xa5,
	0x6c,0x14,0x27,0xf3,0xa3,0x41,0x51,0x63,0x12,0x85,0x14,0x29,0x72,0xc6,0x0f,0x0c,0xb2,
	0xc8,0xb0,0x78,0xe1,0x77,0xe3,0x74,0x89,0xf1,0x8e,0xf7,0x63,0xee,0xf9,0xc1,0xcb,0xcc,
	0x5c,0xee,0xbd,0xe7,0x3c,0xf3,0x9e,0xf7,0xe3,0x9e,0xdb,0x51,0x2a,0x95,0x90,0xae,0x00,
	0xbd,0xc0,0x7b,0x60,0x06,0xd8,0xc3,0x63,0x15,0x34,0xf5,0x3b,0xc0,0x43,0xfd,0x3e,0x00,
	0xd6,0x80,0xa7,0xc0,0x04,0x50,0x05,0x36,0x7c,0x43,0x0c,0xc0,0xae,0x3b,0xdf,0x3b,0x81,
	0x1e,0xa0,0x5f,0xb6,0x02,0x4c,0x02,0x15,0x60,0x1c,0x58,0x05,0x7e,0xb7,0x71,0xce,0x91,
	0x64,0x30,0x1d,0xc0,0xcf,0x26,0x27,0xf7,0xc8,0x6e,0x01,0x9b,0xc0,0x1c,0x30,0x0a,0xcc,
	0xca,0xa3,0x87,0x39,0xe2,0xf9,0xab,0xc0,0x4b,0x51,0x27,0x77,0x46,0xb1,0x68,0xf6,0x4d,
	0x90,0xb6,0x54,0x87,0x14,0x9b,0xdb,0x29,0xcf,0x37,0xb2,0x0a,0x31,0xae,0x3d,0x05,0x5c,
	0x94,0xdd,0xd5,0x12,0x1d,0x06,0x5e,0x03,0x6f,0x81,0x2f,0x19,0xb3,0xfc,0xa3,0x13,0x09,
	0xde,0xab,0x5b,0x49,0x68,0x48,0x4b,0xf4,0x11,0x70,0x1b,0xe8,0x4a,0x70,0x8c,0xc8,0x8a,
	0xe3,0xb1,0x66,0xea,0x96,0xdd,0x00,0xb6,0x54,0x3e,0x5e,0xe8,0x73,0x4e,0x99,0xd7,0x4b,
	0x30,0x57,0xa7,0x81,0xab,0x32,0x8b,0xcb,0x29,0x25,0x9e,0xe7,0xc0,0x32,0x50,0x4f,0x63,
	0xd0,0x2c,0xc0,0x5c,0x59,0x5c,0x5e,0x96,0x3d,0x50,0x29,0x79,0xa9,0x04,0xf4,0x0a,0xf8,
	0x9c,0xd4,0x40,0x59,0x83,0x85,0xc7,0x3e,0x2f,0x33,0x7d,0x04,0xe6,0xe5,0x49,0x2b,0x27,
	0xeb,0x71,0x4a,0x49,0x3b,0xc1,0xc2,0x3a,0x2b,0xbb,0x06,0xec,0x03,0x63,0xf2,0xe6,0x1b,
	0x2d,0xdd,0x96,0x94,0x27,0x30,0x57,0x27,0x9d,0xb8,0xfc,0x01,0x4c,0xab,0x84,0x98,0x37,
	0x97,0x80,0xdd,0xa3,0x6e,0x90,0x57,0x30,0x57,0x45,0xa0,0x4f,0x76,0xcf,0xe9,0x63,0xdf,
	0xa9,0xcd,0xfb,0x6f,0x5c,0xfa,0x00,0xe6,0xaa,0xa8,0x27,0x90,0x5e,0x1d,0xab,0xc9,0x83,
	0x55,0x79,0x75,0x01,0xd8,0xc1,0x43,0xb0,0xb0,0x82,0xe4,0x73,0x53,0xc7,0x0d,0xec,0x3e,
	0x50,0x4e,0xb2,0xf3,0xc8,0x83,0x2e,0x00,0x4f,0x80,0x73,0xbe,0x7b,0x2c,0xac,0x06,0x30,
	0x68,0x45,0xdf,0x77,0xb0,0x86,0x8a,0xfc,0xac,0x12,0xc9,0xa2,0xba,0x19,0x2f,0x63,0xcc,
	0xb2,0x60,0x59,0x09,0x63,0x58,0x59,0xf2,0x7b,0xf8,0x24,0x5f,0xc0,0x16,0x94,0xde,0x47,
	0xd4,0x44,0xaf,0x1c,0x75,0x41,0x9e,0xc1,0x26,0xd5,0x5a,0x4d,0x69,0x99,0x7d,0x6d,0xe5,
	0xe2,0x3c,0x81,0xed,0xc9,0x33,0xcf,0xb4,0xd4,0x96,0xd4,0x5a,0x1d,0x4b,0xed,0x06,0x6b,
	0x68,0x83,0x68,0x46,0xf1,0xb2,0x98,0xd4,0x8d,0xb3,0x06,0x3b,0xd4,0xde,0x48,0x55,0x9e,
	0x31,0xaf,0x7c,0x48,0x63,0xa0,0x2c,0xc0,0xf6,0x05,0x50,0x56,0xa7,0x5e,0x89,0xd2,0xc4,
	0xc6,0x55,0x5a,0x60,0x75,0x79,0x66,0x54,0x0f,0x90,0xb5,0x56,0x83,0x3f,0xae,0x92,0x04,
	0xdb,0x56,0x9c,0x4c,0x28,0x6e,0x52,0x59,0x62,0x51,0x15,0x17,0x6c,0x55,0xf5,0xe5,0xb1,
	0xd2,0xf2,0xa7,0xec,0xa6,0xde,0x5c,0x01,0x58,0xd4,0x66,0xf8,0x40,0x99,0x6b,0x4c,0x20,
	0x23,0x59,0x2f,0xb1,0xa8,0x2a,0x68,0x1f,0xbe,0xd8,0xe4,0xfc,0x2d,0x55,0xfb,0x71,0xc5,
	0x4c,0xcd,0x87,0x37,0x31,0x81,0xc7,0xec,0x9f,0xbf,0xe4,0x1c,0xaf,0x0b,0xa2,0xa2,0x4c,
	0x66,0x89,0xe0,0x57,0x9b,0xe6,0x78,0x2c,0x05,0x60,0x03,0x7a,0x55,0x64,0x0f,0x6d,0x96,
	0x9a,0x6d,0x7f,0xc1,0x76,0x8d,0xfc,0x14,0xf0,0x07,0xbf,0xd0,0x9e,0x45,0xab,0x88,0x4e,
	0x94,0x00,0x00,0x00,0x00,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82
};
