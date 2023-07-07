/*
 * Mini_Project.c
 *
 *  Created on: Mar 9, 2023
 *      Author: T.S
 */

#include <stdio.h>

#include "header.h"
#include "header_data_types.h"

//Bonus
//#define WITH_ENGINE_TEMP_CONTROLLER 1

int main(void) {

	char choice = 'a';	//initial value for specification 1 asking the user
	char a_choice = 'a';//initial value for specification 5 for Sensors Set menu

	char a_5_choice_traffic_light = 'G';	//G OR O OR R

	unsigned short vechile_Speed = 100; //unsigned short since no speed is negative
	Engine engine_state = Engine_ON; //other algorithm to make a greater struct for it and controller

	Room Room_Data = { 35, AC_OFF };
	controller controller_Data = { 90, Controller_OFF };

	/* Data Type used are short not int or float
	 * because should check that CPU contains FPU to support floating operations
	 * and some compilers define int as 2 bytes or 4 bytes so short is used
	 * To get the best use of memory
	 * */

	//short a_5_choice_room_temp = 35;
	//AC AC_state = Room_Data.AC_state;
	//short a_5_choice_engine_temp = 90;
	//Engine_Controller engine_temp_controller = controller_Data.controller_state;

	//if user chose C, Quit the program
	while (choice != 'c') {

		choice = Specification_Ask_the_user();
		//choice = 'a';			//for debug
		if (choice == 'b') {
			printf("Turn off the vehicle engine \n\n");
			//Then return asking the user what he/she wants to do
			continue;
		}
		if (choice == 'a') {
			engine_state = Engine_ON;
			a_choice = Sensor_Set_Menu();
			//a_choice = 'b';		//for debug
		}
		if (a_choice == 'a') {
			//printf("Turn off the engine \n");
			engine_state = Engine_OFF;
			continue;
		}
		//while loop is looping while the engine is on or a_choice != 'a'
		while (engine_state == Engine_ON) {
			switch (a_choice) {
			case 'b':
				printf("Enter the required color: \n");
				fflush(stdout);
				scanf(" %c", &a_5_choice_traffic_light);
				vechile_Speed = Set_Traffic_Light_color(
						a_5_choice_traffic_light);
				vechile_adjustement(vechile_Speed, &(Room_Data.AC_state),
						&Room_Data.Temp, &(controller_Data.controller_state),
						&controller_Data.Temp);
				Display_Current_vechile_state(engine_state, vechile_Speed,
						Room_Data, controller_Data);
				break;
			case 'c':
				printf("Enter the required room temperature: \n");
				fflush(stdout);
				scanf(" %hi", &Room_Data.Temp);
				Room_Data.AC_state = sensor_read_room_temperature(
						&Room_Data.Temp);
				vechile_adjustement(vechile_Speed, &(Room_Data.AC_state),
						&Room_Data.Temp, &(controller_Data.controller_state),
						&controller_Data.Temp);
				Display_Current_vechile_state(engine_state, vechile_Speed,
						Room_Data, controller_Data);
				break;
			case 'd':
				printf("Enter the required engine temperature: \n");
				fflush(stdout);
				scanf(" %hi", &controller_Data.Temp);
				sensor_read_engine_temperature(&controller_Data.Temp,
						&(controller_Data.controller_state));
				vechile_adjustement(vechile_Speed, &(Room_Data.AC_state),
						&Room_Data.Temp, &(controller_Data.controller_state),
						&controller_Data.Temp);

				Display_Current_vechile_state(engine_state, vechile_Speed,
						Room_Data, controller_Data);
				break;
			}
			a_choice = Sensor_Set_Menu();
			if (a_choice == 'a') {
				printf("Turn off the engine \n");
				engine_state = Engine_OFF;
				continue;
			}
		}
		//If chose in menu of requirement 5 to “Turn off the engine”
		//Go to user menu (i.e. Ask the user)
	}
	printf("Quit the System\n");
	return 0;
}
