/*
 * USART_Driver.c
 *
 *  Created on: Nov 1, 2026
 *      Author: Thirisha
 */

#include "USART_Driver.h"
#include "GPIO_driver.h"
#include "RCC_driver.h"

/*This function initializes the USART peripheral based on the USARTID passed through the config struct*/
void USART_Init(USART_Struct_T *usartConfig){

	/*configure the GPIO peripheral for the given USART peripherals*/
	USART_ConfigureGPIO(usartConfig -> usartID);

    float UsartDiv,fraction;
    uint32_t Mantissa;

	if(usartConfig -> usartID == USART1_ID)
	{

		/*Enable the peripheral clock*/
		RCC ->APB2ENR |= (1 << 14);//Making 14th register 1 to enable clock

		/*Set the word length*/
	    if(usartConfig -> wordlength == USART_WORDLENGTH_8B){

	    	USART1->CR1 &= ~(1 << 12);
	    }

	    else{
	    	USART1->CR1 |= ~(1 << 12);//9 bits word length configuration
	    }
	    /*Set the stop bits*/
	    /*to clear bit then enabling to avoid bit manipulation unintended results*/

	    USART1->CR2 &= ~(0b11 << 12);//bit cleared as this particular bit causes issues

	    /*enabling stop bits*/
	    if(usartConfig->stopBits == USART_STOPBITS_0_5)
	    	USART1->CR2 |= USART_CR2_STOPBIT0_5;
	    else if(usartConfig->stopBits == USART_STOPBITS_1)
	    	USART1->CR2 |= USART_CR2_STOPBIT1;
	    else if(usartConfig->stopBits == USART_STOPBITS_1_5)
	   	    USART1->CR2 |= USART_CR2_STOPBIT1_5;
	    else if(usartConfig->stopBits == USART_STOPBITS_2)
	   	    USART1->CR2 |= USART_CR2_STOPBIT2;

	    /*Set the parity*/
	    USART1->CR1 &= ~(1 << 9);//indication OFF condition of parity means that is EVEN(as 0 is EVEN)
	    if(usartConfig->parity == USART_PARITY_EVEN)
	    {
	    	USART1->CR1 &= ~(1 << 9);
	    }
	    else/*ODD*/
	    {
	    	USART1->CR1 |= (1 << 9);
	    }
	    /*Set the baud rate*/
	    /*here over8 not there so the formula become baud rate = FCLK/(8 * (2 - 0)*USARTDIV) rather than baud rate = FCLK/(8 * (2 - 1)*USARTDIV)*/


        UsartDiv = (USART_PeriheralClockFreq / (16 * (usartConfig ->baudrate)));
        Mantissa = (uint32_t)UsartDiv;//type casting to obtain the floating into integer value
        fraction = UsartDiv - Mantissa;

        /*integer will always round to lower end ex.1.9 as 1 in order to bypass this error add up by 0.5f always*/
        USART1->BRR = (Mantissa << 4) | (uint8_t)(fraction * 16 + 0.5f);//round to nearest by 0.5f addition

	    /*Enable transmitter or receiver*/
	    /*Enable USART*/
	    USART1 -> CR1 |= (USARTx_CR1_TE) | (USARTx_CR1_RE) | (USARTx_CR1_UE);

	}

	else if(usartConfig -> usartID == USART2_ID){

		/*Enable the peripheral clock*/
		RCC ->APB1ENR |= (1 << 17);

		/*Set the word length*/
	    if(usartConfig -> wordlength == USART_WORDLENGTH_8B){

	    	USART2->CR1 &= ~(1 << 12);
	    }

	    else{
	    	USART2->CR1 |= ~(1 << 12);//9 bits word length configuration
	    }
	    /*Set the stop bits*/
	    /*to clear bit then enabling to avoid bit manipulation unintended results*/
        USART2->CR2 &= ~(0b11 << 12);//bit cleared as this particular bit causes issues

	    /*enabling stop bits*/
	    if(usartConfig->stopBits == USART_STOPBITS_0_5)
	    	USART2->CR2 |= USART_CR2_STOPBIT0_5;
	    else if(usartConfig->stopBits == USART_STOPBITS_1)
	    	USART2->CR2 |= USART_CR2_STOPBIT1;
	    else if(usartConfig->stopBits == USART_STOPBITS_1_5)
	   	    USART2->CR2 |= USART_CR2_STOPBIT1_5;
	    else if(usartConfig->stopBits == USART_STOPBITS_2)
	   	    USART2->CR2 |= USART_CR2_STOPBIT2;

	    /*Set the parity*/
	    USART2->CR1 &= ~(1 << 9);//indication OFF condition of parity means that is EVEN(as 0 is EVEN)
	    if(usartConfig->parity == USART_PARITY_EVEN)
	    {
	    	USART2->CR1 &= ~(1 << 9);
	    }
	    else/*ODD*/
	    {
	    	USART2->CR1 |= (1 << 9);
	    }
	    /*Set the baud rate*/
        UsartDiv = (USART_PeriheralClockFreq / (16 * (usartConfig ->baudrate)));
        Mantissa = (uint32_t)UsartDiv;
        fraction = UsartDiv - Mantissa;

        USART2->BRR = (Mantissa << 4) | (uint8_t)(fraction * 16 + 0.5f);

	    /*Enable transmitter or receiver*/
	    /*Enable USART*/
	    USART2 -> CR1 |= (USARTx_CR1_TE) | (USARTx_CR1_RE) | (USARTx_CR1_UE);

	}
	else if(usartConfig -> usartID == USART3_ID){

		/*Enable the peripheral clock*/
		RCC ->APB1ENR |= (1 << 18);

		/*Set the word length*/
	    if(usartConfig -> wordlength == USART_WORDLENGTH_8B)
	    {

	    	USART3->CR1 &= ~(1 << 12);
	    }

	    else
	    {
	    	USART3->CR1 |= ~(1 << 12);//9 bits word length configuration
	    }

	    /*Set the stop bits*/
	    /*to clear bit then enabling to avoid bit manipulation unintended results*/
	    USART3->CR2 &= ~(0b11 << 12);//bit cleared as this particular bit causes issues

	    /*enabling stop bits*/
	    if(usartConfig->stopBits == USART_STOPBITS_0_5)
	    	USART3->CR2 |= USART_CR2_STOPBIT0_5;
	    else if(usartConfig->stopBits == USART_STOPBITS_1)
	    	USART3->CR2 |= USART_CR2_STOPBIT1;
	    else if(usartConfig->stopBits == USART_STOPBITS_1_5)
	   	    USART3->CR2 |= USART_CR2_STOPBIT1_5;
	    else if(usartConfig->stopBits == USART_STOPBITS_2)
	   	    USART3->CR2 |= USART_CR2_STOPBIT2;

	    /*Set the parity*/
	    USART3->CR1 &= ~(1 << 9);//indication OFF condition of parity means that is EVEN(as 0 is EVEN)
	    if(usartConfig->parity == USART_PARITY_EVEN)
	    {
	    	USART3->CR1 &= ~(1 << 9);
	    }
	    else/*ODD*/
	    {
	    	USART3->CR1 |= (1 << 9);
	    }

	    /*Set the baud rate*/
	    UsartDiv = (USART_PeriheralClockFreq / (16 * (usartConfig ->baudrate)));
        Mantissa = (uint32_t)UsartDiv;
        fraction = UsartDiv - Mantissa;

        USART3->BRR = (Mantissa << 4) | (uint8_t)(fraction * 16 + 0.5f);

	    /*Enable transmitter or receiver*/
	    /*Enable USART*/
	    USART3 -> CR1 |= (USARTx_CR1_TE) | (USARTx_CR1_RE) | (USARTx_CR1_UE);

	}

}

