/*
 * SPI_driver.c
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */



#include<stdlib.h>
#include"avr/io.h"
#include"avr/interrupt.h"
#include"avr/delay.h"
#include "SPI_config.h"
#include"SPI_driver.h"
#include"macros.h"

extern unsigned char received_spi;

void SPI_init(void){


	DDRB |=(1<<6);
	DDRB &=~(1<<4);
	DDRB &=~(1<<5);
	DDRB &=~(1<<7);

	SPCR |=(1<<SPE) |(1<<DORD)|(1<<CPOL)|(1<<SPIE);

//#if INTERRUPT == ENABLED
	//SPCR |=(1<<SPIE);
	sei();
//#endif

}

void SPI_send(unsigned char data)
{
	PORTB &=~(1<<4);
	SPDR=data;
	_delay_ms(10);
	PORTB |=(1<<4);
}
ISR(SPI_STC_vect)
{
	received_spi=SPDR;

}
