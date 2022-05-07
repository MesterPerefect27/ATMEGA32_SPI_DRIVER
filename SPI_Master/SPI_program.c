/*
 * SPI_Master_program.c
 *
 *  Created on: Apr 13, 2022
 *      Author: INTEL
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"SPI_config.h"
#include"SPI_interface.h"
#include"SPI_privet.h"
#include"../../MCAL/DIO/DIO_interface.h"
void SPI_voidInit(void)
{
#if SPI_Master_Slave_Select==SPI_Master
	DIO_enumSetPinDirection(DIO_PIN4,DIO_PORTB,DIO_OUTPUT);//SS
	DIO_enumSetPinDirection(DIO_PIN5,DIO_PORTB,DIO_OUTPUT);//MOSI
	DIO_enumSetPinDirection(DIO_PIN6,DIO_PORTB,DIO_INPUT);//MISO
	DIO_enumSetPinDirection(DIO_PIN7,DIO_PORTB,DIO_OUTPUT);//SCK
#elif SPI_Master_Slave_Select==SPI_Slave
	DIO_enumSetPinDirection(DIO_PIN4,DIO_PORTB,DIO_INPUT);//SS
	DIO_enumSetPinDirection(DIO_PIN5,DIO_PORTB,DIO_INPUT);//MOSI
	DIO_enumSetPinDirection(DIO_PIN6,DIO_PORTB,DIO_OUTPUT);//MISO
	DIO_enumSetPinDirection(DIO_PIN7,DIO_PORTB,DIO_INPUT);//SCK
#endif

#if SPI_Interrupt==SPI_Interrupt_Enable
	SPCR_REG|=(1<<SPIE);
#elif SPI_Interrupt==SPI_Interrupt_Disable
	SPCR_REG&=~(1<<SPIE);
#endif


#if SPI_Data_Order==SPI_LSB
	SPCR_REG|=(1<<DORD);
#elif SPI_Data_Order==SPI_MSB
	SPCR_REG&=~(1<<DORD);
#endif


#if SPI_Master_Slave_Select==SPI_Master
	SPCR_REG|=(1<<MSTR);
#elif SPI_Master_Slave_Select==SPI_Slave
	SPCR_REG&=~(1<<MSTR);
#endif


#if SPI_Clock_Polarity==SPI_Idle_High
	SPCR_REG|=(1<<CPOL);
#elif SPI_Clock_Polarity==SPI_Idle_Low
	SPCR_REG&=~(1<<CPOL);
#endif

#if SPI_Clock_Phase==SPI_Sample_Setup
	SPCR_REG&=~(1<<CPHA);
#elif SPI_Clock_Phase==SPI_Setup_Sample
	SPCR_REG|=(1<<CPHA);
#endif

#if SPI_Master_Slave_Select==SPI_Master
#if SPI_Clock_Rate>=SPI_fosc_4&&SPI_Clock_Rate<=SPI_fosc_128
	SPCR_REG|=SPI_Clock_Rate;
#endif
#endif


#if SPI_Speed_Bit==SPI_Double_Speed
	SPSR_REG|=(1<<SPI2X);
#elif SPI_Speed_Bit==SPI_Normal_Speed
	SPSR_REG&=~(1<<SPI2X);
#endif
	SPCR_REG|=(1<<SPE);//Enable SPI
	SPSR_REG=0;
}
U8   SPI_U8TransmitRecive(U8 Copy_u8Data)
{
#if SPI_Master_Slave_Select==SPI_Master
	DIO_enumSetPinValue(DIO_PIN4,DIO_PORTB,DIO_LOW);//Select_Slave
	SPDR_REG=Copy_u8Data;
	while(!GET_BIT(SPSR_REG,SPIF));
	DIO_enumSetPinValue(DIO_PIN4,DIO_PORTB,DIO_HIGH);
	return SPDR_REG;
#elif SPI_Master_Slave_Select==SPI_Slave
	SPDR_REG=Copy_u8Data;
	while(GET_BIT(SPSR_REG,SPIF)==0);
	return SPDR_REG;
#endif
}
