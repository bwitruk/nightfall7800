#include "stdlib.h"
#include "string.h"
#include "prosystem.h"
#include "joystick.h"

#define MODE_320AC

ramchip char previous_joystick[2];

#include "nightfall_tiles.c"
#include "nightfall_characters.c"

#define LADDER_WIDTH 16
//#define LADDER_0_1_LEFT 48
//#define LADDER_2_1_LEFT 48
//in Tiled its 48px but seems like 20 in game
#define LADDER_0_2_LEFT 20
#define LADDER_TOP 140
#define LADDER_BOTTOM 8

#define DAY_START_TIME 0
#define DUSK_START_TIME 300 //~5 seconds
#define NIGHT_START_TIME (DUSK_START_TIME + 600) //~10 seconds
#define DAWN_START_TIME (NIGHT_START_TIME + 300) //~5 seconds
#define DAY_END_TIME (DAWN_START_TIME + 600) //~10 seconds
#define BACKGROUND_FLIP 60 //~1 second

ramchip int screen_no;
ramchip int clock_ticker;
ramchip int tile_x, tile_y;
ramchip char background;
ramchip char background_ticker;
ramchip char background_increment;
ramchip char is_day;

#define CHARACTER_HEIGHT 64
#define CHARACTER_WIDTH 32
#define CHARACTER_WIDTH_HALF (CHARACTER_WIDTH / 2)
#define CHARACTER_Y_PLATFORM 148
ramchip char character_x, character_y;
ramchip char character_x_velocity, character_y_velocity;
const char character_movement_speed = 1;
const char character_frame_durations[] = { 20, 10, 10, 20 };
const char character_frame_counts[] = { 4, 5, 5, 4 };
const char *character_animations[] = {
	boy_idle_01, boy_idle_02, boy_idle_03, boy_idle_04
	, boy_walk_right_01, boy_walk_right_02, boy_walk_right_03, boy_walk_right_04, boy_walk_right_05
	, boy_walk_left_01, boy_walk_left_02, boy_walk_left_03, boy_walk_left_04, boy_walk_left_05
};
const char character_idles[] = { 0, 1, 2, 3 };
const char character_walk_right[] = { 4, 5, 6, 7, 8 };
const char character_walk_left[] = { 9, 10, 11, 12, 13 };
const char character_climbs[] = { 0, 1, 2, 3 };
char character_ticker;
char character_frame_index;
char *character_frames;
char *character_gfx;

//Game States
#define GAMESTATE_INTRO 0
#define GAMESTATE_PLAY 1
#define GAMESTATE_PAUSE 2
#define GAMESTATE_GAMEOVER 3

//Character States
#define CHARACTER_STATE_IDLE 0
#define CHARACTER_STATE_WALK 1
#define CHARACTER_STATE_CLIMB 2

//Character Flags
#define CHARACTER_FACE_RIGHT 1
#define CHARACTER_CAN_CLIMB 2
#define CHARACTER_CAN_EXIT_CLIMB 4

ramchip char prev_character_state;
ramchip char character_state;
ramchip unsigned char character_state_flags;

//Triggers
#define TRIGGER_PRESS_UP 0
#define TRIGGER_PRESS_DOWN 1
#define TRIGGER_PRESS_LEFT 2
#define TRIGGER_PRESS_RIGHT 3

