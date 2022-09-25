#include "stm32f746xx.h"

////Как это делать не ручками??
//#define PERIPH_BASE            0x40000000UL /*!< Base address of : AHB/ABP Peripherals*/
//#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
//#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)

void HAL_RCC_OscConfig_TIS()
{
	//узнать, по дефолту 0 или надо обнулять
	RCC_TypeDef_TIS *RCC_MY = (RCC_TypeDef_TIS *) RCC_BASE;
	
	//выход на внешний генератор
	//внутренний генератор работает не стабильно
	RCC_MY->CR.BIT.HSE_ON = 1;
	
	//ждем пока HSE не будет стабильным
	while (RCC_MY->CR.BIT.HSE_RDY ==0)
	{
	}
	
	//настройка множителя для выхода на рабочую частоту контроллера
	//у каждого контроллера свой множитель
	//PLL Configuration
	//множитель для перехода на рабочуу частоту (множилка)
	
	//0: HSI clock selected as PLL and PLLI2S clock entry
	//1: HSE oscillator clock selected as PLL and PLLI2S clock entry
	//значения из куба мх
	RCC_MY->PLL_CFGR.BIT.PLL_SRC = 1;
	
	//PLIM =
	RCC_MY->PLL_CFGR.BIT.PLL_Mx = 16;
	
	//PLLN = 
	RCC_MY->PLL_CFGR.BIT.PLLN = 192;
		
	//PLLP = 
	//RCC_MY->PLL_CFGR.BIT.PLL_Px =2;
//The software has to set these bits correctly not to exceed 216 MHz on this domain.
//PLL output clock frequency = VCO frequency / PLLP with PLLP = 2, 4, 6, or 8
//00: PLLP = 2
//01: PLLP = 4
//10: PLLP = 6
//11: PLLP = 8
	RCC_MY->PLL_CFGR.BIT.PLL_Px = 0;
	//RCC_MY->PLL_CFGR.BIT.PLL_P1 = 1;
	
	//PLLQ = 
	RCC_MY->PLL_CFGR.BIT.PLLQ = 2;	
	RCC_MY->CR.BIT.PLL_ON =  1; 	
	
	//Настройка переферии
	//RCC_MY->CR.BIT. HSE_ON = 1;
	
	//
	while (RCC_MY->CR.BIT.PLL_RDY == 0)
	{
	}
		
}
