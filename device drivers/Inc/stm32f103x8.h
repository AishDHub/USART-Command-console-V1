#ifndef STM32F103X8_H
#define STM32F103X8_H

#include <stdint.h>

/*Macros related to all peripherals address,sram,flash
 * Data structures related to peripherals
 * Peripherals bit definition*/

#define FLASH_BASEADDR          0x08000000U
#define FLASH_ENDADDR           0x0801FFFFU
#define SYSTEM_BASEADDR         0x1FFFF000U
#define OPTBYTE_BASEADDR        0x1FFFF800U
#define SRAM_BASEADDR           0x20000000U
#define SRAM_ENDADDR            0x20004FFFU

/*APB & AHB peripherals*/

#define APB1PERIPH_BASEADDR     0x40000000U
#define APB2PERIPH_BASEADDR     0x40010000U
#define AHBPERIPH_BASEADDR      0x40018000U

/*RCC peripherals address*/

#define RCC_BASEADDR            0x40021000U


/*GPIO peripheral address*/

#define GPIOA_BASEADDR          (APB2PERIPH_BASEADDR + 0X0800)
#define GPIOB_BASEADDR          (APB2PERIPH_BASEADDR + 0X0C00)
#define GPIOC_BASEADDR          (APB2PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR          (APB2PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR          (APB2PERIPH_BASEADDR + 0x1800)

/*GPIO structure definitions*/

typedef struct{


	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;


} GPIO_regdef;

/*RCC structure definitions*/

typedef struct{

	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_regdef;

/*GPIO structure Macros for easier accessing like GPIOA -> ODR = 1 means it can directly access GPIOA's ODR address with the help of these type casting of the base address with the structure variable*/

#define GPIOA   ((GPIO_regdef*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_regdef*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_regdef*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_regdef*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_regdef*)GPIOE_BASEADDR)

/*EXTI register structure*/
typedef struct
{
	volatile uint32_t IMR;//Interrupt mask register
	volatile uint32_t EMR;//event mask register
	volatile uint32_t RTSR;//rising trigger selection register
	volatile uint32_t FTSR;//rising trigger selection register
	volatile uint32_t SWIER;//software interrupt event register
	volatile uint32_t PR;//pending register

}EXTI_regdef;

/*Macros related to EXTI peripherals*/
#define EXTI_BASE_ADDR  0x40010400U
#define EXTI            ((EXTI_regdef*)EXTI_BASE_ADDR)

/*EXTI interrupt number*/
#define EXTI0_IRQn           6
#define EXTI1_IRQn           7
#define EXTI2_IRQn           8
#define EXTI3_IRQn           9
#define EXTI4_IRQn           10
#define EXTI9_5IRQn          23
#define EXTI15_10IRQn        40


/* RCC pointer to structure Macros accessing can be like RCC -> CFGR = 1 */

#define RCC     ((RCC_regdef*)RCC_BASEADDR)

/*Macros related to AFIO peripheral registers*/
typedef struct
{
	volatile uint32_t AFIO_EVCR; //Event Control Register
	volatile uint32_t AFIO_MAPR; //AF Remap and Debug I/O Configuration Register
	volatile uint32_t AFIO_EXTICR[4];//external interrupt config register
	volatile uint32_t AFIO_MAPR2;
}AFIO_regdef;

/*AFIO base address*/
#define AFIO_BASE_ADDR 0x40010000U

/*AFIO pointer to structure macro*/
#define AFIO           ((AFIO_regdef*)AFIO_BASE_ADDR)

/*NVIC Related Macros*/
#define NVIC_BASE_ADDR      0xE000E100U


/*this part of defining each registers, without defining each one we can use array instead to make it easier to use an array has one particular function register
// NVIC ISER Registers
#define NVIC_ISER0   ((volatile uint32_t*)0xE000E100U)
#define NVIC_ISER1   ((volatile uint32_t*)0xE000E104U)
#define NVIC_ISER2   ((volatile uint32_t*)0xE000E108U)


// NVIC ICER Registers

#define NVIC_ICER0   ((volatile uint32_t*)0xE000E180U)
#define NVIC_ICER1   ((volatile uint32_t*)0xE000E184U)
#define NVIC_ICER2   ((volatile uint32_t*)0xE000E188U)


//NVIC ISPR Registers
//Interrupt Set Pending

#define NVIC_ISPR0   ((volatile uint32_t*)0xE000E200U)
#define NVIC_ISPR1   ((volatile uint32_t*)0xE000E204U)
#define NVIC_ISPR2   ((volatile uint32_t*)0xE000E208U)


// NVIC ICPR Registers
// Interrupt Clear Pending

#define NVIC_ICPR0   ((volatile uint32_t*)0xE000E280U)
#define NVIC_ICPR1   ((volatile uint32_t*)0xE000E284U)
#define NVIC_ICPR2   ((volatile uint32_t*)0xE000E288U)/


//NVIC IABR Registers
// Interrupt Active Bit

#define NVIC_IABR0   ((volatile uint32_t*)0xE000E300U)
#define NVIC_IABR1   ((volatile uint32_t*)0xE000E304U)
#define NVIC_IABR2   ((volatile uint32_t*)0xE000E308U)


defining as arrays for easier logic way access*/

#define NVIC_ISER ((volatile uint32_t*)0xE000E100)
#define NVIC_ICER ((volatile uint32_t*)0xE000E180)
#define NVIC_ISPR ((volatile uint32_t*)0xE000E200)
#define NVIC_ICPR ((volatile uint32_t*)0xE000E280)
#define NVIC_IABR ((volatile uint32_t*)0xE000E300)

/* NVIC PR Registers */
#define NVIC_IPRx_BASE_ADDR ((volatile uint32_t*)0xE000E400U)

/*NVIC STIR Registers*/
#define NVIC_STIR_BASE_ADDR ((volatile uint8_t*)0xE000EE00U)

/*USART peripheral related macros*/
#define  USART1_BASE_ADDR  0x40013800U
#define  USART2_BASE_ADDR  0x40004400U
#define  USART3_BASE_ADDR  0x40004800U

/*Register Structure for USARTx peripheral*/
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;

}USART_regdef_T;

/*Pointers to register struct for all USART peripheral*/
/*this pointer is for easy accessing of the register for example if i want to access the SR register of USART3 then i can simply do USART3->SR*/

#define USART1            ((USART_regdef_T*)USART1_BASE_ADDR)
#define USART2            ((USART_regdef_T*)USART2_BASE_ADDR)
#define USART3            ((USART_regdef_T*)USART3_BASE_ADDR)

/*USARTx status register related macros*/
#define USARTx_SR_TXE     (1 << 7)
#define USARTx_SR_TC      (1 << 6)
#define USARTx_SR_RXNE     (1 << 5)

/*USARTx control register 1 related macros*/
#define USARTx_CR1_UE        (1 << 13)
#define USARTx_CR1_TXEIE     (1 << 7)
#define USARTx_CR1_TCIE      (1 << 6)
#define USARTx_CR1_RXNEIE    (1 << 5)
#define USARTx_CR1_TE        (1 << 3)
#define USARTx_CR1_RE        (1 << 2)

/*USARTx CR2 register related macros*/

#define USART_CR2_STOPBIT1    (0b00 << 12)
#define USART_CR2_STOPBIT0_5  (0b01 << 12)
#define USART_CR2_STOPBIT1_5  (0b11 << 12)
#define USART_CR2_STOPBIT2    (0b10 << 12)


#endif
