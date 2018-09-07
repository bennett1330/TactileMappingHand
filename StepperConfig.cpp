#include "StepperConfig.h"

using namespace std;

int config_min_helper_stepper_precheck(int &step_count, char id)
{
	char char_input;
	while (1)
	{
		cout << "Is " << id << " at zero position of " << id << " axis? [y/n]" << endl;
		cin.clear();
		cin >> char_input;
		if (char_input == 'y' || char_input == 'Y')
		{
			cout << "Saving as minimum position." << endl;
			set_step_min_helper(step_count);
			return 1;
		}
		else if (char_input == 'n' || char_input == 'N')
		{
			return 0;
		}
	}
}

int config_min_helper_stepper(int DIR_PIN, int EN_PIN, int &step_count, char id)
{
	if (config_min_helper_stepper_precheck(step_count, id)) return 0;

	int temp;
	char char_input1, char_input2;
	int direction_input = LOW;
	while (1)
	{
		cout << "Locating " << id << " minimum/zero position." << endl;
		cout << "Enter a key then <enter> to stop." << endl;
		cin.clear();
		cin.ignore();
		set_step_speed_eighth();
		set_motor_helper_stepper(DIR_PIN, EN_PIN, direction_input, HIGH); 
		cin >> temp; // STEPPERS ARE ACTIVE LOW but not-ed
		set_motor_helper_stepper(DIR_PIN, EN_PIN, direction_input, LOW);
		while (1)
		{
			cout << "Save minimum position? [y/n]" << endl;
			cin.clear();
			cin.ignore();
			cin >> char_input1;
			if (char_input1 == 'y' || char_input1 == 'Y')
			{
				cout << "Saving as minimum/zero position." << endl;
    			set_step_min_helper(step_count);
    			return 0;
			}
			else if (char_input1 == 'n' || char_input1 == 'N')
			{
				cout << "Continue negative or positive direction? [n/p]" << endl;
				cin.clear();
				cin >> char_input2;
				if (char_input2 == 'n' || char_input2 == 'N')
				{
					direction_input = LOW;
					break;
				}
				else if (char_input2 == 'p' || char_input2 == 'P')
				{
					direction_input = HIGH;
					break;
				}
			}
		}
	}
    return 1;
}

int config_max_helper_stepper(int DIR_PIN, int EN_PIN, int &step_count, int &step_count_max, char id)
{
	int temp;
	char char_input1, char_input2;
	int direction_input = HIGH;
	while (1)
	{
		cout << "Locating " << id << " maximum position." << endl;
		cout << "Enter a key then <enter> to stop." << endl;
		cin.clear();
		cin.ignore();
		set_step_speed_eighth();
		set_motor_helper_stepper(DIR_PIN, EN_PIN, direction_input, HIGH);
		cin >> temp; // STEPPERS ARE ACTIVE LOW but not-ed
		set_motor_helper_stepper(DIR_PIN, EN_PIN, direction_input, LOW);
		while (1)
		{
			cout << "Save maximum position? [y/n]" << endl;
			cin.clear();
			cin.ignore();
			cin >> char_input1;
			if (char_input1 == 'y' || char_input1 == 'Y')
			{
				cout << "Saving as maximum position." << endl;
    			set_step_max_helper(step_count, step_count_max);
    			return 0;
			}
			else if (char_input1 == 'n' || char_input1 == 'N')
			{
				cout << "Continue negative or positve direction? [n/p]" << endl;
				cin.clear();
				cin >> char_input2;
				if (char_input2 == 'n' || char_input2 == 'N')
				{
					direction_input = LOW;
					break;
				}
				else if (char_input2 == 'p' || char_input2 == 'P')
				{
					direction_input = HIGH;
					break;
				}
			}
		}
	}
    return 1;
}

int move_start_position_helper_stepper(int DIR_PIN, int EN_PIN, int &step_count)
{
	set_motor_helper_stepper(DIR_PIN, EN_PIN, LOW, HIGH);
	while (step_count > 0) {}
	set_motor_helper_stepper(DIR_PIN, EN_PIN, LOW, LOW);
	return 0;
}

int move_position_helper_stepper(int DIR_PIN, int EN_PIN, int &step_count, int step_stop)
{
	set_motor_helper_stepper(DIR_PIN, EN_PIN, HIGH, HIGH);
	while (step_count < step_stop) {}
	set_motor_helper_stepper(DIR_PIN, EN_PIN, HIGH, LOW);
	return 0;
}

int next_position_helper_stepper(int DIR_PIN, int EN_PIN, int &step_count, int step_count_max, int STEP_RESOLUTION)
{
	set_step_speed_eighth();
	if (step_count_max - step_count >= STEP_RESOLUTION)
	{
		move_position_helper_stepper(DIR_PIN, EN_PIN, step_count, step_count + STEP_RESOLUTION);
		return 0;
	}
	else
	{
		return 1;
	}
}

///////////////////////////////////////////////////////////////////////////////

int config_min_x()
{
	return config_min_helper_stepper(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, step_count_x, 'X');
}

int config_min_y()
{
	return config_min_helper_stepper(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, step_count_y, 'Y');
}

int config_min_z()
{
	return config_min_helper_stepper(DIR_RING_Z_PIN, EN_RING_Z_PIN, step_count_z, 'Z');
}

///////////////////////////////////////////////////////////////////////////////

int config_max_x()
{
	return config_max_helper_stepper(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, step_count_x, step_count_x_max, 'X');
}

int config_max_y()
{
	return config_max_helper_stepper(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, step_count_y, step_count_y_max, 'Y');
}

int config_max_z()
{
	return config_max_helper_stepper(DIR_RING_Z_PIN, EN_RING_Z_PIN, step_count_z, step_count_z_max, 'Z');
}

///////////////////////////////////////////////////////////////////////////////

int move_start_position_x()
{
	return move_start_position_helper_stepper(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, step_count_x);
}

int move_start_position_y()
{
	return move_start_position_helper_stepper(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, step_count_y);
}

int move_start_position_z()
{
	return move_start_position_helper_stepper(DIR_RING_Z_PIN, EN_RING_Z_PIN, step_count_z);
}

///////////////////////////////////////////////////////////////////////////////

int next_position_x()
{
	return next_position_helper_stepper(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, 
		step_count_x, step_count_x_max, STEP_RESOLUTION_X);
}
int next_position_y()
{
	return next_position_helper_stepper(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, 
		step_count_y, step_count_y_max, STEP_RESOLUTION_Y);
}
int next_position_z()
{
	return next_position_helper_stepper(DIR_RING_Z_PIN, EN_RING_Z_PIN, 
		step_count_z, step_count_z_max, STEP_RESOLUTION_Z);
}
