/*
 * SPI_Master_privet.h
 *
 *  Created on: Apr 13, 2022
 *      Author: INTEL
 */

#ifndef MCAL_SPI_MASTER_SPI_PRIVET_H_
#define MCAL_SPI_MASTER_SPI_PRIVET_H_

#define SPCR_REG *((volatile U8*)0X2D)
#define SPSR_REG *((volatile U8*)0X2E)
#define SPDR_REG *((volatile U8*)0X2F)
/*SPCR_REG*/
#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0
/*SPSR_REG*/
#define SPIF  7
#define WCOL  6
#define SPI2X 0
#endif /* MCAL_SPI_MASTER_SPI_PRIVET_H_ */
