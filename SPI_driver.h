/*
 * SPI_driver.h
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

void SPI_init(void);
void SPI_send(unsigned char data);

unsigned char received_spi;

#endif /* SPI_DRIVER_H_ */
