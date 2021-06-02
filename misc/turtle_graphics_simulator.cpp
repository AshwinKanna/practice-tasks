/*
Make turtle move through an array and draw a path
*/

#include "turtle_graphics_simulator.hpp"

int main()
{
    int floor[ROWS][COLS] = {0};
    short user_input;
    turtle my_turtle;
    bool loop_flag = true;

    while(loop_flag) {
        cout << "Choose any option - 1.Pen up 2.Pen down 3.Turn right 4.Turn left 5.Move Forward\n"
             " 6.Display Floor 7.Display Turtle_Position 8.Display Turtle_Direction_Facing 9.Reset 10.Exit" << endl;
        cin >> user_input;

        switch(user_input) {
            case 1: cout << "Current position of Pen is " << my_turtle.turtle_pen_position << endl;
                    my_turtle.turtle_pen_position = UP;
                    cout << "Changed position of Pen to " << my_turtle.turtle_pen_position << endl;
                    break;
            case 2: cout << "Current position of Pen is " << my_turtle.turtle_pen_position << endl;
                    my_turtle.turtle_pen_position = DOWN;
                    cout << "Changed position of Pen to " << my_turtle.turtle_pen_position << endl;
                    break;
            case 3: cout << "Previously,Turtle is facing towards " << my_turtle.direction_facing << endl;
                    my_turtle.direction_facing  = static_cast<direction>((static_cast<int>(my_turtle.direction_facing)+1) % 4);
                    cout << "Now,Turtle is facing towards " << my_turtle.direction_facing << endl;
                    break;
            case 4: { 
                    cout << "Previously,Turtle is facing towards " << my_turtle.direction_facing << endl;
                    int tmp = (static_cast<int>(my_turtle.direction_facing) - 1) % 4;
                    if(tmp < 0)
                        tmp = 3;
                    my_turtle.direction_facing  = static_cast<direction>(tmp);
                    cout << "Now,Turtle is facing towards " << my_turtle.direction_facing << endl;
                    break;
            }
            case 5: handleMovement(floor, my_turtle);
                    break;
            case 6: displayFloor(floor);
                    break;
            case 7: cout << "Turtle's position - [" << my_turtle.position_row << "][" << my_turtle.position_col << "]" << endl;
                    break;
            case 8: cout << "Turtle is facing the direction - " << my_turtle.direction_facing << endl;
                    break;
            case 9: cout << "Resetting Floor and Turtle" << endl;
                    reset(floor, my_turtle);
                    break;
            case 10: cout << "Thank you for using." << endl;
                    loop_flag = false;
                    break;
            default: cout << "Unknown option specified" << endl;
                    break;
        }

    }
}

void handleMovement(int floor [][COLS], turtle &my_turtle) {
    cout << "Enter number of steps to move" << endl;
    int steps = 0;
    cin >> steps;

    if(my_turtle.direction_facing == EAST) {
        int possible_steps = COLS - 1 - my_turtle.position_col;
        if(steps > possible_steps)
        {
            cout << "Only " << possible_steps << " steps is possible in the direction " << my_turtle.direction_facing << endl;
            return;
        }

        if(my_turtle.turtle_pen_position == DOWN) {
            for(int col_iter=my_turtle.position_col; col_iter <= (my_turtle.position_col + steps); ++col_iter) {
                floor[my_turtle.position_row][col_iter] = 1;
            }
        }

        my_turtle.position_col += steps;
    }

    else if(my_turtle.direction_facing == SOUTH) {
        int possible_steps = ROWS - 1 - my_turtle.position_row;
        if(steps > possible_steps)
        {
            cout << "Only " << possible_steps << " steps is possible in the direction " << my_turtle.direction_facing << endl;
            return;
        }

        if(my_turtle.turtle_pen_position == DOWN) {
            for(int row_iter=my_turtle.position_row; row_iter <= (my_turtle.position_row + steps); ++row_iter) {
                floor[row_iter][my_turtle.position_col] = 1;
            }
        }
        my_turtle.position_row += steps;
    }

    else if(my_turtle.direction_facing == WEST) {
        int possible_steps = my_turtle.position_col;
        if(steps > possible_steps)
        {
            cout << "Only " << possible_steps << " steps is possible in the direction " << my_turtle.direction_facing << endl;
            return;
        }

        if(my_turtle.turtle_pen_position == DOWN) {
            for(int col_iter=my_turtle.position_col; col_iter >= (possible_steps - steps); --col_iter) {
                floor[my_turtle.position_row][col_iter] = 1;
            }
        }
        my_turtle.position_col -= steps;
    }

    else if(my_turtle.direction_facing == NORTH) {
        int possible_steps = my_turtle.position_row;
        if(steps > possible_steps)
        {
            cout << "Only " << possible_steps << " steps is possible in the direction " << my_turtle.direction_facing << endl;
            return;
        }

        if(my_turtle.turtle_pen_position == DOWN) {
            for(int row_iter=my_turtle.position_row; row_iter >= (possible_steps - steps); --row_iter) {
                floor[row_iter][my_turtle.position_col] = 1;
            }
        }
        my_turtle.position_row -= steps;
    }
}


void displayFloor(const int floor[][COLS]) {

    cout << "Displaying floor" << endl;

    for(int row_iter=0; row_iter < ROWS; ++row_iter) {
        for(int col_iter=0; col_iter < COLS; ++col_iter) {
            if(floor[row_iter][col_iter] == 0) {
                cout << "*";
            }
            else {
                cout << "$";
            }
        }
        cout << endl;
    }
}

void reset(int floor[][COLS], turtle &my_turtle) {
    
    for(int row_iter=0; row_iter < ROWS; ++row_iter) {
        for(int col_iter=0; col_iter < COLS; ++col_iter) {
            floor[row_iter][col_iter] = 0;
        }
    }

    my_turtle.position_col = my_turtle.position_row = 0;
    my_turtle.direction_facing = EAST;
    my_turtle.turtle_pen_position = UP;
}