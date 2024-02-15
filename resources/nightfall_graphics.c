const char nightfall_tiles_0_0[1] = {0};
const char nightfall_tiles_0_1[1] = {2};
const char nightfall_tiles_0_2[1] = {4};
const char nightfall_tiles_0_3[1] = {6};
const char nightfall_tiles_0_data[] = {0, 0, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (0 << 5) | ((-1) & 0x1f), 11, 1, 1, nightfall_tiles_0_1, 0x60, nightfall_tiles_0_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 2, 2, nightfall_tiles_0_2, 0x60, nightfall_tiles_0_2 >> 8, (7 << 5) | ((-1) & 0x1f), 11, 3, 3, nightfall_tiles_0_3, 0x60, nightfall_tiles_0_3 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 16, 16, nightfall_tiles_0_3, 0x60, nightfall_tiles_0_3 >> 8, (4 << 5) | ((-1) & 0x1f), 11, 17, 17, nightfall_tiles_0_2, 0x60, nightfall_tiles_0_2 >> 8, (7 << 5) | ((-1) & 0x1f), 11, 18, 18, nightfall_tiles_0_1, 0x60, nightfall_tiles_0_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 19, 19, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (0 << 5) | ((-1) & 0x1f), 11, 96, 0xff};
const char nightfall_tiles_1_data[] = {96, 0xff};
const char nightfall_tiles_2_0[2] = {8, 10};
const char nightfall_tiles_2_1[2] = {12, 14};
const char nightfall_tiles_2_2[2] = {16, 18};
const char nightfall_tiles_2_data[] = {0, 0, nightfall_tiles_2_0, 0xe0, nightfall_tiles_2_0 >> 8, (0 << 5) | ((-2) & 0x1f), 15, 1, 1, nightfall_tiles_2_1, 0xe0, nightfall_tiles_2_1 >> 8, (4 << 5) | ((-2) & 0x1f), 15, 2, 2, nightfall_tiles_2_2, 0xe0, nightfall_tiles_2_2 >> 8, (0 << 5) | ((-2) & 0x1f), 15, 17, 17, nightfall_tiles_2_2, 0xe0, nightfall_tiles_2_2 >> 8, (0 << 5) | ((-2) & 0x1f), 15, 18, 18, nightfall_tiles_2_1, 0xe0, nightfall_tiles_2_1 >> 8, (4 << 5) | ((-2) & 0x1f), 15, 19, 19, nightfall_tiles_2_0, 0xe0, nightfall_tiles_2_0 >> 8, (0 << 5) | ((-2) & 0x1f), 15, 96, 0xff};
const char nightfall_tiles_13_data[] = {0, 0, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (0 << 5) | ((-1) & 0x1f), 11, 1, 1, nightfall_tiles_0_1, 0x60, nightfall_tiles_0_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 18, 18, nightfall_tiles_0_1, 0x60, nightfall_tiles_0_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 19, 19, nightfall_tiles_0_0, 0x60, nightfall_tiles_0_0 >> 8, (0 << 5) | ((-1) & 0x1f), 11, 96, 0xff};

const char nightfall_tiles_data_ptrs_high[14] = {nightfall_tiles_0_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_2_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_1_data >> 8, nightfall_tiles_13_data >> 8};

const char nightfall_tiles_data_ptrs_low[14] = {nightfall_tiles_0_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_2_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_1_data & 0xff, nightfall_tiles_13_data & 0xff};

const char *nightfall_tiles_data_ptrs[2] = {nightfall_tiles_data_ptrs_high, nightfall_tiles_data_ptrs_low};

/*
#define TILING_HEIGHT 14
#define TILING_WIDTH 20
#include "sparse_tiling.h"
*/

