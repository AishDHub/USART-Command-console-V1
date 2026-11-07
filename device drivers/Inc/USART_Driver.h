/*
 * USART_Driver.h
 *
 *  Created on: Nov 1, 2026
 *      Author: Thirisha
 */

#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_

#include<stdint.h>
#include"stm32f103x8.h"

/*USART peripheral clock frequency*/
#define USART_PeriheralClockFreq    8000000U

/*name for each USART*/
typedef enum
{
	USART1_ID,
	USART2_ID,
	USART3_ID

}USART_EN_ID_T;

typedef enum
{
	USART_PARITY_NONE,
	USART_PARITY_EVEN,
	USART_PARITY_ODD

}USART_EN_PARITY_T;

typedef enum
{
	USART_WORDLENGTH_8B,
	USART_WORDLENGTH_16B,
	USART_WORDLENGTH_32B

}USART_EN_WORDLENGTH_T;

typedef enum
{
	USART_STOPBITS_0_5,
	USART_STOPBITS_1,
	USART_STOPBITS_1_5,
	USART_STOPBITS_2

}USART_EN_STOPBIT_T;

/*handle like mode of GPIO same as creating handle for USART as well*/
typedef struct
{
	USART_EN_ID_T usartID;
	uint32_t baudrate;
	USART_EN_WORDLENGTH_T wordlength;
	USART_EN_PARITY_T parity;
	USART_EN_STOPBIT_T stopBits;

}USART_Struct_T;

/*USART functions declarations*/
//in USART_STRUCT_T type we can take a pointer
void USART_Init(USART_Struct_T *usartConfig);
void USART_DeInit(USART_EN_ID_T usartId);
void USART_Transmit(USART_EN_ID_T usartId, uint8_t *data, uint8_t length);// example character array pointer of that array is data, length of the array is length, the usart going to be used is usartId
void USART_Receive(USART_EN_ID_T usartId, uint8_t *data, uint8_t length);

/*support functions*/
void USART_Enable(USART_EN_ID_T usartId);
void USART_Disable(USART_EN_ID_T usartId);
void USART_ConfigureGPIO(USART_EN_ID_T usartId);//for what USART peripheral GPIO has to be configured



#endif /* USART_DRIVER_H_ */
