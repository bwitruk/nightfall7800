#include "stdlib.h"
#include "string.h"
#include "prosystem.h"
#include "joystick.h"

#define MODE_320AC

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

#define TILING_HEIGHT 14
#define TILING_WIDTH 20
#include "sparse_tiling.h"

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

#define DAY_TIME 0
#define DUSK_TIME 300 //~5 seconds
#define NIGHT_TIME (DUSK_TIME + 600) //~10 seconds
#define DAWN_TIME (NIGHT_TIME + 300) //~5 seconds
#define DAY_END (DAWN_TIME + 600) //~10 seconds
#define BACKGROUND_FLIP 60 //~1 second

ramchip int clock_ticker;
ramchip int x, y;
ramchip char background;
ramchip char background_ticker;
ramchip char background_increment;
ramchip char is_day;

void on_day_start()
{
	//Set background to day
	//Flip colors to day
	is_day = 1;
	background = 0x0f;
	*BACKGRND = background;
}

void on_night_start()
{	
	//Set background to night
	//Flip colors to night
	is_day = 0;
	background = 0x00;
	*BACKGRND = background;
}

void clock_step() {
	if (clock_ticker < DUSK_TIME) {
		//Day
		if (clock_ticker == DAY_TIME)
			on_day_start();
	}
	else if (clock_ticker < NIGHT_TIME) {
		//Dusk
		if (clock_ticker == DUSK_TIME) {
			//*BACKGRND = 0xbc;

			//Start transition
			background_increment = -1;
			background_ticker = 0;
			background = 0x0f;
			*BACKGRND = background;
		}

		if (background != 0x00)
		{
			if (background_ticker == BACKGROUND_FLIP)
			{
				background = background + background_increment;
				*BACKGRND = background;

				background_ticker = -1;
			}

			background_ticker++;
		}
	}
	else if (clock_ticker < DAWN_TIME) {
		//Night
		if (clock_ticker == NIGHT_TIME) {
			on_night_start();
		}
	}
	else if (clock_ticker < DAY_END) {
		//Dawn
		if (clock_ticker == DAWN_TIME) {
			//Start transition
			background_increment = 1;
			background_ticker = 0;
			background = 0x00;
			*BACKGRND = background;
		}

		if (background != 0x0f)
		{
			if (background_ticker == BACKGROUND_FLIP)
			{
				background = background + background_increment;
				*BACKGRND = background;

				background_ticker = -1;
			}

			background_ticker++;
		}
	}
	else if (clock_ticker == DAY_END) {
		//Reset back to day
		clock_ticker = -1;
	}

	clock_ticker++;
}

void main()
{
    x = 0; y = 0;
	clock_ticker = 0;

    multisprite_init();
    multisprite_set_charbase(nightfall_001);
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

    } while(1);
}