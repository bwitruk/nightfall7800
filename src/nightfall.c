#include "stdlib.h"
#include "string.h"
#include "prosystem.h"
#include "joystick.h"

#define MODE_320AC

ramchip char previous_joystick[2];

#include "nightfall_tiles.c"
#include "nightfall_characters.c"

#define DAY_START_TIME 0
#define DUSK_START_TIME 300 //~5 seconds
#define NIGHT_START_TIME (DUSK_START_TIME + 600) //~10 seconds
#define DAWN_START_TIME (NIGHT_START_TIME + 300) //~5 seconds
#define DAY_END_TIME (DAWN_START_TIME + 600) //~10 seconds
#define BACKGROUND_FLIP 60 //~1 second

ramchip int clock_ticker;
ramchip int x, y;
ramchip char background;
ramchip char background_ticker;
ramchip char background_increment;
ramchip char is_day;

ramchip char character_x, character_y;
ramchip signed char character_x_velocity, character_y_velocity;
const char character_movement_speed = 1;
const char character_frame_durations[] = { 20, 10, 10 };
const char character_frame_counts[] = { 4, 5, 5 };
const char *character_animations[] = {
	boy_idle_01, boy_idle_02, boy_idle_03, boy_idle_04
	, boy_walk_right_01, boy_walk_right_02, boy_walk_right_03, boy_walk_right_04, boy_walk_right_05
	, boy_walk_left_01, boy_walk_left_02, boy_walk_left_03, boy_walk_left_04, boy_walk_left_05
};
const char character_idles[] = { 0, 1, 2, 3 };
const char character_walk_right[] = { 4, 5, 6, 7, 8 };
const char character_walk_left[] = { 9, 10, 11, 12, 13 };
char character_ticker;
char character_frame_index;
char *character_frames;
char *character_gfx;

#define CHARACTER_STATE_IDLE 0
#define CHARACTER_STATE_WALK_RIGHT 1
#define CHARACTER_STATE_WALK_LEFT 2

ramchip char prev_character_state_index;
ramchip char character_state_index;

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
	if (clock_ticker < DUSK_START_TIME) {
		//Day
		if (clock_ticker == DAY_START_TIME)
			on_day_start();
	}
	else if (clock_ticker < NIGHT_START_TIME) {
		//Dusk
		if (clock_ticker == DUSK_START_TIME) {
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

void change_character_state(char state_index) {
	if (prev_character_state_index == state_index)
		return;

	prev_character_state_index = character_state_index;
	character_state_index = state_index;

	character_frame_index = 0;
	character_ticker = 0;

	if (character_state_index == CHARACTER_STATE_WALK_LEFT) {
		character_frames = character_walk_left;
	}
	else if (character_state_index == CHARACTER_STATE_WALK_RIGHT) {
		character_frames = character_walk_right;
	}
	else {
		character_frames = character_idles;
	}

	char frame_no = character_frames[character_frame_index];
	character_gfx = character_animations[frame_no];
}

void character_update() {
	if (character_ticker == character_frame_durations[character_state_index]) {
		character_frame_index++;

		if (character_frame_index >= character_frame_counts[character_state_index])
			character_frame_index = 0;

		character_ticker = 0;

		char frame_no = character_frames[character_frame_index];
		character_gfx = character_animations[frame_no];
	}

	//Frame 6 has a glitch for some reason
	//character_gfx = character_animations[6];

	//x, y, gfx, width, palette, height, mode
	multisprite_display_big_sprite(character_x, character_y, character_gfx, 8, 4, 4, 1);

	character_ticker++;

	character_x += character_x_velocity;
}

void character_init() {
	character_ticker = 0;
	character_frame_index = 0;
	character_state_index = 0;
	character_frames = character_idles;
	char frame_no = character_frames[0];
	character_gfx = character_animations[frame_no];
	character_x = 100;
	character_y = 148;
	character_x_velocity = 0;
	character_y_velocity = 0;
}

void main() {
    x = 160; y = 448;
    // x = 320; y = 0;
	
	clock_ticker = 0;

	character_init();

    multisprite_init();
    multisprite_set_charbase(sprite_kenney_mono_9);
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

		previous_joystick[0] = joystick[0];
		previous_joystick[1] = joystick[1];
        joystick_update();

		//Process Input
        // if (joystick[0] & JOYSTICK_LEFT) x--; 
        // else if (joystick[0] & JOYSTICK_RIGHT) x++;
        // if (joystick[0] & JOYSTICK_UP) y--; 
        // else if (joystick[0] & JOYSTICK_DOWN) y++;
		
		if (joystick[0] & JOYSTICK_LEFT) {
			change_character_state(CHARACTER_STATE_WALK_LEFT);
			character_x_velocity = -character_movement_speed;
		}
        else if (joystick[0] & JOYSTICK_RIGHT) {
			change_character_state(CHARACTER_STATE_WALK_RIGHT);
			character_x_velocity = character_movement_speed;
		}
		else {
			change_character_state(CHARACTER_STATE_IDLE);
			character_x_velocity = 0;
		}

		//Background
		sparse_tiling_goto(x, y);

		//Character
		character_update();
    } while(1);
}