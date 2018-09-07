#include "MeasurementConfig.h"

int move_finger_helper(int FSR_PIN, int ENCODER_PIN, int DIR_PIN, int EN_PIN, 
	int &state_value, int &state_count, int state_count_max, int &fsr_flag)
{
	set_motor_helper_dc(DIR_PIN, EN_PIN, LOW, HIGH);
	while ( (state_count <= state_count_max) && (fsr_flag != LOW) )
	{
		std::this_thread::sleep_for(std::chrono:: milliseconds(1));
		update_count_helper(ENCODER_PIN, DIR_PIN, state_value, state_count);
		read_fsr_helper(FSR_PIN, fsr_flag);
	}
	set_motor_helper_dc(DIR_PIN, EN_PIN, LOW, LOW);
	if (fsr_flag == LOW)
	{
		std::cout << "contact made now write code to save the point" << std::endl;
	}
	//std::cout << "line 17 : pre move start pos state count :: " << state_count << std::endl;
	move_start_position_helper_dc(ENCODER_PIN, DIR_PIN, EN_PIN, state_value, state_count);
	//std::cout << "line 19 : post move start pos state count :: " << state_count << std::endl;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

int move_finger_index()
{
	return move_finger_helper(FSR_INDEX_PIN, ENCODER_INDEX_PIN, DIR_INDEX_X_PIN, EN_INDEX_X_PIN, 
		state_value_index, state_count_index, state_count_index_max, fsr_index);
}

int move_finger_middle()
{
	return move_finger_helper(FSR_MIDDLE_PIN, ENCODER_MIDDLE_PIN, DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, 
		state_value_middle, state_count_middle, state_count_middle_max, fsr_middle);
}

int move_finger_ring()
{
	return move_finger_helper(FSR_RING_PIN, ENCODER_RING_PIN, DIR_RING_Z_PIN, EN_RING_Z_PIN, 
		state_value_ring, state_count_ring, state_count_ring_max, fsr_ring);
}

int move_finger_pinky()
{
	return move_finger_helper(FSR_PINKY_PIN, ENCODER_PINKY_PIN, DIR_PINKY_MS_PIN, EN_PINKY_MS_PIN, 
		state_value_pinky, state_count_pinky, state_count_pinky_max, fsr_pinky);
}