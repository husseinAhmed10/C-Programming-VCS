/*
 * func.c
 *
 *  Created on: Mar 9, 2023
 *      Author: T.S
 */

#include <stdio.h>
#include "header_data_types.h"

//Bonus
#define WITH_ENGINE_TEMP_CONTROLLER 1

/*At the beginning of the program this message appears
 specification 1. Ask the user if he/she wants
 a. Turn on the vehicle engine
 b. Turn off the vehicle engine
 c. Quit the system
 */

char Specification_Ask_the_user(void) {

	char choice;
	do {
		printf("a. Turn on the vehicle engine \n");
		printf("b. Turn off the vehicle engine \n");
		printf("c. Quit the system\n");
		fflush(stdout);
		scanf(" %c", &choice);
		//if the entered char is not one of them, will loop again
	} while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'A'
			&& choice != 'B' && choice != 'C');

	return choice;

}

/*specification 5. Display sensor set menu
 * if user chooses from specification 1 to
 * Turn on the vehicle engine
 */

char Sensor_Set_Menu() {

	char choice;
	do {
		printf("a. Turn off the engine \n");
		printf("b. Set the traffic light color \n");
		printf("c. Set the room temperature (Temperature Sensor)\n");
#if WITH_ENGINE_TEMP_CONTROLLER
		printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
		fflush(stdout);
		scanf(" %c", &choice);

	} while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'A'
			&& choice != 'B' && choice != 'C' && choice != 'd' && choice != 'D');

	return choice;

}

//The following functions are based on the answer of specification 5

//7.a Based on traffic light, the vehicle speed is set
//Assumption: it accepts upper case and lower case char
unsigned short Set_Traffic_Light_color(char c) {
	if (c == 'G' || c == 'g')
		return 100;
	else if (c == 'o' || c == 'O')
		return 30;
	else if (c == 'R' || c == 'r')
		return 0;
	//returned value in km/h
	return 0;	//if wrong value is entered
}

//7.b Based on temp sensor, the temp is set and AC is whatever ON or OFF
//Assumption: at 10 and 30 celsius, AC is off and no temp is set
int sensor_read_room_temperature(short *temperature) {
	if (*temperature < 10 || *temperature > 30) {
		*temperature = 20;
		return 1;		//AC ON
	} else {
		return 0;		//AC OFF
	}
}

//7.c Based on temp sensor, the temp is set and engine temp controller is whatever ON or OFF
//Assumption: at 100 and 150 celsius, engine temp controller is off and no temp is set
void sensor_read_engine_temperature(short *eng_temp,
		Engine_Controller *engineController) {
#if WITH_ENGINE_TEMP_CONTROLLER
	if (*eng_temp < 100 || *eng_temp > 150) {
		*engineController = Controller_ON;
		*eng_temp = 125;
		//Engine controller ON

	} else {
		*engineController = Controller_OFF;
		//Engine controller OFF
	}
#endif
}

//7.d Based on vehicle speed, the temp of room or engine temp controller is set and engine temp controller or AC is whatever ON or OFF

void vechile_adjustement(unsigned short v_speed, AC *a, short *room_temp,
		Engine_Controller *c, short *engine_temp) {
	if (v_speed == 30) {
		*a = AC_ON;
		*room_temp = (((*room_temp) * 5) / 4) + 1;
#if WITH_ENGINE_TEMP_CONTROLLER
		*c = Controller_ON;
		*engine_temp = (((*engine_temp) * 5) / 4) + 1;
#endif
	}

}

//7.e Display the current vehicle state after applying 7.a to 7.d

void Display_Current_vechile_state(Engine E, unsigned short Speed,
		Room R_sensor, controller C_sensor) {
	if (E == Engine_ON)
		printf("Engine state: ON \n");
	else
		printf("Engine state: OFF \n");

	if (R_sensor.AC_state == AC_ON)
		printf("AC: ON \n");
	else
		printf("AC: OFF \n");

	printf("Vehicle Speed = %d km/hr \n", Speed);
	printf("Room Temperature = %d  Celsius \n", R_sensor.Temp);

	//Bonus: Conditional compilation
#if WITH_ENGINE_TEMP_CONTROLLER

	if (C_sensor.controller_state == Controller_ON)
		printf("Engine Temperature Controller State: ON   \n");
	else
		printf("Engine Temperature Controller State: OFF   \n");

//#else
	//printf("test \n");
#endif

#if WITH_ENGINE_TEMP_CONTROLLER
	printf("Engine Temperature = %d  Celsius \n\n", C_sensor.Temp);
#endif

}

