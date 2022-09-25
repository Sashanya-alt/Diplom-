#include "stm32f746xx.h"

void HAL_RCC_OscConfig_TIS()
{
	//объявление локальной переменной
	RCC_TypeDef_TIS *RCC_LOCAL = (RCC_TypeDef_TIS *) RCC_BASE;
	
	//выход на внешний генератор HSE (HSI - внутренний)
	//внутренний генератор работает не стабильно
	RCC_LOCAL->CR.BIT.HSE_ON = 1;
	
	//ждем пока HSE не будет стабильным
	while (RCC_LOCAL->CR.BIT.HSE_RDY ==0)
	{
	}
	
	//настройка множителя для выхода на рабочую частоту контроллера
	//у каждого контроллера свой множитель
	//PLL Configuration
	//множитель для перехода на рабочуу частоту (множилка)
	
	//0: HSI clock selected as PLL and PLLI2S clock entry
	//1: HSE oscillator clock selected as PLL and PLLI2S clock entry
	//значения из куба мх
	RCC_LOCAL->PLL_CFGR.BIT.PLL_SRC = 1;
	
	//PLIM =
	RCC_LOCAL->PLL_CFGR.BIT.PLL_Mx = 25;
	
	//PLLN = 
	RCC_LOCAL->PLL_CFGR.BIT.PLLN = 432;
		
	//PLLP = 
	//RCC_MY->PLL_CFGR.BIT.PLL_Px =2;
//The software has to set these bits correctly not to exceed 216 MHz on this domain.
//PLL output clock frequency = VCO frequency / PLLP with PLLP = 2, 4, 6, or 8
//00: PLLP = 2
//01: PLLP = 4
//10: PLLP = 6
//11: PLLP = 8
	RCC_LOCAL->PLL_CFGR.BIT.PLL_Px = 0;
	//RCC_MY->PLL_CFGR.BIT.PLL_P1 = 1;
	
	//PLLQ = 
	RCC_LOCAL->PLL_CFGR.BIT.PLLQ = 2;	
	RCC_LOCAL->CR.BIT.PLL_ON =  1; 	

	//
	while (RCC_LOCAL->CR.BIT.PLL_RDY == 0)
	{
	}
		
}

int HAL_RCC_ClockConfig_TIS(uint32_t FLatency)
{
	RCC_TypeDef_TIS *RCC_LOCAL = (RCC_TypeDef_TIS *) RCC_BASE;
	FLASH_TypeDef2 *FLASH_TISLoc = (FLASH_TypeDef2 *) FLASH_R_BASE;
	
	FLASH_TISLoc->ACR.bit.LATENCY = FLatency;
	//line 747 MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, (RCC_HCLK_DIV16 << 3));
	
	 //  HCLK Configuration 
//	0xx: AHB clock not divided
//	100: AHB clock divided by 2
//	101: AHB clock divided by 4
//	110: AHB clock divided by 8
	
	RCC_LOCAL->CFGR.BIT.PPRE2 = 6;
	RCC_LOCAL->CFGR.BIT.PPRE1 = 6;
	
	//set HCLK clock divider
	//0xxx: system clock not divided
	//1000: system clock divided by 2
	//1001: system clock divided by 4
	//1010: system clock divided by 8
	RCC_LOCAL->CFGR.BIT.HPRE = 0;//0xxx: system clock not divided
	// SYSCLK Configuration 
	RCC_LOCAL->CFGR.BIT.SW1 = 1;//PLL selected as system clock
	RCC_LOCAL->CFGR.BIT.SW0 = 0;
	
	
//  while (__HAL_RCC_GET_SYSCLK_SOURCE() != (RCC_ClkInitStruct->SYSCLKSource << RCC_CFGR_SWS_Pos))
//    {
//      if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
//      {
//        return HAL_TIMEOUT;
//      }
//    }
	 while ( (RCC_LOCAL->CFGR.BIT.SWS0 != 0) && (RCC_LOCAL->CFGR.BIT.SWS1 != 1))
	 {
	 }
	return 1;
}

uint32_t HAL_RCC_GetSysClockFreq(void)
{
	int Shift;
  uint32_t pllm = 0, pllvco = 0, pllp = 0;
  uint32_t sysclockfreq = 0;
	RCC_TypeDef_TIS * RCC_TISLoc = (RCC_TypeDef_TIS *) RCC_BASE;
	uint8_t SWS = (RCC_TISLoc->CFGR.BIT.SWS1 << 1) | RCC_TISLoc->CFGR.BIT.SWS0;
//	00: HSI oscillator used as the system clock
//	01: HSE oscillator used as the system clock
//	10: PLL used as the system clock
  /* Get SYSCLK source -------------------------------------------------------*/
  switch (SWS)
  {
    case 0:  /* HSI used as system clock source */
    {
      sysclockfreq = HSI_VALUE;
       break;
    }
    case 1:  /* HSE used as system clock  source */
    {
      sysclockfreq = HSE_VALUE;
      break;
    }
    case 2:  /* PLL used as system clock  source */
    {
      /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLLM) * PLLN
      SYSCLK = PLL_VCO / PLLP */
      pllm = RCC_TISLoc->PLL_CFGR.BIT.PLL_Mx;// RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
			//PLLSRC: Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
			//Set and cleared by software to select PLL and PLLI2S clock source. This bit can be written
			//only when PLL and PLLI2S are disabled.
			//0: HSI clock selected as PLL and PLLI2S clock entry
			//1: HSE oscillator clock selected as PLL and PLLI2S clock entry
			//RCC->PLLCFGR
			//RCC_TISLoc->PLL_CFGR.BIT.PLL_SRC
      if (RCC_TISLoc->PLL_CFGR.BIT.PLL_SRC == 1)
      {
        /* HSE used as PLL clock source */
        pllvco = (uint32_t) (((uint64_t) HSE_VALUE * 
				((uint64_t) RCC_TISLoc->PLL_CFGR.BIT.PLLN )) / (uint64_t)pllm);
      }
      else
      {
        /* HSI used as PLL clock source */
        pllvco = (uint32_t) ((uint64_t) HSI_VALUE * 
				((uint64_t)  RCC_TISLoc->PLL_CFGR.BIT.PLLN ) / (uint64_t)pllm);
      }
      pllp = ((RCC_TISLoc->PLL_CFGR.BIT.PLL_Px + 1 ) *2);

      sysclockfreq = pllvco/pllp;
      break;
    }
    default:
    {
      sysclockfreq = HSI_VALUE;
      break;
    }
  }
	// Compute HCLK frequency 
  // Get HCLK prescaler 
	//AHBPrescTable[RCC_TIS->CFGR.BIT.HPRE];
	Shift = AHBPrescTable[RCC_TISLoc->CFGR.BIT.HPRE];//RCC_TIS->CFGR.BIT.HPRE >> 1;
  sysclockfreq >>= Shift;// RCC_TIS->CFGR.BIT.HPRE; 
  return sysclockfreq;
}
