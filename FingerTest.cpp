#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "GpioSetup.h"
#include "SelectSetup.h"
#include "StepSetup.h"
#include "MotorSetup.h"

using namespace std;

int main(int argc, char **argv)
{
    if ( init() ) return 1;
    if ( init_select() ) return 2;
    set_finger_mode();
    if ( init_motors() ) return 3;

    int motor_input, direction_input, direction, time;
    while (1)
    {
        cout << "Select [0: Exit    1: Index      2: Middle     3: Ring     4: Pinky]" << endl;
        cin.clear();
        cin >> motor_input;
        if (motor_input == 0) break;

        cout << "Select [0: Exit    1: Forward    2: Reverse]" << endl;
        cin.clear();
        cin >> direction_input;
        if (direction_input == 0) break;
        direction = (direction_input == 1) ? LOW : direction;
        direction = (direction_input == 2) ? HIGH : direction;

        cout << "Select [0: Exit    +int: (#) * 0.1 seconds]" << endl;
        cin.clear();
        cin >> time;
        if (time == 0) break;

        chrono::milliseconds ms(100 * time);
        switch (motor_input)
        {
            case 1:
                set_motor_index(direction, HIGH);
                this_thread::sleep_for(ms);
                set_enable_index(LOW);
                break;
            case 2:
                set_motor_middle(direction, HIGH);
                this_thread::sleep_for(ms);
                set_enable_middle(LOW);
                break;
            case 3:
                set_motor_ring(direction, HIGH);
                this_thread::sleep_for(ms);
                set_enable_ring(LOW);
                break;
            case 4:
                set_motor_pinky(direction, HIGH);
                this_thread::sleep_for(ms);
                set_enable_pinky(LOW);
                break;
            default:
                continue;
        }
    }
    shutdown();
    return 0;
}
