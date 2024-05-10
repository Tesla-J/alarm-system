#ifndef __ALARM_FLAGS__
#define __ALARM_FLAGS__

/*
 * Sensor flags
 *
 * They will be in the 4 most significant bits
 * to standardize the serial communication
 */
const int TEMPERATURE_SENSOR	=	1;
const int LIGHT_SENSOR		=	2;
const int GAS_SENSOR		=	3;

const int FIRE_ALERT		=	4;
const int LIGHTS_ON		=	5;
const int TURN_OFF_LIGHS	=	6;
const int BUZZER_ON		=	7;
const int TURN_OFF_BUZZER	=	8;

/*
 * Sensor manipulation functions
 *
 * Functions to assign and remove flags from sensor data
 * Note that in Arduino Uno the int size is 16 bits
 */

int assign_flag (int flag, int data) {
	return (flag<<12) | data;
}


int remove_flag (int data) {
	return data & 0x0fff;
}

#endif
