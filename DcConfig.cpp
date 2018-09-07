#include "DcConfig.h"

using namespace std;

int config_min_helper_dc_precheck(int &state_count, char id)
{
	char char_input;
	while(1)
	{
		cout << "Is " << id << " at zero position [y/n]" << endl;
		cin.clear();
		cin >> char_input;
		if (char_input == 'y' || char_input == 'Y')
		{
			cout << "Saving as minimum position." << endl;
			set_dc_min_helper(state_count);
			return 1;
		}
		else if (char_input == 'n' || char_input == 'N')
		{
			return 0;
		}
	}
}

int config_min_helper_dc(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count, char id)
{
	if (config_min_helper_dc_precheck(state_count, id)) return 0;

	char char_input1;
	int direction_input = HIGH;
	cout << "Locating " << id << " minimum/zero position." << endl;
	cout << "Save minimum position? (no to turn more) [y/n]" << endl;
	while (1)
	{
		cin.clear();
		cin.ignore();
		cin >> char_input1;
		if (char_input1 == 'y' || char_input1 == 'Y')
		{
			cout << "Saving as minimum/zero position." << endl;
			set_dc_min_helper(state_count);
			return 0;
		}
		set_motor_helper_dc(DIR_PIN, EN_PIN, direction_input, HIGH);
		for (int i = 0; i < 200; i++)
		{
			std::this_thread::sleep_for(std::chrono:: milliseconds(1));
			//update_count_helper(ENCODER_PIN, DIR_PIN, state_value, state_count);
		}
		set_motor_helper_dc(DIR_PIN, EN_PIN, direction_input, LOW);
	}
    return 1;
}

int config_max_helper_dc(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count, int &state_count_max, char id)
{
	int temp;
	char char_input1, char_input2;
	int direction_input = LOW;
	cout << "Locating " << id << " maximum position." << endl;
	cout << "Save maximum position? (no to turn more) [y/n]" << endl;
	while (1)
	{
		cin.clear();
		cin.ignore();
		cin >> char_input1;
		if (char_input1 == 'y' || char_input1 == 'Y')
		{
			cout << "Saving as maximum position." << endl;
			set_dc_max_helper(state_count, state_count_max);
			return 0;
		}
		set_motor_helper_dc(DIR_PIN, EN_PIN, direction_input, HIGH);
		for (int i = 0; i < 200; i++)
		{
			std::this_thread::sleep_for(std::chrono:: milliseconds(1));
			update_count_helper(ENCODER_PIN, DIR_PIN, state_value, state_count);
		}
		set_motor_helper_dc(DIR_PIN, EN_PIN, direction_input, LOW);
	}
    return 1;
}

int move_start_position_helper_dc(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count)
{
	// cout << "State count : " << state_count << endl;
	set_motor_helper_dc(DIR_PIN, EN_PIN, HIGH, HIGH);
	while (state_count > 0) 
	{
		std::this_thread::sleep_for(std::chrono:: milliseconds(1));
		update_count_helper(ENCODER_PIN, DIR_PIN, state_value, state_count);
	}
	set_motor_helper_dc(DIR_PIN, EN_PIN, HIGH, LOW);
	return 0;
}

int move_position_helper_dc(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count, int state_count_max)
{
	set_motor_helper_dc(DIR_PIN, EN_PIN, LOW, HIGH);
	while (state_count < state_count_max) 
	{
		update_count_helper(ENCODER_PIN, DIR_PIN, state_value, state_count);
	}
	set_motor_helper_dc(DIR_PIN, EN_PIN, LOW, LOW);
	return 0;
}

int measure_position_helper(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count, int state_count_max)
{

	return 0;
}

///////////////////////////////////////////////////////////////////////////////

int config_min_index()
{
	return config_min_helper_dc(ENCODER_INDEX_PIN, DIR_INDEX_X_PIN, EN_INDEX_X_PIN, state_value_index, state_count_index, 'I');
}

int config_min_middle()
{
	return config_min_helper_dc(ENCODER_MIDDLE_PIN, DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, state_value_middle, state_count_middle, 'M');
}

int config_min_ring()
{
	return config_min_helper_dc(ENCODER_RING_PIN, DIR_RING_Z_PIN, EN_RING_Z_PIN, state_value_ring, state_count_ring, 'R');
}

int config_min_pinky()
{
	return config_min_helper_dc(ENCODER_PINKY_PIN, DIR_PINKY_MS_PIN, EN_PINKY_MS_PIN, state_value_pinky, state_count_pinky, 'P');
}

///////////////////////////////////////////////////////////////////////////////

int config_max_index()
{
	return config_max_helper_dc(ENCODER_INDEX_PIN, DIR_INDEX_X_PIN, EN_INDEX_X_PIN, state_value_index, state_count_index, state_count_index_max, 'I');
}

int config_max_middle()
{
	return config_max_helper_dc(ENCODER_MIDDLE_PIN, DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, state_value_middle, state_count_middle, state_count_middle_max, 'M');
}

int config_max_ring()
{
	return config_max_helper_dc(ENCODER_RING_PIN, DIR_RING_Z_PIN, EN_RING_Z_PIN, state_value_ring, state_count_ring, state_count_ring_max, 'R');
}

int config_max_pinky()
{
	return config_max_helper_dc(ENCODER_PINKY_PIN, DIR_PINKY_MS_PIN, EN_PINKY_MS_PIN, state_value_pinky, state_count_pinky, state_count_pinky_max, 'P');
}

///////////////////////////////////////////////////////////////////////////////

int move_start_position_index()
{
	return move_start_position_helper_dc(ENCODER_INDEX_PIN, DIR_INDEX_X_PIN, EN_INDEX_X_PIN, state_value_index, state_count_index);
}

int move_start_position_middle()
{
	return move_start_position_helper_dc(ENCODER_MIDDLE_PIN, DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, state_value_middle, state_count_middle);
}

int move_start_position_ring()
{
	return move_start_position_helper_dc(ENCODER_RING_PIN, DIR_RING_Z_PIN, EN_RING_Z_PIN, state_value_ring, state_count_ring);
}

int move_start_position_pinky()
{
	return move_start_position_helper_dc(ENCODER_PINKY_PIN, DIR_PINKY_MS_PIN, EN_PINKY_MS_PIN, state_value_pinky, state_count_pinky);
}

//////////////////////////////////////////////////////////////////////////////////////////////

int measure_position_index()
{
	return measure_position_helper(ENCODER_INDEX_PIN, DIR_INDEX_X_PIN, EN_INDEX_X_PIN, state_value_index, state_count_index, state_count_index_max);
}

int measure_position_middle()
{
	return measure_position_helper(ENCODER_MIDDLE_PIN, DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, state_value_middle, state_count_middle, state_count_middle_max);
}

int measure_position_ring()
{
	return measure_position_helper(ENCODER_RING_PIN, DIR_RING_Z_PIN, EN_RING_Z_PIN, state_value_ring, state_count_ring, state_count_ring_max);
}
int measure_position_pinky()
{
	return measure_position_helper(ENCODER_PINKY_PIN, DIR_PINKY_MS_PIN, EN_PINKY_MS_PIN, state_value_pinky, state_count_pinky, state_count_pinky_max);
}
