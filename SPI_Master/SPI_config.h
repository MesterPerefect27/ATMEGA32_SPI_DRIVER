/*
 * SPI_Master_config.h
 *
 *  Created on: Apr 13, 2022
 *      Author: INTEL
 */

#ifndef MCAL_SPI_MASTER_SPI_CONFIG_H_
#define MCAL_SPI_MASTER_SPI_CONFIG_H_
/*option
 * SPI_Interrupt_Enable
 * SPI_Interrupt_Disable*/
#define SPI_Interrupt SPI_Interrupt_Disable
/*option
 * SPI_LSB
 * SPI_MSB*/
#define SPI_Data_Order SPI_LSB
/*option
 * SPI_Master
 * SPI_Slave*/
#define SPI_Master_Slave_Select SPI_Master
/*option
 *  SPI_Idle_High
 *  SPI_Idle_Low*/
#define SPI_Clock_Polarity  SPI_Idle_Low
/*option
 * SPI_Sample_Setup
 * SPI_Setup_Sample*/
#define SPI_Clock_Phase SPI_Setup_Sample
/*option
 * SPI_fosc_4
 * SPI_fosc_16
 * SPI_fosc_64
 * SPI_fosc_128*/
#define SPI_Clock_Rate SPI_fosc_16
/*option
 * SPI_Normal_Speed
 * SPI_Double_Speed*/
#define SPI_Speed_Bit SPI_Normal_Speed
#endif /* MCAL_SPI_MASTER_SPI_CONFIG_H_ */
