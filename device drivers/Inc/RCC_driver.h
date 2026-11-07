#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include <stm32f103x8.h>

void RCC_Enable_GPIO(GPIO_regdef *port);
void RCC_Disable_GPIO(GPIO_regdef *port);
void RCC_config_HSE_SystemClock(void);
#endif
