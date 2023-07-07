/*
 * header.h
 *
 *  Created on: Mar 9, 2023
 *      Author: T.S
 */

#ifndef HEADER_H_
#define HEADER_H_

#include "header_data_types.h"

//Bonus
//#define WITH_ENGINE_TEMP_CONTROLLER 1
//Functions Prototype
char Specification_Ask_the_user(void);
char Sensor_Set_Menu();
int Set_Traffic_Light_color(char c);
int sensor_read_room_temperature(short *temperature);
void sensor_read_engine_temperature(short *compression,
		Engine_Controller *engineController);
void vechile_adjustement(unsigned short v_speed, AC *ac, short *room_temp,
		Engine_Controller *engineController, short *engine_temp);
void Display_Current_vechile_state(Engine E, unsigned short Speed, Room x,
		controller y);

#endif /* HEADER_H_ */