reversed scattered(16,2) char nightfall_001[32] = {
	0xaa, 0xae, 0x11, 0x55, 0xaa, 0xbb, 0x04, 0x55, 0xaa, 0xaa, 0x01, 0x55, 0xaa, 0xab, 0x00, 0x55,
	0x8a, 0xaa, 0x01, 0x15, 0x2a, 0xab, 0x00, 0x45, 0x8a, 0xaa, 0x01, 0x15, 0x2a, 0xaa, 0x00, 0x05
};
reversed scattered(16,2) char nightfall_002[32] = {
	0xef, 0xff, 0x55, 0x55, 0xbb, 0xbf, 0x55, 0x55, 0xef, 0xff, 0x55, 0x55, 0xbb, 0xbf, 0x55, 0x55,
	0xee, 0xff, 0x55, 0x55, 0xab, 0xbb, 0x55, 0x55, 0xae, 0xff, 0x55, 0x55, 0xaa, 0xbb, 0x55, 0x55
};
reversed scattered(16,2) char nightfall_003[32] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
reversed scattered(16,2) char nightfall_004[32] = {
	0xf0, 0x00, 0x98, 0x00, 0xac, 0x00, 0xd6, 0x00, 0x6b, 0x00, 0x35, 0x80, 0x1a, 0xc8, 0x0d, 0x68,
	0x06, 0x98, 0x03, 0x38, 0x01, 0x70, 0x00, 0xe0, 0x03, 0xc8, 0x00, 0x04, 0x00, 0x03, 0x00, 0x03
};
reversed scattered(16,4) char nightfall_005[64] = {
	0x00, 0x60, 0x31, 0x00, 0x10, 0xe0, 0xf5, 0x00, 0x70, 0xd1, 0xe5, 0x32, 0xf0, 0x31, 0x84, 0xfa,
	0xc0, 0xf5, 0x12, 0xea, 0x11, 0xe5, 0x32, 0x88, 0x75, 0x84, 0xfa, 0x00, 0xf5, 0x12, 0xea, 0x00,
	0xc4, 0x7a, 0x88, 0x33, 0x00, 0xfa, 0x00, 0xff, 0x12, 0xc8, 0x13, 0xef, 0x7a, 0x88, 0x7f, 0x8c,
	0xfa, 0x13, 0xff, 0x00, 0xc8, 0x33, 0xcc, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x6f, 0x00, 0x00
};
reversed scattered(16,4) char nightfall_006[64] = {
	0x00, 0x60, 0x31, 0x00, 0x10, 0xe0, 0xf5, 0x00, 0x70, 0xd1, 0xe5, 0x00, 0xf0, 0x31, 0x84, 0x32,
	0xc0, 0xf5, 0x00, 0xfa, 0x11, 0xe5, 0x12, 0xea, 0x75, 0x84, 0x7a, 0x88, 0xf5, 0x00, 0xfa, 0x00,
	0xc4, 0x32, 0xc8, 0x33, 0x00, 0xfa, 0x88, 0xff, 0x12, 0xea, 0x13, 0xef, 0x7a, 0x88, 0x7f, 0x8c,
	0xfa, 0x00, 0xff, 0x00, 0xc8, 0x33, 0xcc, 0x00, 0x00, 0x7f, 0x8c, 0x00, 0x00, 0x6f, 0x00, 0x00
};
reversed scattered(16,4) char nightfall_007[64] = {
	0x60, 0xc4, 0x00, 0x00, 0x60, 0xc4, 0x00, 0x00, 0x60, 0xfa, 0xfa, 0xfa, 0x60, 0xfa, 0xfa, 0xfa,
	0x60, 0xc4, 0x00, 0x00, 0x60, 0xc4, 0x00, 0x00, 0x60, 0xc4, 0x00, 0x00, 0x70, 0xe5, 0x00, 0x00,
	0x30, 0x65, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x65, 0x00, 0x00,
	0x30, 0x65, 0x00, 0x00, 0xff, 0xf0, 0x5e, 0x54, 0x30, 0x65, 0x00, 0x00, 0xfd, 0xfd, 0xfd, 0xfd
};