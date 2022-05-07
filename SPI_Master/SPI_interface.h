/*
 * SPI_Master_interface.h
 *
 *  Created on: Apr 13, 2022
 *      Author: INTEL
 */

#ifndef MCAL_SPI_MASTER_SPI_INTERFACE_H_
#define MCAL_SPI_MASTER_SPI_INTERFACE_H_
/*SPI_Interrupt*/
#define SPI_Interrupt_Enable   0
#define SPI_Interrupt_Disable  1
/*SPI_Data_Order*/
#define SPI_LSB  0
#define SPI_MSB  1
/*SPI_Master_Slave_Select*/
#define SPI_Master 0
#define SPI_Slave  1
/*SPI_Clock_Polarity*/
#define SPI_Idle_High  0
#define SPI_Idle_Low   1
/*SPI_Clock_Phase*/
#define SPI_Sample_Setup  0
#define SPI_Setup_Sample  1
/*SPI_Clock_Rate*/
#define SPI_fosc_4   0
#define SPI_fosc_16  1
#define SPI_fosc_64  2
#define SPI_fosc_128 3
/*SPI_Speed_Bit*/
#define SPI_Normal_Speed 0
#define SPI_Double_Speed 1
void SPI_voidInit(void);

U8   SPI_U8TransmitRecive(U8 Copy_u8Data);



#endif /* MCAL_SPI_MASTER_SPI_INTERFACE_H_ */