/*This function initializes the USART peripheral based on the USARTID passed as a parameter*/
void USART_DeInit(USART_EN_ID_T usartId)
{

	if(usartId == USART1_ID){

		/*Disable USART1 through CR1 Register*/
		USART1->CR1 &= ~(USARTx_CR1_UE);

		/*Disable USAERT1 Peripheral clock through APB RCC Register*/
		RCC ->APB2ENR &= ~(1 << 14);
	}
	else if(usartId == USART2_ID){

		/*Disable USART1 through CR1 Register*/
		USART2->CR1 &= ~(USARTx_CR1_UE);

		/*Disable USAERT1 Peripheral clock through APB RCC Register*/
		RCC ->APB1ENR &= ~(1 << 17);
	}
	else if(usartId == USART3_ID){

		/*Disable USART1 through CR1 Register*/
		USART3->CR1 &= ~(USARTx_CR1_UE);

		/*Disable USAERT1 Peripheral clock through APB RCC Register*/
		RCC ->APB1ENR &= ~(1 << 18);
	}

}

/*this function transmits the data of length passed as parameter*/
void USART_Transmit(USART_EN_ID_T usartId, uint8_t *data, uint8_t length){

	if(usartId == USART1_ID)
	{
		for(uint32_t i=0;i<length;i++)

		{
			while(!(USART1->SR & USARTx_SR_TXE));// default value of SR is 1 if TXE is 1 then data can be transfered so it enter in loop as the AND operation produces 1

					//transmit the data
					//checking first element of the data
					USART1->DR = data[i] & 0xff;//no need for 0xff for good practice added
	     }

		     //check the TC flag for theTransmission complete
			 while(!(USART1->SR & USARTx_SR_TC));//loop waits until transmission finishes(after transmission it becomes 1)

      }

	else if(usartId == USART2_ID)
	{
		for(uint32_t i=0;i<length;i++)

		{

			while(!(USART2->SR & USARTx_SR_TXE));// default value of SR is 1 if TXE is 1 then data can be transfered so it enter in loop as the AND operation produces 1

					//transmit the data
					//checking first element of the data
					USART2->DR = data[i] & 0xff;//no need for 0xff for good practice added
	     }

		     //check the TC flag for theTransmission complete
			 while(!(USART2->SR & USARTx_SR_TC));//loop waits until transmission finishes(after transmission it becomes 1)

      }

	else if(usartId == USART3_ID)
	{
		for(uint32_t i=0;i<length;i++)

		{
			while(!(USART3->SR & USARTx_SR_TXE));// default value of SR is 1 if TXE is 1 then data can be transfered so it enter in loop as the AND operation produces 1

					//transmit the data
					//checking first element of the data
					USART3->DR = data[i] & 0xff;//no need for 0xff for good practice added
	     }

		     //check the TC flag for theTransmission complete
			 while(!(USART3->SR & USARTx_SR_TC));//loop waits until transmission finishes(after transmission it becomes 1)

      }

}

