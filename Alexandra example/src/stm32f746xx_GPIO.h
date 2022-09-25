#ifndef stm32f746xx_GPIO_H
#define stm32f746xx_GPIO_H

#include <stdint.h>

//䮪󬥭򠒥ference manual RM0090

//񲰠281 ﳭ겠8.4.1
struct GPIOx_MODER_BITS
{
	uint32_t MODER0 	: 2;
	uint32_t MODER1 	: 2;
	uint32_t MODER2 	: 2;
	uint32_t MODER3 	: 2;
	uint32_t MODER4 	: 2;
	uint32_t MODER5 	: 2;
	uint32_t MODER6 	: 2;
	uint32_t MODER7 	: 2;
	uint32_t MODER8 	: 2;
	uint32_t MODER9 	: 2;
	uint32_t MODER10 	: 2;
	uint32_t MODER11 	: 2;
	uint32_t MODER12 	: 2;
	uint32_t MODER13 	: 2;
	uint32_t MODER14 	: 2;
	uint32_t MODER15 	: 2;
	 
	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_MODER
{
	uint32_t 									ALL;
	struct GPIOx_MODER_BITS 	BIT;
};

//񲰠281 ﳭ겠8.4.2
struct GPIOx_OTYPER_BITS
{
	uint32_t OT0 		: 1;
	uint32_t OT1 		: 1;
	uint32_t OT2 		: 1;
	uint32_t OT3 		: 1;
	uint32_t OT4 		: 1;
	uint32_t OT5 		: 1;
	uint32_t OT6 		: 1;
	uint32_t OT7 		: 1;
	uint32_t OT8 		: 1;
	uint32_t OT9 		: 1;
	uint32_t OT10 	: 1;
	uint32_t OT11 	: 1;
	uint32_t OT12 	: 1;
	uint32_t OT13 	: 1;
	uint32_t OT14 	: 1;
	uint32_t OT15 	: 1;
	uint32_t res 		: 16;

	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_OTYPER
{
	uint32_t 									ALL;
	struct GPIOx_OTYPER_BITS 	BIT;
};

//񲰠282 ﳭ겠8.3.4 
struct GPIOx_OSPEEDR_BITS
{
	uint32_t OSPEEDR0 	: 2;
	uint32_t OSPEEDR1 	: 2;
	uint32_t OSPEEDR2 	: 2;
	uint32_t OSPEEDR3 	: 2;
	uint32_t OSPEEDR4 	: 2;
	uint32_t OSPEEDR5 	: 2;
	uint32_t OSPEEDR6 	: 2;
	uint32_t OSPEEDR7 	: 2;
	uint32_t OSPEEDR8 	: 2;
	uint32_t OSPEEDR9 	: 2;
	uint32_t OSPEEDR10 	: 2;
	uint32_t OSPEEDR11 	: 2;
	uint32_t OSPEEDR12 	: 2;
	uint32_t OSPEEDR13 	: 2;
	uint32_t OSPEEDR14 	: 2;
	uint32_t OSPEEDR15 	: 2;

	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_OSPEEDR
{
	uint32_t 										ALL;
	struct GPIOx_OSPEEDR_BITS 	BIT;
};

//񲰠282 ﳭ겠8.3.4
struct GPIOx_PUPDR_BITS
{
	uint32_t PUPDR0 	: 2;
	uint32_t PUPDR1 	: 2;
	uint32_t PUPDR2 	: 2;
	uint32_t PUPDR3 	: 2;
	uint32_t PUPDR4 	: 2;
	uint32_t PUPDR5 	: 2;
	uint32_t PUPDR6 	: 2;
	uint32_t PUPDR7 	: 2;
	uint32_t PUPDR8 	: 2;
	uint32_t PUPDR9 	: 2;
	uint32_t PUPDR10 	: 2;
	uint32_t PUPDR11 	: 2;
	uint32_t PUPDR12 	: 2;
	uint32_t PUPDR13 	: 2;
	uint32_t PUPDR14 	: 2;
	uint32_t PUPDR15 	: 2;

	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_PUPDR
{
	uint32_t 									ALL;
	struct GPIOx_PUPDR_BITS 	BIT;
};

//񲰠283 ﳭ겠8.4.5
struct GPIOx_IDR_BITS
{
	uint32_t IDR0 	: 1;
	uint32_t IDR1 	: 1;
	uint32_t IDR2 	: 1;
	uint32_t IDR3 	: 1;
	uint32_t IDR4 	: 1;
	uint32_t IDR5 	: 1;
	uint32_t IDR6 	: 1;
	uint32_t IDR7 	: 1;
	uint32_t IDR8 	: 1;
	uint32_t IDR9 	: 1;
	uint32_t IDR10 	: 1;
	uint32_t IDR11 	: 1;
	uint32_t IDR12 	: 1;
	uint32_t IDR13 	: 1;
	uint32_t IDR14 	: 1;
	uint32_t IDR15 	: 1;
	uint32_t res 		: 16;
	
	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_IDR
{
	uint32_t 							ALL;
	struct GPIOx_IDR_BITS BIT;
};

//񲰠283 ﳭ겠8.4.6
struct GPIOx_ODR_BITS
{
	uint32_t ODR0 	: 1;
	uint32_t ODR1 	: 1;
	uint32_t ODR2 	: 1;
	uint32_t ODR3 	: 1;
	uint32_t ODR4 	: 1;
	uint32_t ODR5 	: 1;
	uint32_t ODR6 	: 1;
	uint32_t ODR7 	: 1;
	uint32_t ODR8 	: 1;
	uint32_t ODR9 	: 1;
	uint32_t ODR10 	: 1;
	uint32_t ODR11 	: 1;
	uint32_t ODR12 	: 1;
	uint32_t ODR13 	: 1;
	uint32_t ODR14 	: 1;
	uint32_t ODR15 	: 1;
	uint32_t res 		: 16;
	
