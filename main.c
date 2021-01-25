/*
 * main.c
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */
#include "stdlib.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include"avr/delay.h"
#include "SPI_driver.h"
#include "SPI_config.h"
#include "macros.h"


extern unsigned char received_spi;
int main(){
	SPI_init();
	setBit(DDRA,0);
	setBit(DDRA,1);
	//clearBit(PORTA,1);
    DDRD=0xFF;

	while (1){
		SPI_send(0xFF);
	    if(received_spi == 0x31){
	    			setBit(PORTA,0);
	    		}
	    		if(received_spi == 0x32){
	    			clearBit(PORTA,0);
	    		}
	    	    if(received_spi == 0x33){
	    	    			setBit(PORTA,1);
	    	    		}
	    	    		if(received_spi == 0x34){
	    	    			clearBit(PORTA,1);
	    	    		}
		PORTD=received_spi;

	}

	return 0;
}