/*this function receives the data through the data buffer of length passed as parameter*/
void USART_Receive(USART_EN_ID_T usartId, uint8_t *data, uint8_t length)
{
	if(usartId == USART1_ID){

		//buffer to read data(buffer-block of memory used to temporarily hold data while it’s being transferred between two parts of a system)
		for(uint32_t i=0; i<length; i++)
		{
			   //check the RXNE flag in SR(to find any data arrived or not if it is 1 then data arrived)
				while(!(USART1->SR & USARTx_SR_RXNE));

				//Read the DR
				data[i] = USART1->DR & 0xFF;
		}
	}

	else if(usartId == USART2_ID){

		//buffer to read data(buffer-block of memory used to temporarily hold data while it’s being transferred between two parts of a system)
		for(uint32_t i=0; i<length; i++)
		{
			   //check the RXNE flag in SR(to find any data arrived or not if it is 1 then data arrived)
				while(!(USART2->SR & USARTx_SR_RXNE));

				//Read the DR
				data[i] = USART2->DR & 0xFF;
		}
	}

	else if(usartId == USART3_ID){

		//buffer to read data(buffer-block of memory used to temporarily hold data while it’s being transferred between two parts of a system)
		for(uint32_t i=0; i<length; i++)
		{
			   //check the RXNE flag in SR(to find any data arrived or not if it is 1 then data arrived)
				while(!(USART3->SR & USARTx_SR_RXNE));

				//Read the DR
				data[i] = USART3->DR & 0xFF;
		}
	}


}

/*this function enables the USART for given USART peripherals*/
void USART_Enable(USART_EN_ID_T usartId)
{

	if(usartId == USART1_ID)
	{
		USART1 -> CR1 |= USARTx_CR1_UE;
	}
	else if(usartId == USART2_ID)
	{
		USART2 -> CR1 |= USARTx_CR1_UE;
	}
	else if(usartId == USART3_ID)
	{
		USART3 -> CR1 |= USARTx_CR1_UE;
	}

}

/*this function disables the USART for given USART peripherals*/
void USART_Disable(USART_EN_ID_T usartId)
{

	if(usartId == USART1_ID)
	{
		USART1 -> CR1 &= ~USARTx_CR1_UE;
	}
	else if(usartId == USART2_ID)
	{
		USART2 -> CR1 &= ~USARTx_CR1_UE;
	}
	else if(usartId == USART3_ID)
	{
		USART3 -> CR1 &= ~USARTx_CR1_UE;
	}

}

/*this function configures the USART GPIO peripheral for the given USART ID*/
void USART_ConfigureGPIO(USART_EN_ID_T usartId){

	GPIO_PINCONFIG_T GpioUsartPinConfig = {

			.pin = 0,
			.mode = GPIO_AF_PP_OUT_MODE_50,
			.alternatefunc = 0
	};

	/*configure the GPIO for USART1*/
	if(usartId == USART1_ID){

		/*PA9 -Tx and PA10 -Rx*/
		GpioUsartPinConfig.pin = 9;
		GPIO_Init(GPIOA, &GpioUsartPinConfig);

		GpioUsartPinConfig.pin = 10;
		GPIO_Init(GPIOA, &GpioUsartPinConfig);
		RCC_Enable_GPIO(GPIOA);

	}

	/*configure the GPIO for USART2*/
	else if(usartId == USART2_ID){

		/*PA2 -Tx and PA3 -Rx*/
		GpioUsartPinConfig.pin = 2;
		GPIO_Init(GPIOA, &GpioUsartPinConfig);

		GpioUsartPinConfig.pin = 3;
	    GPIO_Init(GPIOA, &GpioUsartPinConfig);
	    RCC_Enable_GPIO(GPIOA);

	}

	/*configure the GPIO for USART3*/
	else if(usartId == USART3_ID){

		/*PB10 -Tx and PB11 - Rx*/
		GpioUsartPinConfig.pin = 10;
		GPIO_Init(GPIOB, &GpioUsartPinConfig);

		GpioUsartPinConfig.pin = 11;
		GPIO_Init(GPIOB, &GpioUsartPinConfig);
		RCC_Enable_GPIO(GPIOC);

	}


}