	//ꮭ򰮫ü🰠񳬬࠳2 
};

union GPIOx_ODR
{
	uint32_t ALL;
	struct GPIOx_ODR_BITS BIT;
};

//񲰠284 ﳭ겠8.4.7 
struct GPIOx_BSRR_BITS
{
	uint32_t BS0 	: 1;
	uint32_t BS1 	: 1;
	uint32_t BS2 	: 1;
	uint32_t BS3 	: 1;
	uint32_t BS4 	: 1;
	uint32_t BS5 	: 1;
	uint32_t BS6 	: 1;
	uint32_t BS7 	: 1;
	uint32_t BS8 	: 1;
	uint32_t BS9 	: 1;
	uint32_t BS10 : 1;
	uint32_t BS11 : 1;
	uint32_t BS12 : 1;
	uint32_t BS13 : 1;
	uint32_t BS14 : 1;
	uint32_t BS15 : 1;
	uint32_t BR0 	: 1;
	uint32_t BR1 	: 1;
	uint32_t BR2 	: 1;
	uint32_t BR3 	: 1;
	uint32_t BR4 	: 1;
	uint32_t BR5 	: 1;
	uint32_t BR6 	: 1;
	uint32_t BR7 	: 1;
	uint32_t BR8 	: 1;
	uint32_t BR9 	: 1;
	uint32_t BR10 : 1;
	uint32_t BR11 : 1;
	uint32_t BR12 : 1;
	uint32_t BR13 : 1;
	uint32_t BR14 : 1;
	uint32_t BR15 : 1;

	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_BSRR
{
	uint32_t 								ALL;
	struct GPIOx_BSRR_BITS 	BIT;
};

//񲰠284 ﳭ겠8.4.8 
struct GPIOx_LCKR_BITS
{

	uint32_t LCK0 	: 1;
	uint32_t LCK1 	: 1;
	uint32_t LCK2 	: 1;
	uint32_t LCK3 	: 1;
	uint32_t LCK4 	: 1;
	uint32_t LCK5 	: 1;
	uint32_t LCK6 	: 1;
	uint32_t LCK7 	: 1;
	uint32_t LCK8 	: 1;
	uint32_t LCK9 	: 1;
	uint32_t LCK10 	: 1;
	uint32_t LCK11 	: 1;
	uint32_t LCK12 	: 1;
	uint32_t LCK13 	: 1;
	uint32_t LCK14 	: 1;
	uint32_t LCK15 	: 1;
	uint32_t LCKK 	: 1;
	uint32_t res		: 15;

	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_LCKR
{
	uint32_t 								ALL;
	struct GPIOx_LCKR_BITS 	BIT;
};

//񲰠285 ﳭ겠8.4.9 
struct GPIOx_AFRL_BITS
{
	uint32_t AFRL0 : 4;
	uint32_t AFRL1 : 4;
	uint32_t AFRL2 : 4;
	uint32_t AFRL3 : 4;
	uint32_t AFRL4 : 4;
	uint32_t AFRL5 : 4;
	uint32_t AFRL6 : 4;
	uint32_t AFRL7 : 4;

	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_AFRL
{
	uint32_t 								ALL;
	struct GPIOx_AFRL_BITS 	BIT;
};

//񲰠286 ﳭ겠8.4.10
struct GPIOx_AFRH_BITS
{
	uint32_t AFRH8 	: 4;
	uint32_t AFRH9 	: 4;
	uint32_t AFRH10 : 4;
	uint32_t AFRH11 : 4;
	uint32_t AFRH12 : 4;
	uint32_t AFRH13 : 4;
	uint32_t AFRH14 : 4;
	uint32_t AFRH15 : 4;

	//ꮭ򰮫ü🰠񳬬࠳2
};

union GPIOx_AFRH
{
	uint32_t 								ALL;
	struct GPIOx_AFRH_BITS 	BIT;
};

typedef struct 
{
	union GPIOx_MODER 	MODER;
	union GPIOx_OTYPER 	OTYPER;
	union GPIOx_OSPEEDR OSPEEDR;
	union GPIOx_PUPDR 	PUPDR;
	union GPIOx_IDR 		IDR;
	union GPIOx_ODR 		ODR;
	union GPIOx_BSRR 		BSRR;
	union GPIOx_LCKR 		LCKR;
	union GPIOx_AFRL 		AFRL;
	union GPIOx_AFRH 		AFRH;
	
}	GPIO_TypeDef_TIS;

void MX_GPIO_Init_TIS(void);

#endif
