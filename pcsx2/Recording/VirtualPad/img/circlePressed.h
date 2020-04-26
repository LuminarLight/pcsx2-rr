#pragma once

#include "Pcsx2Types.h"
#include <wx/gdicmn.h>

class res_circlePressed
{
public:
	static const uint Length = 3232;
	static const u8 Data[Length];
	static wxBitmapType GetFormat() { return wxBITMAP_TYPE_PNG; }
};

const u8 res_circlePressed::Data[Length] =
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,0x00,
	0x00,0x00,0x5f,0x00,0x00,0x00,0x5f,0x08,0x06,0x00,0x00,0x00,0x8e,0x4c,0x1b,0xf5,0x00,
	0x00,0x0c,0x67,0x49,0x44,0x41,0x54,0x78,0x9c,0xed,0x5d,0x79,0xac,0x54,0x57,0x19,0xff,
	0xbd,0x79,0xef,0xcd,0xbc,0xe1,0x6d,0x15,0x0a,0xf8,0x90,0xb5,0xb6,0xa8,0x34,0x55,0x82,
	0x61,0x11,0x52,0x6b,0xb5,0x04,0xa9,0xb6,0xd1,0x6a,0x9b,0x68,0x0c,0xd1,0x68,0x7d,0x71,
	0xaf,0x7f,0xa8,0x69,0xd4,0x7a,0x5c,0xe2,0xd2,0xc4,0x18,0x97,0xb4,0x46,0xeb,0xda,0x58,
	0xe3,0xd2,0x34,0xc1,0x5a,0xa1,0x48,0xd5,0x62,0x95,0x82,0xb6,0x54,0x5a,0x62,0x80,0x42,
	0x69,0x81,0x57,0x4a,0xa0,0xbc,0xfd,0xcd,0x5b,0x66,0xcc,0xef,0xe6,0xbb,0x38,0x0c,0x73,
	0xcf,0x36,0x77,0xe6,0xdd,0x19,0xfa,0x4b,0x6e,0x78,0xcc,0xcc,0xd9,0xbe,0x7b,0x96,0xdf,
	0xf9,0xce,0xf7,0x7d,0xa7,0xa9,0x50,0x28,0xc0,0x17,0x4a,0x29,0xef,0xb4,0x96,0x98,0x0b,
	0x60,0x31,0x80,0x79,0x00,0x5e,0x0e,0xe0,0x62,0x00,0x17,0x01,0xe8,0x00,0x90,0x05,0xd0,
	0x0c,0x60,0x02,0xc0,0x28,0x80,0x41,0x00,0xa7,0x01,0x9c,0x04,0xf0,0x3c,0x80,0x63,0x00,
	0x0e,0x01,0x18,0xa8,0x76,0x25,0x7d,0xd1,0x92,0xa0,0xba,0x50,0x98,0x97,0x00,0x78,0x03,
	0x80,0x2b,0xe4,0x79,0x0d,0x80,0x2e,0x00,0x33,0x1c,0xf3,0xca,0x03,0x18,0x06,0x70,0x0a,
	0xc0,0x93,0xf2,0x3c,0x0e,0x60,0x27,0x80,0xa3,0xf2,0xfd,0xb4,0x63,0xba,0x85,0xdf,0x0e,
	0xe0,0xf5,0x00,0xae,0x03,0xb0,0x46,0xfe,0xce,0xc6,0x90,0x6f,0x0a,0x40,0xa7,0x3c,0x1c,
	0x39,0x6f,0x97,0xcf,0x39,0x2a,0x76,0x01,0xd8,0x01,0x60,0x1b,0x80,0xc7,0x62,0x28,0xcb,
	0x1b,0xd3,0x25,0xfc,0xe5,0x00,0xae,0x07,0xf0,0x4e,0xf9,0xbb,0x56,0x98,0x0d,0xe0,0x6d,
	0xf2,0xdc,0x06,0xe0,0x51,0x00,0xbf,0x03,0xf0,0x47,0x00,0xcf,0xd6,0x5a,0x08,0xb5,0x16,
	0xfe,0x7a,0x00,0x9b,0x44,0xf0,0x5d,0x35,0x2e,0xbb,0x14,0x9c,0xca,0xae,0x96,0xe7,0x38,
	0x80,0x5f,0x01,0xb8,0x1b,0xc0,0xde,0x5a,0x55,0x20,0x55,0xa3,0x72,0xae,0x01,0x70,0x2f,
	0x80,0x2d,0x00,0xde,0x97,0x00,0xc1,0x97,0x82,0x0b,0xfa,0x67,0x00,0xfc,0x15,0xc0,0x0f,
	0x01,0x2c,0xab,0x45,0xa1,0xd5,0x16,0x3e,0xe7,0xf0,0x7b,0x00,0x6c,0x05,0x70,0x43,0x0d,
	0x5f,0xb6,0x2f,0x66,0x02,0xe8,0x95,0x35,0xe1,0xeb,0x00,0x16,0x56,0xb3,0xb0,0x6a,0x09,
	0x83,0x0b,0x1d,0x79,0xe8,0x83,0x00,0xde,0x53,0x07,0x42,0x2f,0x05,0x5f,0xc2,0xad,0x52,
	0xff,0x4d,0xd5,0x2a,0xa4,0x1a,0x42,0x59,0x23,0x0b,0xd8,0x97,0xa4,0x11,0xf5,0x8c,0x57,
	0x01,0xf8,0x85,0x8c,0xde,0x45,0x71,0xb7,0x23,0x4e,0xe1,0xa7,0x01,0x7c,0x0e,0xc0,0x9f,
	0x01,0x5c,0x19,0x63,0xbe,0x49,0x00,0x47,0xef,0xc3,0xc2,0xce,0x62,0x43,0x5c,0xc2,0x7f,
	0x19,0x80,0x9f,0x01,0xf8,0xa6,0x70,0xf7,0x46,0xc4,0x42,0xa1,0xa5,0xb7,0x25,0x49,0xf8,
	0x4b,0x65,0x9a,0x79,0x6f,0x0c,0x79,0x25,0x1d,0x54,0x67,0x7c,0x59,0x68,0x69,0x67,0xa5,
	0x75,0x75,0xe7,0xf9,0xbd,0xbd,0xff,0xff,0xbb,0xa7,0x67,0x9d,0xcc,0x87,0xb1,0xb3,0x82,
	0xb6,0x7c,0x1e,0x73,0x27,0x27,0x31,0x7b,0x72,0x12,0xb3,0x26,0x27,0x71,0xd1,0xd4,0x14,
	0xba,0xa6,0xa6,0xd0,0x91,0xcf,0x07,0xdf,0xb5,0x8a,0x4e,0x6a,0xa2,0xa9,0x09,0x63,0xa9,
	0x14,0x86,0x52,0x29,0x0c,0x34,0x37,0xe3,0x4c,0x73,0x33,0x4e,0xb5,0xb4,0xe0,0x64,0x4b,
	0x0b,0x4e,0xb4,0xb4,0x04,0xdf,0x55,0x01,0xec,0x68,0xb3,0x00,0x7c,0x58,0xf5,0xf5,0x05,
	0x9b,0x33,0xd5,0xd3,0xe3,0x5c,0x8a,0xf7,0x26,0x4b,0xf5,0xf4,0x5c,0x23,0x8b,0xd1,0xbc,
	0xb8,0xda,0x36,0x67,0x72,0x12,0x8b,0xc6,0xc7,0xb1,0x60,0x7c,0x1c,0xf3,0x27,0x26,0x30,
	0x73,0x72,0xd2,0x98,0x26,0x53,0x28,0x20,0x33,0x35,0x85,0xee,0xa9,0x29,0xbc,0x62,0x62,
	0xe2,0x9c,0xef,0x4e,0xb7,0xb4,0xe0,0x68,0x6b,0x2b,0x9e,0x4b,0xa7,0x71,0x24,0x9d,0xc6,
	0x0b,0x2d,0xb1,0xee,0x29,0x37,0xb0,0xfd,0xaa,0xa7,0xe7,0x66,0xd5,0xd7,0x77,0xd0,0x27,
	0x03,0x77,0xad,0x66,0x6f,0x6f,0x28,0x78,0xce,0xf1,0xf3,0x7d,0x0a,0x2d,0x06,0x85,0xb7,
	0x74,0x6c,0x0c,0x97,0xe6,0x72,0x78,0x65,0x2e,0x17,0xf4,0xec,0x6a,0x80,0x23,0xe3,0xe9,
	0x4c,0x06,0x07,0x33,0x19,0xec,0x6f,0x6b,0x43,0xae,0xa9,0x29,0xae,0x52,0xa8,0x2b,0xba,
	0xd1,0x47,0x3d,0xe1,0x2c,0x7c,0xa5,0x14,0xb5,0x8e,0xf7,0x89,0xba,0xd7,0x1b,0xed,0xf9,
	0x3c,0x96,0x8d,0x8d,0x61,0xd9,0xe8,0x28,0x96,0x8c,0x8f,0x57,0x92,0x95,0x33,0x0e,0xa7,
	0xd3,0xd8,0x97,0xcd,0x62,0x5f,0x5b,0x1b,0x86,0xe3,0x99,0x96,0x76,0xc8,0x0b,0x38,0xe1,
	0x92,0xc8,0x49,0xf8,0x4a,0xa9,0x25,0xb2,0x5b,0xbd,0xcc,0xa7,0x86,0x90,0x15,0xfe,0xb5,
	0xa3,0xa3,0xc1,0x73,0x49,0x2e,0xe7,0x9b,0x4d,0x2c,0x38,0x94,0xc9,0xe0,0x3f,0xd9,0x6c,
	0xf0,0xc4,0x30,0xde,0xd8,0x21,0x6f,0x02,0x60,0x9e,0x2b,0x05,0xd6,0xc2,0x57,0x4a,0x71,
	0xc3,0x74,0xbf,0xe8,0xdb,0xbd,0xb0,0x70,0x7c,0x1c,0x2b,0x46,0x46,0xb0,0x7c,0x94,0x67,
	0x1f,0xc9,0xc1,0x9e,0x6c,0x16,0x8f,0xcd,0x98,0x81,0x67,0xd3,0xe9,0x4a,0xeb,0xf4,0x23,
	0x51,0x4f,0x58,0xc1,0x4a,0xf8,0x4a,0x29,0xae,0x54,0xbf,0x94,0xcd,0x86,0x33,0x38,0xbb,
	0xae,0x1c,0x19,0xc1,0xca,0xe1,0xe1,0x80,0xbd,0x24,0x11,0x64,0x47,0xbb,0xdb,0xdb,0xb1,
	0x7b,0xc6,0x0c,0xf8,0x9f,0xed,0x05,0xf8,0x14,0x80,0xef,0xd9,0xfc,0xd0,0x76,0xf9,0xef,
	0xf5,0x15,0x3c,0x29,0xe2,0x9a,0xe1,0xe1,0xe0,0xf1,0x05,0xe9,0xe2,0x09,0xa1,0x8f,0xa4,
	0x91,0xa4,0x93,0xa4,0x95,0x04,0xe9,0x27,0xcb,0x98,0x25,0xb4,0x94,0xf4,0xb4,0xcd,0x63,
	0xd1,0x66,0xda,0x6b,0xfb,0xfb,0x03,0x86,0xb5,0xb3,0xbd,0x3d,0x28,0xc3,0x13,0x5f,0x95,
	0x13,0xb3,0x5d,0xa6,0xe4,0xc6,0x9e,0xaf,0x94,0xe2,0x61,0xc7,0x43,0xb2,0x8b,0x75,0xc2,
	0xbc,0x89,0x09,0xac,0x1b,0x1a,0xc2,0xe5,0x63,0x63,0xce,0xcd,0x20,0x2d,0x24,0x3d,0x24,
	0x4d,0x24,0x5d,0x3c,0x6d,0x49,0x13,0x29,0x3c,0xd2,0x54,0xd2,0x55,0xd2,0xd6,0x39,0x1e,
	0x23,0xed,0xa9,0xb6,0x36,0x3c,0xd2,0xd1,0x81,0xe3,0xad,0xad,0xce,0x69,0x05,0xbb,0x85,
	0x8a,0xbe,0xa8,0xfb,0x91,0x56,0xf8,0x4a,0x29,0x1e,0x54,0x6f,0x96,0x03,0x07,0x27,0xb0,
	0xe1,0x6f,0x1c,0x1a,0x0a,0xe8,0xa3,0x2d,0x48,0xff,0x48,0x03,0x49,0x07,0x49,0x0b,0x87,
	0x2a,0x64,0x22,0xa4,0xad,0x2c,0x9f,0x34,0x96,0x74,0x36,0xe3,0x40,0x2e,0x58,0xfe,0xc3,
	0x1d,0x1d,0x41,0x07,0xf0,0xc4,0x77,0x01,0xdc,0xa2,0x4b,0x6a,0xea,0x4e,0xbd,0xbe,0x82,
	0xbf,0x7a,0x70,0x10,0x8b,0x2d,0x29,0x24,0xe9,0x1e,0x69,0x1f,0xe9,0xdf,0xe1,0xca,0x17,
	0xbd,0xb3,0xe0,0xcb,0x7b,0x22,0x9b,0x0d,0x1e,0xd2,0x59,0xd2,0x5a,0xd2,0xdb,0x76,0x8b,
	0x69,0x89,0x2f,0xad,0xb9,0x50,0xc0,0x5f,0x3a,0x3b,0x7d,0x5f,0xc0,0x47,0x44,0x17,0xf4,
	0x48,0xd4,0x0f,0x22,0x7b,0xbe,0x52,0x8a,0x2a,0xd4,0x7f,0xcb,0x36,0xda,0x1a,0x9c,0x6a,
	0xde,0x32,0x38,0x68,0xd5,0xe3,0x29,0x82,0x90,0xea,0x91,0xf6,0xd5,0x02,0xa4,0xb7,0x21,
	0xd5,0xb5,0x19,0x57,0x1c,0x01,0xdb,0x3b,0x3b,0x7d,0xa7,0xa0,0xbf,0x01,0x78,0x53,0xd4,
	0x97,0xba,0x9e,0xff,0x45,0x57,0xc1,0x73,0xe1,0x5b,0x67,0x39,0xd5,0x90,0xd6,0x91,0xde,
	0x91,0xe6,0xd5,0x12,0x7c,0xc9,0x7c,0x9e,0xc9,0x64,0x02,0xda,0xbb,0xd0,0x30,0x3a,0xd9,
	0x96,0xb1,0xa6,0x26,0x6c,0xeb,0xea,0xf2,0x59,0x84,0xaf,0x02,0xf0,0x01,0xd1,0x06,0x9c,
	0x87,0xb2,0x3d,0x5f,0x29,0xb5,0x02,0xc0,0x3f,0xb8,0xfb,0xb7,0x2d,0x85,0x74,0x72,0xc3,
	0xc0,0x80,0x91,0xd5,0xb0,0x34,0xd2,0x39,0xd2,0xba,0x93,0xf1,0xea,0x5a,0x9c,0x41,0x86,
	0x43,0xfa,0x4b,0x1a,0x6c,0x52,0x36,0x90,0x01,0x6d,0xed,0xea,0xf2,0xa1,0xa1,0x7b,0xe5,
	0x25,0x9c,0xb7,0xf8,0x46,0x8d,0xbc,0x4f,0xba,0x08,0x1e,0xc2,0xe3,0x4d,0x82,0x67,0xcf,
	0x61,0x03,0x1e,0xe8,0xee,0x9e,0x76,0xc1,0x43,0xb8,0x3d,0xeb,0xb2,0xd5,0xa2,0x57,0xaf,
	0x91,0x97,0xe4,0x81,0x2b,0xa2,0xd4,0xed,0xe7,0x09,0x5f,0x29,0xb5,0x0a,0xc0,0xbb,0x5d,
	0xca,0xe0,0xd0,0x5d,0x69,0x21,0x78,0x0e,0x5d,0xf6,0xa0,0xa4,0x81,0x75,0xb2,0x99,0x56,
	0xd8,0x46,0xd3,0x34,0x15,0x81,0x8f,0x96,0xb3,0xd8,0x28,0xd7,0xf3,0x37,0xb9,0x9c,0x46,
	0x31,0x03,0xce,0x9d,0xba,0x9d,0x6b,0x41,0x1a,0x48,0xfe,0x9c,0x54,0xb0,0x6e,0xac,0xa3,
	0x6e,0x5a,0x61,0x1b,0xd9,0x56,0x0f,0x02,0x4c,0x53,0x94,0x8d,0xe5,0x64,0x77,0x16,0x4a,
	0xa9,0xf9,0xae,0x27,0x52,0x64,0x0d,0x26,0x5d,0x0d,0xe7,0xf8,0x24,0xf6,0xf8,0x52,0xec,
	0x14,0xf5,0x82,0x0e,0xcb,0x85,0x29,0x79,0xe0,0x3c,0x9d,0x4f,0xe9,0x4b,0xbc,0xde,0x65,
	0x27,0x4b,0xbe,0x6c,0xaa,0x08,0x59,0xcd,0xee,0x3a,0x10,0x7c,0x08,0xd6,0xd5,0xa4,0x60,
	0x63,0x9b,0x6d,0xf6,0x0a,0x25,0x58,0xcb,0x99,0xab,0xf8,0xa3,0x52,0xe1,0xdf,0xe8,0x92,
	0x1b,0x37,0x2c,0x3a,0xb5,0x30,0xab,0x47,0x3a,0x99,0x84,0xc5,0xd5,0x16,0xac,0x2b,0xeb,
	0xac,0x13,0x2d,0xdb,0xbc,0xcc,0x5d,0x65,0x42,0x02,0xf3,0x8e,0xe2,0x0f,0xce,0x0a,0x5f,
	0x29,0x75,0x79,0xe9,0x9b,0xd1,0xe6,0x54,0x28,0x04,0x3b,0x46,0x1d,0xb8,0x79,0xaa,0x35,
	0x8f,0x8f,0x03,0x7b,0x64,0xe3,0xa7,0x03,0xdb,0xee,0xa2,0xae,0x10,0xd0,0x56,0xf5,0xec,
	0xc2,0x57,0xdc,0xf3,0x37,0xba,0x2c,0xb4,0xd4,0x95,0xe8,0x4e,0xa0,0xa8,0x32,0x30,0x35,
	0x20,0xc9,0x60,0xdd,0x75,0xa7,0x5c,0x6c,0xfb,0x52,0xf7,0xde,0x4f,0xf3,0xc9,0x75,0xe1,
	0x7f,0x8a,0x73,0x5f,0xeb,0x92,0xcb,0xa5,0x86,0x5d,0x2c,0x75,0x35,0xb5,0x52,0x19,0x54,
	0x03,0xac,0xfb,0x3e,0x03,0x3b,0x33,0xc9,0xa0,0x0c,0x52,0x62,0xd1,0x17,0x20,0x10,0xbe,
	0x52,0x6a,0x5e,0xf1,0x87,0x26,0x50,0x4d,0xab,0x53,0x21,0x50,0x3b,0xb9,0xaf,0x8e,0x7b,
	0x7d,0x08,0xb6,0x41,0x77,0xd0,0x4e,0x19,0x78,0xa8,0xac,0xaf,0x0a,0xff,0x08,0x7b,0xfe,
	0x6a,0x5a,0xe1,0xd8,0xa6,0xa6,0xd6,0x52,0x67,0x65,0x40,0xb5,0x70,0x9c,0xda,0xc9,0xe9,
	0x02,0xdb,0xb0,0x5f,0xd3,0xfb,0x29,0x83,0x45,0xee,0x9b,0xae,0xe5,0xa1,0xd5,0x47,0x28,
	0xfc,0x57,0xbb,0xa4,0x5e,0x60,0x28,0xf0,0x60,0x1d,0x4f,0x37,0xa5,0x30,0xb5,0xc5,0x24,
	0x8b,0x32,0x98,0x25,0x56,0x7e,0x67,0x85,0xff,0x3a,0xdb,0x94,0x3c,0xa2,0x9b,0x5f,0x62,
	0x9c,0x54,0x0c,0x9e,0x40,0x3d,0xdd,0x40,0xc2,0x67,0x5b,0x74,0xc6,0x56,0x94,0x85,0xe3,
	0xb1,0x65,0x2a,0x74,0xbe,0xa0,0x32,0xa3,0x55,0xd4,0xc7,0x73,0x6c,0x52,0xd2,0x2a,0x6c,
	0xad,0x46,0x8f,0xc3,0x45,0xea,0xa9,0x06,0x98,0xef,0x43,0x8c,0x37,0x35,0x05,0xf3,0x7a,
	0xa9,0x35,0x5c,0x88,0x6c,0x3e,0x8f,0x03,0x6d,0x6d,0xe8,0x77,0x53,0x37,0xd3,0x55,0x75,
	0x73,0x4a,0xe6,0xfa,0x8b,0x6d,0x53,0x99,0xac,0x0f,0x9e,0x6b,0x80,0xb9,0xbe,0x14,0xa6,
	0x36,0x79,0x58,0x64,0x2c,0x80,0x0c,0x01,0x0a,0xbf,0xdb,0x36,0xd5,0x2c,0x4d,0x41,0xb4,
	0x32,0x38,0xea,0x7f,0xe8,0x9c,0x58,0xb0,0x4d,0x3a,0x83,0x5b,0x9d,0x4c,0x22,0xc0,0x59,
	0xa6,0x3b,0x25,0xee,0x91,0xd6,0xf3,0x04,0x4f,0xab,0xa2,0x40,0xf3,0x0e,0x5b,0x2b,0x83,
	0x7a,0xc2,0x69,0xb1,0x78,0xf6,0x91,0x49,0x04,0x66,0x87,0xc2,0x77,0x32,0x09,0xe9,0xd2,
	0x14,0x54,0x4f,0x3a,0x1c,0x57,0xe8,0xda,0xa6,0x93,0x49,0x04,0x68,0xfd,0xd7,0x9e,0x72,
	0x99,0x72,0x20,0xdc,0x36,0x0a,0xa7,0x1a,0x58,0xf8,0xba,0xb6,0x79,0x58,0x56,0x73,0xf3,
	0x90,0x4d,0xb9,0xc6,0x35,0xd0,0xd1,0xaa,0x0a,0xac,0xbc,0x12,0x0f,0x5d,0xdb,0x7c,0x2c,
	0xe4,0x98,0x2c,0x55,0xac,0x65,0xb3,0x41,0xab,0x46,0x93,0x37,0xd0,0xc0,0xc2,0xd7,0xb5,
	0x4d,0x27,0x13,0x0d,0x5a,0x53,0x75,0xe8,0x23,0xdb,0x30,0xa0,0xe0,0x9d,0xf6,0xc7,0x13,
	0x1a,0x45,0x93,0xc7,0xc2,0x53,0x37,0xd0,0xb5,0x4d,0x27,0x13,0x0d,0xf2,0x14,0xbe,0x93,
	0x52,0x5a,0xc7,0x77,0x3d,0x28,0x57,0xdd,0x40,0xd7,0x36,0x4f,0xa7,0xbb,0x5c,0x4a,0x22,
	0x34,0x59,0x43,0x67,0xbc,0xea,0xb1,0xd9,0xa8,0x1b,0xe8,0xda,0xe6,0x61,0xd0,0x5b,0x08,
	0xde,0x19,0x17,0x72,0x97,0x54,0xba,0x85,0x27,0xa9,0x8e,0x0f,0x71,0x40,0xd7,0x36,0x0f,
	0xa2,0x71,0x26,0x38,0xec,0x93,0x50,0x58,0xd6,0xf3,0x85,0x8e,0x72,0xd1,0x31,0xc1,0xc6,
	0x7d,0xb3,0xde,0x30,0x53,0x9c,0x2e,0x7c,0x64,0x12,0x81,0x53,0xc1,0x80,0xa1,0x16,0xd8,
	0x25,0x08,0x9c,0x6e,0xb3,0x61,0x52,0x37,0xd7,0x2b,0x4c,0x6a,0x63,0x8f,0xcd,0x25,0x65,
	0x7e,0x26,0x25,0x01,0xdf,0xfa,0x6d,0x53,0x99,0x54,0x08,0x1e,0x87,0x0b,0x89,0x87,0xa9,
	0x4d,0x1e,0x6a,0x95,0xe7,0x83,0x05,0x57,0x29,0xc5,0xf9,0xe7,0x88,0x6d,0x2a,0x93,0xf2,
	0xcc,0x74,0xc4,0x58,0x6f,0x30,0x1d,0x15,0x9a,0x94,0x6e,0x11,0xf8,0x2f,0x8a,0x36,0x58,
	0x8f,0xdb,0xa6,0x32,0xa9,0x8d,0x4d,0x87,0xeb,0xf5,0x06,0xd3,0x21,0xb9,0x49,0xdd,0x1c,
	0x81,0x3d,0x28,0x12,0xfe,0x3e,0x97,0x94,0xa6,0xc3,0x05,0x0f,0x93,0x8a,0xc4,0xc2,0xd4,
	0x16,0x8f,0xc3,0x23,0x5a,0x9a,0x1d,0x40,0x91,0xf0,0xf7,0xb8,0x78,0x4e,0xd3,0x47,0x49,
	0xc7,0x6d,0x4d,0x06,0x55,0xf5,0x02,0x93,0x61,0x14,0x65,0xe0,0xe1,0xaf,0xc5,0x29,0x7e,
	0x3f,0x4a,0x84,0x6f,0x3d,0xf5,0x98,0x0e,0xc9,0x6d,0x4c,0x09,0xeb,0x01,0x26,0x93,0x40,
	0xd3,0xe1,0x7a,0x04,0x18,0xb1,0x2a,0xf0,0xb2,0x08,0x8d,0xa6,0x26,0xc4,0x71,0xd7,0x1a,
	0x26,0x93,0x0a,0x93,0x11,0x6d,0xd2,0x61,0x63,0x0c,0xeb,0x69,0x22,0xf3,0xcf,0xf0,0x8f,
	0xe2,0xb9,0x63,0xbb,0x4b,0x0e,0x26,0xc3,0x28,0x1b,0xf3,0xf1,0x24,0xc3,0x64,0x06,0x6e,
	0x32,0xa8,0x8a,0xc0,0x0b,0xe2,0xa1,0x18,0xa0,0x58,0xf8,0x0c,0xe8,0x79,0xd8,0x36,0x17,
	0x1b,0x93,0x40,0x1b,0xc7,0x89,0x24,0xc2,0xc6,0x01,0xc2,0x64,0x4a,0x18,0x81,0x73,0x64,
	0x5c,0x6c,0x22,0xde,0x2f,0x11,0x5f,0xad,0x61,0x32,0x86,0xb5,0x71,0x19,0x4a,0x1a,0x6c,
	0x5c,0x7f,0x6c,0x8c,0x68,0x23,0x70,0x7f,0xa9,0x7c,0x8a,0xf1,0x6b,0x97,0x9c,0x6c,0xcc,
	0xc0,0x6d,0x9c,0xe5,0x92,0x04,0x1b,0xa7,0x37,0x93,0xf9,0x78,0x04,0x8e,0x99,0x84,0xbf,
	0x4b,0xfc,0x6f,0xad,0x61,0xe3,0x00,0x61,0xe3,0x26,0x9a,0x04,0xd8,0xb8,0x7b,0xda,0x38,
	0x4e,0x44,0xe0,0x37,0xa5,0xbe,0xb8,0xa5,0x0e,0x71,0x39,0x09,0xd8,0x63,0x0d,0x1b,0xd7,
	0x9f,0x26,0x69,0x98,0x4f,0xf4,0x91,0x5a,0x81,0x75,0x63,0x1d,0x75,0xb3,0xb8,0x8d,0xcb,
	0x50,0x04,0xd8,0xf0,0x1f,0x97,0x7e,0x55,0x6e,0xec,0x6c,0x76,0x0d,0x63,0x6e,0xe3,0xf4,
	0xc6,0x93,0xa0,0xf5,0x16,0x1e,0xea,0xd3,0x01,0xd6,0x89,0x75,0x33,0x9d,0xc4,0xd9,0x38,
	0xcb,0x45,0xe0,0xf7,0xa1,0x3e,0xa7,0x18,0xe5,0x9c,0xa0,0x5f,0x74,0xed,0xfd,0xb0,0x74,
	0xf7,0x64,0xe3,0x18,0x22,0x80,0x41,0x85,0x92,0xb0,0x08,0x87,0x01,0x8e,0x36,0x58,0x08,
	0xde,0xc6,0x4d,0x34,0x02,0xec,0x6d,0x77,0x96,0xfb,0x2a,0x6a,0xd5,0xf8,0x09,0xfd,0x82,
	0x5d,0x4a,0xb0,0x75,0x74,0xe6,0xb0,0x5e,0x35,0x32,0x82,0xeb,0xfa,0xfb,0xa7,0x95,0x86,
	0xb2,0x6c,0xd6,0x61,0x95,0x45,0xdc,0x05,0x1b,0x07,0x69,0x0d,0xee,0x89,0x5a,0x47,0x75,
	0x21,0x5f,0x6e,0x92,0x45,0xc2,0x09,0x2f,0x85,0x7c,0x39,0x07,0x9c,0x45,0x18,0x4e,0xa1,
	0x6c,0xd0,0x53,0x9d,0x62,0xe2,0x3e,0x09,0xe3,0xb8,0xc1,0xa5,0x34,0x56,0x92,0x11,0x9a,
	0x18,0x28,0xc8,0x14,0xec,0x28,0x25,0x3d,0xf0,0xb2,0x5c,0xae,0x2a,0xc1,0x8e,0x8a,0xe1,
	0x1a,0xec,0x88,0x78,0x26,0x9d,0x0e,0xda,0x52,0x41,0xb8,0xaf,0xef,0x47,0x09,0x1e,0x16,
	0x61,0xbe,0x56,0xc8,0xc6,0x6b,0xb6,0x6b,0xa9,0x2f,0x85,0xf9,0x0a,0x02,0x45,0x5d,0x29,
	0x2a,0xe4,0xb2,0xb0,0x09,0x70,0xf7,0x59,0x00,0xdf,0xf2,0x29,0xfd,0x02,0x0e,0x70,0x97,
	0x17,0xbf,0xe6,0x07,0x75,0x3f,0xb2,0x69,0xd1,0xb7,0x25,0xce,0xda,0x5b,0x5d,0x6b,0xc0,
	0xca,0x33,0x94,0xca,0x60,0x73,0xb3,0x33,0xc5,0xa4,0xd0,0xf8,0x70,0xd3,0x53,0x8b,0xd0,
	0x8e,0x21,0xb8,0xb0,0x56,0x18,0xda,0x91,0xf8,0x9a,0x49,0xf0,0x70,0x08,0x6a,0xba,0x54,
	0x6e,0x84,0x58,0xe0,0x53,0x93,0x0b,0x2c,0xa8,0xe9,0x16,0xb9,0x61,0xc2,0x38,0xdc,0x5d,
	0xc2,0xf9,0xde,0x20,0xd7,0x2d,0x79,0xe3,0x02,0x08,0xe7,0x7b,0x4c,0x66,0x89,0x03,0x36,
	0x3f,0x76,0x0d,0x64,0xcd,0x38,0x91,0xdf,0xa9,0xa4,0x76,0x0d,0x1c,0xc8,0x7a,0x40,0x7a,
	0xfc,0x43,0xb6,0x09,0x7c,0x42,0xb8,0xdf,0x2e,0x17,0x7a,0x55,0x84,0x06,0x0b,0xe1,0xce,
	0xa1,0xfc,0x7e,0x00,0xbf,0x75,0x49,0xe4,0x7b,0x79,0x01,0x95,0x44,0x1f,0x72,0xac,0x60,
	0x59,0x34,0xc0,0xe5,0x05,0xc4,0xc7,0x00,0xdc,0xe1,0x9a,0xc8,0xd7,0x89,0xea,0xd3,0xf2,
	0x6f,0xc5,0x2f,0x80,0x42,0xd8,0x9b,0xcd,0x06,0x8f,0xcf,0xb5,0x1d,0x3a,0x54,0xf9,0xda,
	0x0e,0xc8,0x5d,0xbc,0xb7,0xaa,0xbe,0xbe,0x3b,0x6a,0x76,0x67,0x8a,0xea,0xeb,0x1b,0x52,
	0x3d,0x3d,0x1f,0xa7,0xec,0xe4,0xad,0xc7,0x02,0x0a,0x87,0x0f,0x19,0x47,0xc2,0x2f,0xac,
	0x81,0x4c,0x35,0xb7,0xa8,0xbe,0x3e,0x67,0x25,0x64,0x88,0x38,0x6e,0x82,0x26,0xa7,0xfd,
	0xbc,0x77,0x26,0xf5,0x09,0x6e,0x5a,0x6e,0x76,0x3d,0xf9,0x2b,0x45,0x1c,0xdd,0xe2,0x0b,
	0x52,0x91,0xa1,0xc6,0x90,0xab,0x11,0x87,0x25,0x10,0x60,0x45,0x82,0x47,0x8c,0xce,0x70,
	0x77,0x49,0xf0,0xb6,0x27,0x62,0xca,0x2f,0xa9,0xd8,0x2c,0xc1,0x8a,0xac,0xe9,0xa4,0x0e,
	0x71,0x4e,0x88,0xdb,0xe5,0x3a,0xed,0x9f,0xd6,0x83,0x14,0x1d,0x91,0x93,0x8b,0x36,0xdf,
	0x45,0xf3,0xcc,0xb8,0x32,0x8d,0x7b,0x35,0x62,0xc5,0x3e,0x28,0x91,0xb3,0x6b,0x7e,0xad,
	0x75,0x95,0xb0,0x43,0xf4,0x5a,0x5f,0x71,0xb1,0x67,0xb5,0x41,0xb5,0xa8,0xc0,0xcf,0x45,
	0x9d,0xfa,0x83,0xd0,0x2e,0xb1,0x0e,0x71,0x44,0x6e,0x39,0xdd,0x28,0xc6,0x4e,0xb1,0xa3,
	0x9a,0x0e,0xd0,0xec,0xf9,0x9f,0x90,0x5e,0x73,0x6f,0xdc,0xbd,0xa6,0x8a,0x18,0x10,0x15,
	0xca,0x9b,0x01,0xdc,0x2e,0xcc,0xa6,0x2a,0xa8,0x45,0xa4,0x8a,0x1d,0x45,0x43,0xb7,0x57,
	0x6e,0xde,0x4f,0x62,0x50,0x9e,0x13,0x62,0x65,0xc0,0x51,0xfb,0xaf,0x5a,0x14,0x58,0xcb,
	0x30,0x21,0x5b,0xe4,0x59,0x2d,0x97,0xd0,0x5f,0xcb,0x23,0xd5,0x1a,0x96,0x1f,0x05,0x9e,
	0x38,0xfd,0x41,0x0e,0xba,0xad,0xb4,0x91,0x71,0x61,0x3a,0x62,0xb4,0x3c,0x2a,0xcf,0x37,
	0xe4,0x05,0xac,0x97,0x21,0x6e,0x1d,0x6a,0xac,0x42,0x14,0x84,0xab,0x93,0x9d,0xfd,0x09,
	0xc0,0xb6,0xe9,0xda,0xa3,0x4c,0x67,0x80,0x9c,0xe3,0xb2,0x3f,0xb8,0x4b,0x42,0x1d,0xae,
	0x96,0x50,0xb7,0x2b,0xe5,0xbe,0x71,0xa7,0xfb,0x5a,0x2c,0xca,0x3a,0x04,0xe0,0xef,0xe2,
	0x87,0xb0,0xd3,0xf5,0x12,0xc9,0x6a,0x20,0x29,0xd1,0x89,0xf6,0xcb,0x73,0xb7,0x84,0x1c,
	0xe3,0x05,0x98,0x8b,0x25,0x00,0xe8,0x12,0xb9,0x73,0x77,0xae,0x8c,0x8e,0x6e,0xb9,0x85,
	0xb9,0xf8,0x9c,0x6f,0x5c,0xc2,0x18,0xd0,0x54,0xe3,0xa4,0x08,0xf6,0xa8,0x4c,0x23,0x4f,
	0xd2,0x10,0x41,0x84,0x9f,0x28,0x24,0x31,0x34,0x14,0x15,0x56,0x74,0xd0,0xe3,0xf3,0x80,
	0x7c,0x46,0x56,0x46,0x73,0x38,0xbe,0x18,0x1a,0xf8,0xf0,0xc8,0x89,0xc2,0xe7,0xe7,0x34,
	0x35,0x23,0x93,0xe2,0x0b,0xe0,0x66,0x88,0xd4,0x36,0xf9,0xf4,0x16,0xc0,0xff,0x00,0x59,
	0x6f,0x49,0xe4,0x16,0x75,0x77,0x6b,0x00,0x00,0x00,0x00,0x49,0x45,0x4e,0x44,0xae,0x42,
	0x60,0x82
};
