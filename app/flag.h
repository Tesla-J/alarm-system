#ifndef __ALARM_FLAGS__
#define __ALARM_FLAGS__

/*
 * Sensor flags
 *
 * They will be in the 4 most significant bits
 * to standardize the serial communication
 */
#define TEMPERATURE_SENSOR
#define LIGHT_SENSOR
#define GAS_SENSOR

#define FIRE_ALERT
#define LIGHTS_ON
#define TURN_OFF_LIGHS
#define BUZZER_ON
#define TURN_OFF_BUZZER

/*
 * Sensor manipulation functions
 *
 * Functions to assign and remove flags from sensor data
 * it assumes that the int size is 32 bits
 * so the data must be less or equal to 0xf00 (3840)
 * to avoid bugs.
 */

int assign_flag (int flag, int data) {
	return (flag<<28) | data;
}


int remove_flag (int data) {
	return data & 0x0fffffff;
}

#endif
