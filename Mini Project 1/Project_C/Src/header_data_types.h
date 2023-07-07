/*
 * header_data_types.h
 *
 *  Created on: Mar 9, 2023
 *      Author: T.S
 */

#ifndef HEADER_DATA_TYPES_H_
#define HEADER_DATA_TYPES_H_

//User Defined Data types
typedef enum {
	Engine_OFF = 0, Engine_ON = 1
} Engine;

typedef enum {
	AC_OFF = 0, AC_ON = 1
} AC;

typedef enum {
	Controller_OFF = 0, Controller_ON = 1
} Engine_Controller;

typedef struct {
	short Temp;
	AC AC_state;
} Room;

typedef struct {
	short Temp;
	Engine_Controller controller_state;
} controller;

#endif /* HEADER_DATA_TYPES_H_ */
