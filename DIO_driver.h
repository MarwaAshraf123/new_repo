/*
 * DIO_driver.h
 *
 *  Created on: Dec 10, 2020
 *      Author: PC
 */

#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

#include"macros.h"


#define myDDRC*((volatile unsigned char*)(0x34))
#define PORTC*((volatile unsigned char*)(0x35))



void DIO_makeInput(char *port,unsigned char pin);

void DIO_makeOutput(char *port,unsigned char pin);






#endif /* DIO_DRIVER_H_ */
