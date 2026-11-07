#include<RCC_driver.h>

/*enables the GPIO peripherals clock for a particular GPIO port*/
void RCC_Enable_GPIO(GPIO_regdef *port){

	if(port == GPIOA){
		RCC->APB2ENR |= (1 << 2);
	}

	else if(port == GPIOB){
		RCC->APB2ENR |= (1 << 3);
	}

	else if(port == GPIOC){
		RCC->APB2ENR |= (1 << 4);
	}

	else if(port == GPIOD){
		RCC->APB2ENR |= (1 << 5);
	}

	else if(port == GPIOE){
		RCC->APB2ENR |= (1 << 6);
	}

}

/*disables the GPIO peripherals clock for a particular GPIO port*/
void RCC_Disable_GPIO(GPIO_regdef *port){

	if(port == GPIOA){
			RCC->APB2ENR &= ~(1 << 2);
		}

		else if(port == GPIOB){
			RCC->APB2ENR &= ~(1 << 3);
		}

		else if(port == GPIOC){
			RCC->APB2ENR &= ~(1 << 4);
		}

		else if(port == GPIOD){
			RCC->APB2ENR &= ~(1 << 5);
		}

		else if(port == GPIOE){
			RCC->APB2ENR &= ~(1 << 6);
		}

}

void RCC_config_HSE_SystemClock(void)
{
    //enable HSE Clock
	RCC->CR |= (1 << 16);

	//wait until HSE is ready
	while(!(RCC->CR & (1<<17)));

	//select HSE as System clock
	RCC->CFGR &= ~(0b11 << 0);//OFF before enabling
	RCC->CFGR |=  (0b01 << 0);

	//wait until System clock is set to HSE
	while(!(RCC->CFGR & (0b01 << 2)));

}
