#include <iostream>
#include <thread>

#include "FsrSetup.h"
#include "StepSetup.h"
#include "SelectSetup.h"
#include "StepperConfig.h"
#include "DcConfig.h"
#include "MeasurementConfig.h"

using namespace std;

int main(int argc, char **argv)
{
    if ( init() ) return 1;
    if ( init_select() ) return 2;
    if ( init_motors() ) return 3;
    if ( init_encoders() ) return 4;
    if ( init_fsrs() ) return 5;

    
    set_3daxis_mode();

    int temp;
    thread step(start_step);

    config_min_x();
    config_min_y();
    config_min_z();

    config_max_x();
    config_max_y();
    config_max_z();

    move_start_position_x();
    move_start_position_y();
    move_start_position_z();


    set_finger_mode();

    config_min_index();
    config_min_middle();
    config_min_ring();
    config_min_pinky();

    config_max_index();
    config_max_middle();
    config_max_ring();
    config_max_pinky();

    move_start_position_index();
    move_start_position_middle();
    move_start_position_ring();
    move_start_position_pinky();

    while (1) {

        cout << "Place object in mapping region now." << endl;
        cout << "Enter a key and <enter> to continue." << endl;
        cin.clear();
        cin >> temp;


        do // Z LOOP
        {
            do // X LOOP
            {
                do // Y LOOP
                {
                    set_finger_mode();

                    thread get_point_index(move_finger_index);
                    thread get_point_middle(move_finger_middle);
                    thread get_point_ring(move_finger_ring);
                    thread get_point_pinky(move_finger_pinky);

                    get_point_index.join();
                    get_point_middle.join();
                    get_point_ring.join();
                    get_point_pinky.join();

                    //get_point_index.~thread();
                    //get_point_middle.~thread();
                    //get_point_ring.~thread();
                    //get_point_pinky.~thread();


                    set_3daxis_mode();
                } while (next_position_y() == 0);
                move_start_position_y();
            } while (next_position_x() == 0);
            move_start_position_x();
        } while (next_position_z() == 0);

        cout << "Mapping complete." << endl;
        // save file prompts
        // rerun prompt
            // reconfig prompt

    }
    stop_step();
    step.join();

    shutdown();
    return 0;
}
