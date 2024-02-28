#include "stdlib.h"
#include "string.h"
#include "prosystem.h"
#include "joystick.h"

#define MODE_320AC

const char nightfall_tiles_0_0[1] = {0};
const char nightfall_tiles_0_1[2] = {0, 0};
const char nightfall_tiles_0_2[3] = {0, 0, 0};
const char nightfall_tiles_0_data[] = {0, 0, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 21, 20, nightfall_tiles_0_1, 0x60, nightfall_tiles_0_1 >> 8, (4 << 5) | ((-2) & 0x1f), 15, 42, 40, nightfall_tiles_0_2, 0x60, nightfall_tiles_0_2 >> 8, (4 << 5) | ((-3) & 0x1f), 20, 96, 0xff};
const char nightfall_tiles_1_data[] = {96, 0xff};
const char nightfall_tiles_14_0[4] = {0, 0, 0, 0};
const char nightfall_tiles_14_1[4] = {24, 28, 28, 28};
const char nightfall_tiles_14_data[] = {3, 0, nightfall_tiles_14_0, 0x60, nightfall_tiles_14_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 31, 28, nightfall_tiles_14_1, 0x60, nightfall_tiles_14_1 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_15_0[4] = {24, 28, 24, 28};
const char nightfall_tiles_15_data[] = {31, 28, nightfall_tiles_15_0, 0x60, nightfall_tiles_15_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_17_0[4] = {24, 28, 28, 24};
const char nightfall_tiles_17_data[] = {31, 28, nightfall_tiles_17_0, 0x60, nightfall_tiles_17_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_18_0[4] = {24, 24, 28, 24};
const char nightfall_tiles_18_data[] = {31, 28, nightfall_tiles_18_0, 0x60, nightfall_tiles_18_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_19_0[4] = {24, 28, 24, 24};
const char nightfall_tiles_19_data[] = {31, 28, nightfall_tiles_19_0, 0x60, nightfall_tiles_19_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_20_0[4] = {24, 24, 24, 24};
const char nightfall_tiles_20_data[] = {31, 28, nightfall_tiles_20_0, 0x60, nightfall_tiles_20_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_23_0[4] = {28, 28, 24, 24};
const char nightfall_tiles_23_data[] = {31, 28, nightfall_tiles_23_0, 0x60, nightfall_tiles_23_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_25_0[4] = {28, 28, 28, 28};
const char nightfall_tiles_25_data[] = {31, 28, nightfall_tiles_25_0, 0x60, nightfall_tiles_25_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_27_0[4] = {28, 24, 28, 24};
const char nightfall_tiles_27_data[] = {31, 28, nightfall_tiles_27_0, 0x60, nightfall_tiles_27_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 96, 0xff};
const char nightfall_tiles_28_0[31] = {28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 24, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28};
const char nightfall_tiles_28_1[5] = {28, 28, 28, 28, 28};
const char nightfall_tiles_28_data[] = {42, 12, nightfall_tiles_28_0, 0x60, nightfall_tiles_28_0 >> 8, (4 << 5) | ((-31) & 0x1f), 146, 47, 43, nightfall_tiles_28_1, 0x60, nightfall_tiles_28_1 >> 8, (4 << 5) | ((-5) & 0x1f), 29, 96, 0xff};
const char nightfall_tiles_29_0[1] = {14};
const char nightfall_tiles_29_1[1] = {2};
const char nightfall_tiles_29_data[] = {14, 14, nightfall_tiles_29_0, 0x60, nightfall_tiles_29_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 31, 28, nightfall_tiles_25_0, 0x60, nightfall_tiles_25_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 37, 37, nightfall_tiles_29_1, 0x60, nightfall_tiles_29_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_34_0[4] = {28, 24, 24, 28};
const char nightfall_tiles_34_data[] = {14, 14, nightfall_tiles_29_0, 0x60, nightfall_tiles_29_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 31, 28, nightfall_tiles_34_0, 0x60, nightfall_tiles_34_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 37, 37, nightfall_tiles_29_1, 0x60, nightfall_tiles_29_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_35_0[3] = {8, 10, 12};
const char nightfall_tiles_35_data[] = {14, 14, nightfall_tiles_29_0, 0x60, nightfall_tiles_29_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 25, 23, nightfall_tiles_35_0, 0x60, nightfall_tiles_35_0 >> 8, (4 << 5) | ((-3) & 0x1f), 20, 31, 28, nightfall_tiles_25_0, 0x60, nightfall_tiles_25_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 37, 37, nightfall_tiles_29_1, 0x60, nightfall_tiles_29_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_36_0[4] = {28, 24, 28, 28};
const char nightfall_tiles_36_data[] = {14, 14, nightfall_tiles_29_0, 0x60, nightfall_tiles_29_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 31, 28, nightfall_tiles_36_0, 0x60, nightfall_tiles_36_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 37, 37, nightfall_tiles_29_1, 0x60, nightfall_tiles_29_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_37_data[] = {14, 14, nightfall_tiles_29_0, 0x60, nightfall_tiles_29_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 23, 21, nightfall_tiles_35_0, 0x60, nightfall_tiles_35_0 >> 8, (4 << 5) | ((-3) & 0x1f), 20, 31, 28, nightfall_tiles_17_0, 0x60, nightfall_tiles_17_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 37, 37, nightfall_tiles_29_1, 0x60, nightfall_tiles_29_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_39_data[] = {14, 14, nightfall_tiles_29_0, 0x60, nightfall_tiles_29_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 26, 24, nightfall_tiles_35_0, 0x60, nightfall_tiles_35_0 >> 8, (4 << 5) | ((-3) & 0x1f), 20, 31, 28, nightfall_tiles_27_0, 0x60, nightfall_tiles_27_0 >> 8, (4 << 5) | ((-4) & 0x1f), 24, 37, 37, nightfall_tiles_29_1, 0x60, nightfall_tiles_29_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_40_0[1] = {22};
const char nightfall_tiles_40_1[1] = {4};
const char nightfall_tiles_40_2[7] = {4, 26, 28, 28, 28, 28, 30};
const char nightfall_tiles_40_3[1] = {6};
const char nightfall_tiles_40_data[] = {12, 12, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 14, 14, nightfall_tiles_40_0, 0x60, nightfall_tiles_40_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 16, 16, nightfall_tiles_40_1, 0x60, nightfall_tiles_40_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 21, 21, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 32, 26, nightfall_tiles_40_2, 0x60, nightfall_tiles_40_2 >> 8, (4 << 5) | ((-7) & 0x1f), 38, 34, 34, nightfall_tiles_40_1, 0x60, nightfall_tiles_40_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 37, 37, nightfall_tiles_40_3, 0x60, nightfall_tiles_40_3 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 42, 42, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 46, 46, nightfall_tiles_40_1, 0x60, nightfall_tiles_40_1 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_41_0[31] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
const char nightfall_tiles_41_1[29] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
const char nightfall_tiles_41_data[] = {30, 0, nightfall_tiles_41_0, 0x60, nightfall_tiles_41_0 >> 8, (4 << 5) | ((-31) & 0x1f), 146, 59, 31, nightfall_tiles_41_1, 0x60, nightfall_tiles_41_1 >> 8, (4 << 5) | ((-29) & 0x1f), 137, 96, 0xff};

const char nightfall_tiles_data_ptrs_high[42] = {nightfall_tiles_0_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_14_data >> 8, nightfall_tiles_15_data >> 8, nightfall_tiles_15_data >> 8, nightfall_tiles_17_data >> 8, nightfall_tiles_18_data >> 8, nightfall_tiles_19_data >> 8, nightfall_tiles_20_data >> 8, nightfall_tiles_18_data >> 8, nightfall_tiles_17_data >> 8, nightfall_tiles_23_data >> 8, nightfall_tiles_20_data >> 8, nightfall_tiles_25_data >> 8, nightfall_tiles_17_data >> 8, nightfall_tiles_27_data >> 8, nightfall_tiles_28_data >> 8, nightfall_tiles_29_data >> 8, nightfall_tiles_29_data >> 8, nightfall_tiles_29_data >> 8, nightfall_tiles_29_data >> 8, nightfall_tiles_29_data >> 8, nightfall_tiles_34_data >> 8, nightfall_tiles_35_data >> 8, nightfall_tiles_36_data >> 8, nightfall_tiles_37_data >> 8, nightfall_tiles_29_data >> 8, nightfall_tiles_39_data >> 8, nightfall_tiles_40_data >> 8, nightfall_tiles_41_data >> 8};

const char nightfall_tiles_data_ptrs_low[42] = {nightfall_tiles_0_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_14_data & 0xff, nightfall_tiles_15_data & 0xff, nightfall_tiles_15_data & 0xff, nightfall_tiles_17_data & 0xff, nightfall_tiles_18_data & 0xff, nightfall_tiles_19_data & 0xff, nightfall_tiles_20_data & 0xff, nightfall_tiles_18_data & 0xff, nightfall_tiles_17_data & 0xff, nightfall_tiles_23_data & 0xff, nightfall_tiles_20_data & 0xff, nightfall_tiles_25_data & 0xff, nightfall_tiles_17_data & 0xff, nightfall_tiles_27_data & 0xff, nightfall_tiles_28_data & 0xff, nightfall_tiles_29_data & 0xff, nightfall_tiles_29_data & 0xff, nightfall_tiles_29_data & 0xff, nightfall_tiles_29_data & 0xff, nightfall_tiles_29_data & 0xff, nightfall_tiles_34_data & 0xff, nightfall_tiles_35_data & 0xff, nightfall_tiles_36_data & 0xff, nightfall_tiles_37_data & 0xff, nightfall_tiles_29_data & 0xff, nightfall_tiles_39_data & 0xff, nightfall_tiles_40_data & 0xff, nightfall_tiles_41_data & 0xff};

const char *nightfall_tiles_data_ptrs[2] = {nightfall_tiles_data_ptrs_high, nightfall_tiles_data_ptrs_low};

#define TILING_HEIGHT 42
#define TILING_WIDTH 60
#include "sparse_tiling.h"

reversed scattered(16,2) char sprite_kenney_mono_17[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x80, 0x3b, 0x80, 0x11, 0x00,
	0x04, 0x00, 0x11, 0x14, 0x3b, 0x88, 0x31, 0x94, 0x04, 0x08, 0x1f, 0x1c, 0x0e, 0x08, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_19[32] = {
	0x01, 0x80, 0x01, 0x80, 0x01, 0xa0, 0x01, 0xd0, 0x01, 0x78, 0x01, 0x38, 0x01, 0x80, 0x01, 0x80,
	0x01, 0xc0, 0x01, 0x60, 0x05, 0x80, 0x0b, 0x80, 0x1e, 0x80, 0x1c, 0x80, 0x01, 0x80, 0x01, 0x80
};
reversed scattered(16,2) char sprite_kenney_mono_38[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x40,
	0x02, 0x40, 0x01, 0x40, 0x01, 0x48, 0x09, 0x50, 0x05, 0x50, 0x25, 0x54, 0x15, 0x54, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_39[32] = {
	0x01, 0x80, 0x01, 0x80, 0x01, 0xa0, 0x01, 0xd0, 0x01, 0x78, 0x01, 0x38, 0x01, 0x80, 0x01, 0x80,
	0x03, 0x80, 0x06, 0x80, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_64[32] = {
	0xff, 0xff, 0x66, 0x66, 0x19, 0x99, 0x3f, 0xff, 0x0f, 0xff, 0x00, 0xff, 0x00, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_65[32] = {
	0xff, 0xff, 0x66, 0x66, 0x99, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_66[32] = {
	0xff, 0xff, 0x66, 0x66, 0x99, 0x98, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0x00, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_81[32] = {
	0x18, 0x18, 0x1b, 0xd8, 0x1b, 0xd8, 0x18, 0x18, 0x18, 0x18, 0x1b, 0xd8, 0x0b, 0xd0, 0x28, 0x14,
	0x28, 0x14, 0x0b, 0xd0, 0x1b, 0xd8, 0x18, 0x18, 0x18, 0x18, 0x1b, 0xd8, 0x1b, 0xd8, 0x18, 0x18
};
reversed scattered(16,2) char sprite_kenney_mono_84[32] = {
	0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0x7f, 0xff, 0x37, 0xe7, 0x03, 0xc3, 0x31, 0x8d, 0x34, 0x2c,
	0x01, 0x80, 0x09, 0x82, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_85[32] = {
	0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xe7, 0xc3, 0xc3, 0xb1, 0x8d, 0x34, 0x2c,
	0x81, 0x80, 0x09, 0x82, 0x00, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,2) char sprite_kenney_mono_88[32] = {
	0x19, 0x80, 0xff, 0xff, 0x00, 0x00, 0xe6, 0x7f, 0xff, 0xef, 0xff, 0xd7, 0xdf, 0xff, 0xaf, 0xfb,
	0xff, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
reversed scattered(16,2) char sprite_kenney_mono_121[32] = {
	0x18, 0x18, 0x1b, 0xd8, 0x0b, 0xd0, 0x28, 0x14, 0x28, 0x14, 0x0b, 0xd0, 0x1b, 0xd8, 0x18, 0x18,
	0x18, 0x18, 0x1b, 0xd8, 0x1b, 0xd8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x3c, 0x3c
};
reversed scattered(16,2) char sprite_kenney_mono_188[32] = {
	0x70, 0x16, 0x6a, 0x0e, 0x70, 0x16, 0x2a, 0x0e, 0x32, 0x16, 0x6a, 0x0e, 0x70, 0x16, 0x68, 0x0e,
	0x70, 0x16, 0x68, 0x0e, 0x70, 0x56, 0x68, 0x4c, 0x70, 0x54, 0x68, 0x0e, 0x70, 0x56, 0x68, 0x0e
};
reversed scattered(16,2) char sprite_kenney_mono_207[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x07, 0x00, 0x0f
};
reversed scattered(16,2) char sprite_kenney_mono_208[32] = {
	0xf0, 0x17, 0xea, 0x0f, 0xf0, 0x16, 0xea, 0x0e, 0x72, 0x17, 0x6a, 0x0f, 0xf0, 0x17, 0xe8, 0x0f,
	0xf0, 0x17, 0xe8, 0x0f, 0xf0, 0x17, 0xe8, 0x4f, 0xf0, 0x57, 0xe8, 0x0f, 0xf0, 0x57, 0xe8, 0x0f
};
reversed scattered(16,2) char sprite_kenney_mono_209[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xf0, 0x00
};

#include "nightfall_characters.c"

#define DAY_START_TIME 0
#define DUST_START_TIME 300 //~5 seconds
#define NIGHT_START_TIME (DUST_START_TIME + 600) //~10 seconds
#define DAWN_START_TIME (NIGHT_START_TIME + 300) //~5 seconds
#define DAY_END_TIME (DAWN_START_TIME + 600) //~10 seconds
#define BACKGROUND_FLIP 60 //~1 second
#define FRAME_FLIP 20

ramchip int clock_ticker;
ramchip int x, y;
ramchip char background;
ramchip char background_ticker;
ramchip char background_increment;
ramchip char is_day;

const char *character_idles[] = { boy_idle_01, boy_idle_02, boy_idle_03, boy_idle_04 };
const char *character_right_walks[] = { boy_walk_right_01, boy_walk_right_02, boy_walk_right_03, boy_walk_right_04, boy_walk_right_05 };
const char *character_left_walks[] = { boy_walk_left_01, boy_walk_left_02, boy_walk_left_03, boy_walk_left_04, boy_walk_left_05 };
char character_ticker;
char character_frame;
const char *character_anims[] = { character_idles, character_right_walks, character_left_walks };
char *character_gfx;
char character_state_index;
char *character_state;

void on_day_start()
{
	//Set background to day
	//Flip colors to day
	is_day = 1;
	background = 0x0f;
	*BACKGRND = background;
	*P4C2 = 0x00; // Black
    *P5C2 = 0x0f; // White
}

void on_night_start()
{	
	//Set background to night
	//Flip colors to night
	is_day = 0;
	background = 0x00;
	*BACKGRND = background;
	*P4C2 = 0x0f; // White
    *P5C2 = 0x00; // Black
}

void clock_step() {
	if (clock_ticker < DUST_START_TIME) {
		//Day
		if (clock_ticker == DAY_START_TIME)
			on_day_start();
	}
	else if (clock_ticker < NIGHT_START_TIME) {
		//Dusk
		if (clock_ticker == DUST_START_TIME) {
			//Start transition
			background_increment = -1;
			background_ticker = 0;
			background = 0x0f;
			*BACKGRND = background;
		}

		if (background != 0x00) {
			if (background_ticker == BACKGROUND_FLIP) {
				background = background + background_increment;
				*BACKGRND = background;

				background_ticker = -1;
			}

			background_ticker++;
		}
	}
	else if (clock_ticker < DAWN_START_TIME) {
		//Night
		if (clock_ticker == NIGHT_START_TIME) {
			on_night_start();
		}
	}
	else if (clock_ticker < DAY_END_TIME) {
		//Dawn
		if (clock_ticker == DAWN_START_TIME) {
			//Start transition
			background_increment = 1;
			background_ticker = 0;
			background = 0x00;
			*BACKGRND = background;
		}

		if (background != 0x0f) {
			if (background_ticker == BACKGROUND_FLIP) {
				background = background + background_increment;
				*BACKGRND = background;

				background_ticker = -1;
			}

			background_ticker++;
		}
	}
	else if (clock_ticker == DAY_END_TIME) {
		//Reset back to day
		clock_ticker = -1;
	}

	clock_ticker++;
}

void character_update() {
	if (character_ticker == FRAME_FLIP) {
		character_frame++;

		if (character_frame > 4)
			character_frame = 0;

		character_ticker = 0;

		// character_gfx = character_state[character_frame];
		character_gfx = character_left_walks[character_frame];
	}

	//x, y, gfx, width, palette, height, mode
	multisprite_display_big_sprite(380, 400, character_gfx, 8, 4, 4, 1);

	character_ticker++;
}

void main() {
    //x = 320; y = 448;
    //x = 160; y = 448;
    x = 160; y = 448;
	
	clock_ticker = 0;
	character_ticker = 0;
	character_frame = 0;
	character_state_index = 0;
	character_state = character_anims[character_state_index];
	character_gfx = character_state[character_frame];

    multisprite_init();
    multisprite_set_charbase(sprite_kenney_mono_17);
    sparse_tiling_init(nightfall_tiles_data_ptrs);
    joystick_init();
    
    sparse_tiling_goto(x, y);

    *P0C2 = multisprite_color(0xbc); // Light turquoie
    *P1C2 = multisprite_color(0x33); // Red
    *P2C2 = multisprite_color(0xa5); // Dark turquoise
    *P3C2 = multisprite_color(0x83); // Blue
    *P4C2 = 0x0f; // White
    *P5C2 = 0x00; // Black
    *P6C2 = multisprite_color(0x29); // Orange 
    *P7C2 = multisprite_color(0x3c); // Rose 

    // Main loop
    do {
		clock_step();

        multisprite_flip();

        joystick_update();

        if (joystick[0] & JOYSTICK_LEFT) x--; 
        else if (joystick[0] & JOYSTICK_RIGHT) x++;
        if (joystick[0] & JOYSTICK_UP) y--; 
        else if (joystick[0] & JOYSTICK_DOWN) y++;
        sparse_tiling_goto(x, y);

		//Character
		character_update();
    } while(1);
}