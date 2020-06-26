#ifndef _TURTLE_GRAPHICS_SIM_HH_
#define _TURTLE_GRAPHICS_SIM_HH_

#include <iostream>

using std::endl;
using std::cout;
using std::cin;

#define ROWS 20
#define COLS 20

enum direction { NORTH, EAST, SOUTH, WEST};
enum pen_position { UP, DOWN};

struct turtle {
    // starts at (0,0) facing towards EAST, with pen_position as UP
    int position_row = 0, position_col = 0;
    direction direction_facing = EAST;
    pen_position turtle_pen_position = UP;
};

void reset(int [][COLS], turtle &);
void displayFloor(const int [][COLS]);
void handleMovement(int [][COLS], turtle &);


#endif