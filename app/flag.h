#ifndef __ALARM_FLAGS__
#define __ALARM_FLAGS__

/*
 * Sensor flags
 *
 * They will be in the 4 most significant bits
 * to standardize the serial communication
 */
#define TEMPERATURE_SENSOR	1
#define LIGHT_SENSOR		2
#define GAS_SENSOR		3

#define FIRE_ALERT		4
#define LIGHTS_ON		5
#define TURN_OFF_LIGHS		6
#define BUZZER_ON		7
#define TURN_OFF_BUZZER		8

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