void on_day_start() {
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

void clock_step()
{
	if (clock_ticker < DUSK_START_TIME) 
	{
		//Day
		if (clock_ticker == DAY_START_TIME)
			on_day_start();
	}
	else if (clock_ticker < NIGHT_START_TIME) 
	{
		//Dusk
		if (clock_ticker == DUSK_START_TIME) 
		{
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
	else if (clock_ticker < DAWN_START_TIME) 
	{
		//Night
		if (clock_ticker == NIGHT_START_TIME) 
		{
			on_night_start();
		}
	}
	else if (clock_ticker < DAY_END_TIME) 
	{
		//Dawn
		if (clock_ticker == DAWN_START_TIME) 
		{
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
	else if (clock_ticker == DAY_END_TIME) 
	{
		//Reset back to day
		clock_ticker = -1;
	}

	clock_ticker++;
}

// void character_state_trigger(char trigger) 
// {
// 	if (character_state_index == CHARACTER_STATE_IDLE)
// 	{

// 	}
// 	else if (character_state_index == CHARACTER_STATE_WALK)
// 	{

// 	}
// 	else if (character_state_index == CHARACTER_STATE_CLIMB)
// 	{

// 	}
// 	else
// 	{
// 		//Unhandled State
// 	}
// }

void character_reset_animation()
{
	//Reset Animations
	character_frame_index = 0;
	character_ticker = 0;

	X = character_frames[Y = character_frame_index];
	character_gfx = character_animations[X];
}

void character_state_changed() 
{
	prev_character_state = character_state;

	//Exit State
	if (prev_character_state == CHARACTER_STATE_IDLE)
	{

	}
	else if (prev_character_state == CHARACTER_STATE_WALK) 
	{

	}
	else if (prev_character_state == CHARACTER_STATE_CLIMB) 
	{
		//TODO snap character to ground
		character_y = CHARACTER_Y_PLATFORM;
	}	

	//Enter State
	if (character_state == CHARACTER_STATE_IDLE)
	{
		character_frames = character_idles;
	}
	else if (character_state == CHARACTER_STATE_WALK) 
	{
		if (character_state_flags & CHARACTER_FACE_RIGHT)
			character_frames = character_walk_right;
		else
			character_frames = character_walk_left;
	}
	else if (character_state == CHARACTER_STATE_CLIMB) 
	{
		character_frames = character_climbs;

		//TODO properly snap player X to ladder X
		//Save current ladder
		character_x = LADDER_0_2_LEFT;
	}

	character_reset_animation();
}

void collison_check() 
{
	//TODO zone based check, limit objects
	if (character_x + 32 >= LADDER_0_2_LEFT
			&& character_x <= LADDER_0_2_LEFT + LADDER_WIDTH) 
	{
		character_state_flags |= CHARACTER_CAN_CLIMB;
	}
	else
	{
		character_state_flags &= ~CHARACTER_CAN_CLIMB;
	}

	if (character_y >= LADDER_BOTTOM
			&& character_y <= LADDER_TOP) 
	{
		character_state_flags |= CHARACTER_CAN_EXIT_CLIMB;
	}
	else
	{
		character_state_flags &= ~CHARACTER_CAN_EXIT_CLIMB;
	}
}

void character_x_changed() 
{
	//TODO Pause character activity during transition
	//TODO define constants
	if (character_x == 127 && tile_x < 320) 
	{
		tile_x += 160;
		character_x = 0;
	}
	else if (character_x == 0 && tile_x > 0) 
	{
		tile_x -= 160;
		character_x = 126;
	}
}

void character_y_changed() 
{
	//TODO Pause character activity during transition
	//TODO define constants
	if (character_y == 200 && tile_y < 448) 
	{
		tile_y += 224;
		character_y = 0;
	}
	else if (character_y == 0 && tile_y > 0) 
	{
		tile_y -= 224;
		character_y = CHARACTER_Y_PLATFORM;
	}
}

void character_update_movement()
{
	char previous_character_x = character_x;
	char previous_character_y = character_y;

	character_x += character_x_velocity;
	character_y += character_y_velocity;

	if (previous_character_x != character_x) 
	{
		character_x_changed();
		collison_check();
	}

	if (previous_character_y != character_y) 
	{
		character_y_changed();
		collison_check();
	}
}

void character_update_animations() 
{
	if (character_ticker == character_frame_durations[X = character_state]) 
	{
		character_frame_index++;

		if (character_frame_index >= character_frame_counts[X])
			character_frame_index = 0;

		character_ticker = 0;

		X = character_frames[Y = character_frame_index];
		character_gfx = character_animations[X];
	}

	character_ticker++;
}

void character_state_update()
{
	if (character_state == CHARACTER_STATE_IDLE) 
	{
		if (joystick[0] & (JOYSTICK_LEFT | JOYSTICK_RIGHT))
		{
			character_state = CHARACTER_STATE_WALK;
		}
		else if (joystick[0] & (JOYSTICK_UP | JOYSTICK_DOWN)
					&& character_state_flags & CHARACTER_CAN_CLIMB)
		{
			character_state = CHARACTER_STATE_CLIMB;
		}
	}
	else if (character_state == CHARACTER_STATE_WALK)
	{
		if (joystick[0] & JOYSTICK_LEFT) 
		{
			if (character_state_flags & CHARACTER_FACE_RIGHT)
			{
				character_frames = character_walk_left;
				character_reset_animation();
				character_state_flags &= ~CHARACTER_FACE_RIGHT;
			}
			character_x_velocity = -character_movement_speed;
		}
        else if (joystick[0] & JOYSTICK_RIGHT) 
		{
			if (!(character_state_flags & CHARACTER_FACE_RIGHT))
			{
				character_frames = character_walk_right;
				character_reset_animation();
				character_state_flags |= CHARACTER_FACE_RIGHT;
			}
			character_x_velocity = character_movement_speed;
		}
		else if (joystick[0] & (JOYSTICK_UP | JOYSTICK_DOWN) 
					&& character_state_flags & CHARACTER_CAN_CLIMB)
		{
			character_state = CHARACTER_STATE_CLIMB;
		}
		else 
		{
			character_x_velocity = 0;

			character_state = CHARACTER_STATE_IDLE;
		}
	}
	else if (character_state == CHARACTER_STATE_CLIMB) 
	{
		if (joystick[0] & JOYSTICK_UP) 
		{
			character_y_velocity = -character_movement_speed;
		}
		else if (joystick[0] & JOYSTICK_DOWN) 
		{
			character_y_velocity = character_movement_speed;			
		}
		else 
		{
			character_y_velocity = 0;
		}
	}

	character_update_movement();
	character_update_animations();

	if (character_state != prev_character_state)
	{
		character_state_changed();
	}
}

void character_init() 
{
	character_state = CHARACTER_STATE_IDLE;
	character_state_changed();
	// character_x = 100;
	// character_y = CHARACTER_Y_PLATFORM;
	character_x = 100;
	character_y = CHARACTER_Y_PLATFORM;
	character_x_velocity = 0;
	character_y_velocity = 0;
	character_state_flags = CHARACTER_FACE_RIGHT & ~CHARACTER_CAN_CLIMB;
}

void main() 
{
    // tile_x = 160; 
	// tile_y = 448;
    tile_x = 0;
	tile_y = 448;
	
	clock_ticker = 0;

	character_init();

    multisprite_init();
    multisprite_set_charbase(sprite_kenney_mono_14);
    sparse_tiling_init(nightfall_tiles_data_ptrs);
    joystick_init();
    
    sparse_tiling_goto(tile_x, tile_y);

    *P0C2 = multisprite_color(0xbc); // Light turquoie
    *P1C2 = multisprite_color(0x33); // Red
    *P2C2 = multisprite_color(0xa5); // Dark turquoise
    *P3C2 = multisprite_color(0x83); // Blue
    *P4C2 = 0x0f; // White
    *P5C2 = 0x00; // Black
    *P6C2 = multisprite_color(0x29); // Orange 
    *P7C2 = multisprite_color(0x3c); // Rose 

    // Main loop
    do 
	{
		clock_step();

        multisprite_flip();

		previous_joystick[0] = joystick[0];
		previous_joystick[1] = joystick[1];
        joystick_update();

		//Process Input
        // if (joystick[0] & JOYSTICK_LEFT) tile_x--; 
        // else if (joystick[0] & JOYSTICK_RIGHT) tile_x++;
        // if (joystick[0] & JOYSTICK_UP) y--; 
        // else if (joystick[0] & JOYSTICK_DOWN) y++;

		//Background
		sparse_tiling_goto(tile_x, tile_y);

		//Character Update
		character_state_update();

		//Draw Character
		//x, y, gfx, width, palette, height, mode
		multisprite_display_big_sprite(character_x, character_y, character_gfx, 8, 4, 4, 1);

    } while(1);
}