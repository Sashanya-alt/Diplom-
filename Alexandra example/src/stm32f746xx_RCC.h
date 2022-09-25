//copy from "stm32f7xx.h"
#ifndef STM32F746xx_RCC_H
#define STM32F746xx_RCC_H
#ifdef _cplusplus
extern "C" { 
#endif
#include <stdint.h>

#if !defined  (HSE_VALUE) 
  #define HSE_VALUE    ((uint32_t)25000000U) /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSE_STARTUP_TIMEOUT)
  #define HSE_STARTUP_TIMEOUT    ((uint32_t)100U)   /*!< Time out for HSE start up, in ms */
#endif /* HSE_STARTUP_TIMEOUT */

/**
  * @brief Internal High Speed oscillator (HSI) value.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSI is used as system clock source, directly or through the PLL). 
  */
#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)16000000U) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/**
  * @brief Internal Low Speed oscillator (LSI) value.
  */
#if !defined  (LSI_VALUE) 
 #define LSI_VALUE  ((uint32_t)32000U)       /*!< LSI Typical Value in Hz*/
#endif /* LSI_VALUE */                      /*!< Value of the Internal Low Speed oscillator in Hz
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
/**
  * @brief External Low Speed oscillator (LSE) value.
  */
#if !defined  (LSE_VALUE)
 #define LSE_VALUE  ((uint32_t)32768U)    /*!< Value of the External Low Speed oscillator in Hz */
#endif /* LSE_VALUE */

#if !defined  (LSE_STARTUP_TIMEOUT)
  #define LSE_STARTUP_TIMEOUT    ((uint32_t)5000U)   /*!< Time out for LSE start up, in ms */
#endif /* LSE_STARTUP_TIMEOUT */

/**
  * @brief External clock source for I2S peripheral
  *        This value is used by the I2S HAL module to compute the I2S clock source 
  *        frequency, this source is inserted directly through I2S_CKIN pad. 
  */
#if !defined  (EXTERNAL_CLOCK_VALUE)
  #define EXTERNAL_CLOCK_VALUE    ((uint32_t)12288000U) /*!< Value of the Internal oscillator in Hz*/
#endif /* EXTERNAL_CLOCK_VALUE */

/////////////////
//#include "stm32f746xx.h"

//document reference manual page 143
struct RCC_CR_BITS
{
	uint32_t  HSI_ON : 1;
	uint32_t  HSI_RDY  : 1;
	uint32_t  r3 : 1;
	uint32_t  HSITRIM : 5;
	uint32_t  HSICAL : 8;
	uint32_t  HSE_ON : 1;
	uint32_t  HSE_RDY : 1;
	uint32_t  HSE_BYP : 1;
	uint32_t  CSS_ON : 1;
	uint32_t  r1 : 4;
	uint32_t  PLL_ON : 1;
	uint32_t  PLL_RDY : 1;
	uint32_t  PLL_I2S_ON : 1;
	uint32_t  PLL_I2S_RDY : 1;
	uint32_t  PLL_SAI_ON : 1;
	uint32_t  PLL_SAI_RDY : 1;
	uint32_t  r2 : 2;

};

union RCC_CR
{
	uint32_t ALL;
	struct RCC_CR_BITS BIT;
};
////////////////////////////////////
struct RCC_PLL_CFGR_BITS
{
	uint32_t  PLL_Mx  : 6;
	uint32_t  PLLN 	  : 9;
	uint32_t  r1 		  : 1;
	uint32_t  PLL_Px  : 2;
	uint32_t  r2 			: 4;
	uint32_t  PLL_SRC : 1;
	uint32_t  r3 			: 1;
	uint32_t  PLLQ 		: 4;
	uint32_t  r4 			: 4;

};


union RCC_PLL_CFGR
{
	uint32_t ALL;
	struct RCC_PLL_CFGR_BITS BIT;
};
//////////////////////////////////
//RCC clock configuration register (RCC_CFGR)
//page 148
struct RCC_CFGR_BITS
{
	uint32_t SW0 		: 1;
	uint32_t SW1 		: 1;
	uint32_t SWS0 	: 1;
	uint32_t SWS1 	: 1;
	uint32_t HPRE 	: 4;
	uint32_t r1     : 2;
	uint32_t PPRE1 	: 3;
	uint32_t PPRE2 	: 3;
	uint32_t RTCPRE : 5;
	uint32_t MCO1 	: 2;
	uint32_t I2S_SCR 	: 1;
	uint32_t MCO1_PRE : 3;
	uint32_t MCO2_PRE : 3;
	uint32_t MCO2 		: 2;
};
union RCC_CFGR
{
	uint32_t ALL;
	struct RCC_CFGR_BITS BIT;
	
};//
/////////////////////////////////////////
struct RCC_CIR_BITS
{
	uint32_t LSI_RDY_F : 1;
	uint32_t LSE_RDYF : 1;
	uint32_t HSI_RDYF : 1;
	uint32_t HSE_RDYF : 1;
	uint32_t PLL_RDYF : 1;
	uint32_t PLLI2S_RDYF : 1;
	uint32_t PLLSAI_RDYF : 1;
	uint32_t CSSF : 1;
	uint32_t LSI_RDYIE : 1;
	uint32_t LSE_RDYIE : 1;
	uint32_t HSI_RDYIE : 1;
	uint32_t HSE_RDYIE : 1;
	uint32_t PLL_RDYIE : 1;
	uint32_t PLLI2S_RDYIE : 1;
	uint32_t PLLSAI_RDYIE : 1;
	uint32_t r1 : 1;
	uint32_t LSI_RDYC : 1;
	uint32_t LSE_RDYC : 1;
	uint32_t HSI_RDYC : 1;
	uint32_t HSE_RDYC : 1;
	uint32_t PLL_RDYC : 1;
	uint32_t PLLI2S_RDYC : 1;
	uint32_t PLLSAI_RDYC : 1;
	uint32_t CSSC : 1;
	uint32_t r2 : 8;
};

union RCC_CIR
{
	uint32_t ALL;
	struct RCC_CIR_BITS BIT;
};
////////////////////////////////////
struct RCC_AHB1RSTR_BITS
{
	uint32_t GPIOA_RST : 1;
	uint32_t GPIOB_RST : 1;
	uint32_t GPIOC_RST : 1;
	uint32_t GPIOD_RST : 1;
	uint32_t GPIOE_RST : 1;
	uint32_t GPIOF_RST : 1;
	uint32_t GPIOG_RST : 1;
	uint32_t GPIOH_RST : 1;
	uint32_t GPIOI_RST : 1;
	uint32_t GPIOJ_RST : 1;
	uint32_t GPIOK_RST : 1;
	uint32_t r1  : 1;
	uint32_t CRCR_ST : 1;
	uint32_t r2 : 8;
	uint32_t DMA1_RST : 1;
	uint32_t DMA2_RST : 1;
	uint32_t DMA2D_RST : 1;
	uint32_t r3 : 1;
	uint32_t ETHMAC_RST : 1;
	uint32_t r4 : 3;
	uint32_t  OTGH_S_RST : 1;
	uint32_t r5 : 2;

};
union RCC_AHB1RSTR
{
	uint32_t ALL;
	struct RCC_AHB1RSTR_BITS BIT;
};
/////////////////////////////////////
struct RCC_AHB2RSTR_BITS
{
	uint32_t DCMI_RST : 1;
	uint32_t r1 : 3;
	uint32_t CRYP_RST : 1;
	uint32_t HASH_RST : 1;
	uint32_t RNG_RST : 1;
	uint32_t OTGFS_RST : 1;
	uint32_t r2 : 24;
};

union RCC_AHB2RSTR
{
	uint32_t ALL;
	struct RCC_AHB2RSTR_BITS BIT;
};
//////////////////////////////////////
struct RCC_AHB3RSTR_BITS
{
	uint32_t FMCRST : 1;
	uint32_t QSPIRST : 1;
	uint32_t r1 : 30;
};
union RCC_AHB3RSTR
{
	uint32_t ALL;
	struct RCC_AHB3RSTR_BITS BIT;
};

//////////////////////////////////////
struct RCC_APB1RSTR_BITS
{
	uint32_t TIM2_RST : 1;
	uint32_t TIM3_RST : 1;
	uint32_t TIM4_RST : 1;
	uint32_t TIM5_RST : 1;
	uint32_t TIM6_RST : 1;
	uint32_t TIM7_RST : 1;
	uint32_t TIM12_RST : 1;
	uint32_t TIM13_RST : 1;
	uint32_t TIM14_RST : 1;
	uint32_t LPTIM1_RST : 1;
	uint32_t r1 : 1;
	uint32_t WWDG_RST : 1;
	uint32_t r2 : 2;
	uint32_t SPI2_RST : 1;
	uint32_t SPI3_RST : 1;
	uint32_t SPDIFR_XRST : 1;
	uint32_t UART2_RST : 1;
	uint32_t UART3_RST : 1;
	uint32_t UART4_RST : 1;
	uint32_t UART5_RST : 1;
	uint32_t I2C1_RST : 1;
	uint32_t I2C2_RST : 1;
	uint32_t I2C3_RST : 1;
	uint32_t I2C4_RST : 1;
	uint32_t CAN1_RST : 1;
	uint32_t CAN2_RST : 1;
	uint32_t CEC_RST  : 1;
	uint32_t PWR_RST : 1;
	uint32_t DAC_RST : 1;
	uint32_t UART7_RST : 1;
	uint32_t UART8_RST : 1;
};

union RCC_APB1RSTR
{
	uint32_t ALL;
	struct RCC_APB1RSTR_BITS BIT;
};
//////////////////////////////////


struct RCC_APB2RSTR_BITS
{
	uint32_t TIM1_RST : 1;
	uint32_t TIM8_RST : 1;
	uint32_t r1  : 2;
	uint32_t USART1_RST : 1;
	uint32_t USART6_RST : 1;
	uint32_t r2 : 2;
	uint32_t ADC_RST : 1;
	uint32_t r3 : 2;
	uint32_t SDMMC1_RST : 1;
	uint32_t SPI1_RST : 1;
	uint32_t SPI4_RST : 1;
	uint32_t SYSCFG_RST : 1;
	uint32_t r4 : 1;
	uint32_t TIM9_RST : 1;
	uint32_t TIM10_RST : 1;
	uint32_t TIM11_RST : 1;
	uint32_t r5 : 1;
	uint32_t SPI5_RST : 1;
	uint32_t SPI6_RST : 1;
	uint32_t SAI1_RST : 1;
	uint32_t SAI2_RST : 1;
	uint32_t r6 : 2;
	uint32_t LTDC_RST : 1;
	uint32_t r7 : 5;
};

union RCC_APB2RSTR
{
	uint32_t ALL;
	struct RCC_APB2RSTR_BITS BIT;
};
//////////////////////////////////////
struct RCC_AHB1ENR_BITS
{
	uint32_t GPIO_AEN : 1;
	uint32_t GPIO_BEN : 1;
	uint32_t GPIOC_EN : 1;
	uint32_t GPIOD_EN : 1;
	uint32_t GPIOE_EN : 1;
	uint32_t GPIOF_EN : 1;
	uint32_t GPIOG_EN : 1;
	uint32_t GPIOH_EN : 1;
	uint32_t GPIOI_EN : 1;
	uint32_t GPIOJ_EN : 1;
	uint32_t GPIOK_EN : 1;
	uint32_t r1 : 1;
	uint32_t CRC_EN : 1;
	uint32_t r2 : 5;
	uint32_t BKPSRAM_EN : 1;
	uint32_t r3 : 1;
	uint32_t DTCMRAM_EN : 1;
	uint32_t DMA1_EN : 1;
	uint32_t DMA2_EN : 1;
	uint32_t DMA2D_EN : 1;
	uint32_t r4 : 1;
	uint32_t ETHMAC_EN : 1;
	uint32_t ETHMACTX_EN : 1;
	uint32_t ETHMACRX_EN : 1;
	uint32_t ETHMACPTP_EN : 1;
	uint32_t OTGHS_EN : 1;
	uint32_t OTGHSULPI_EN : 1;
	uint32_t r6 : 1;

};
union RCC_AHB1ENR
{
	uint32_t  ALL;
	struct RCC_AHB1ENR_BITS BIT;
};

//стр. 163
///////////5.3.11/////////////////////
struct RCC_AHB2ENR_BITS
{
	uint32_t DCMIEN : 1;
	uint32_t r1 : 3;
	uint32_t CRYP_EN : 1;
	uint32_t HASH_EN :1;
	uint32_t RNG_EN : 1;
	uint32_t OTGFS_EN :1;
	uint32_t r2 : 24;
	
};

union RCC_AHB2ENR
{
	uint32_t  ALL;
	struct RCC_AHB2ENR_BITS BIT;
};

////////////////5.3.12////////////////////////////
struct RCC_AHB3ENR_BITS
{
	uint32_t FMCEN : 1;
	uint32_t QSPIEN : 1;
	uint32_t r1 : 30;
};

union RCC_AHB3ENR
{
	uint32_t  ALL;
	struct RCC_AHB3ENR_BITS BIT;
};
//////////////5.3.13/////////////////////////////
struct RCC_APB1ENR_BITS
{
	uint32_t TIM2_EN : 1;
	uint32_t TIM3_EN : 1;
	uint32_t TIM4_EN : 1;
	uint32_t TIM5_EN : 1;
	uint32_t TIM6_EN : 1;
	uint32_t TIM7_EN : 1;
	uint32_t TIM12_EN : 1;
	uint32_t TIM13_EN : 1;
	uint32_t TIM14_EN : 1;
	uint32_t LPTIM1_EN : 1;
	uint32_t r1 : 1;
	uint32_t WWDG_EN : 1;
	uint32_t r2 : 2;
	uint32_t SPI2_EN : 1;
	uint32_t SPI3_EN : 1;
	uint32_t SPDIFRX2_EN : 1;
	uint32_t USART2_EN : 1;
	uint32_t USART3_EN : 1;
	uint32_t UART4_EN : 1;
	uint32_t UART5_EN : 1;
	uint32_t I2C1_EN : 1;
	uint32_t I2C2_EN : 1;
	uint32_t I2C3_EN : 1;
	uint32_t I2C4_EN : 1;
	uint32_t CAN1_EN : 1;
	uint32_t CAN2_EN : 1;
	uint32_t CEC_EN : 1;
	uint32_t PWR_EN : 1;
	uint32_t DAC_EN : 1;
	uint32_t UART7_EN : 1;
	uint32_t UART8_EN : 1;
};

union RCC_APB1ENR
{
	uint32_t  ALL;
	struct RCC_APB1ENR_BITS BIT;
};

////////////////5.3.14/////////////
struct RCC_APB2ENR_BITS
{
	uint32_t TIM1_EN : 1;
	uint32_t TIM8_EN : 1;
	uint32_t r1 : 2;
	uint32_t USART1_EN : 1;
	uint32_t USART6_EN : 1;
	uint32_t r2 : 2;
	uint32_t ADC1_EN : 1;
	uint32_t ADC2_EN : 1;
	uint32_t ADC3_EN : 1;
	uint32_t SDMMC1_EN : 1;
	uint32_t SPI1_EN : 1;
	uint32_t SPI4_EN : 1;
	uint32_t SYSCFG_EN : 1;
	uint32_t r3 : 1;
	uint32_t TIM9_EN : 1;
	uint32_t TIM10_EN : 1;
	uint32_t TIM11_EN : 1;
	uint32_t r4 : 1;
	uint32_t SPI5_EN : 1;
	uint32_t SPI6_EN : 1;
	uint32_t SAI1_EN : 1;
	uint32_t SAI2_EN : 1;
	uint32_t r5 : 2;
	uint32_t LTDC_EN : 1;
	uint32_t r6 : 5;
};

union RCC_APB2ENR
{
	uint32_t  ALL;
	struct RCC_APB2ENR_BITS BIT;
};

////////5.3.15////////////////
struct RCC_AHB1LPENR_BITS
{
	uint32_t GPIOA_LPEN : 1;
	uint32_t GPIOB_LPEN : 1;
	uint32_t GPIOC_LPEN : 1;
	uint32_t GPIOD_LPEN : 1;
	uint32_t GPIOE_LPEN : 1;
	uint32_t GPIOF_LPEN : 1;
	uint32_t GPIOGG_LPEN : 1;
	uint32_t GPIOH_LPEN : 1;
	uint32_t GPIOI_LPEN : 1;
	uint32_t GPIOIJ_LPEN : 1;
	uint32_t GPIOK_LPEN : 1;
	uint32_t r1 : 1;
	uint32_t CRC_LPEN : 1;
	uint32_t AXI_LPEN : 1;
	uint32_t r2 : 1;
	uint32_t FLITF_LPEN : 1;
	uint32_t SRAM1_LPEN : 1;
	uint32_t SRAM2_LPEN : 1;
	uint32_t BKPSRAM_LPEN : 1;
	uint32_t r3 : 1;
	uint32_t DTCM_LPEN : 1;
	uint32_t DMA1_LPEN : 1;
	uint32_t DMA2_LPEN : 1;
	uint32_t DMA2D_LPEN : 1;
	uint32_t r4 : 1;
	uint32_t ETHMAC_LPEN : 1;
	uint32_t ETHTX_LPEN : 1;
	uint32_t ETHRX_LPEN : 1;
	uint32_t ETHPTP_LPEN : 1;
	uint32_t OTGHS_LPEN : 1;
	uint32_t OTGHS_ULPI_LPEN : 1;
	uint32_t r5 : 1;
};

union RCC_AHB1LPENR
{
	uint32_t  ALL;
	struct RCC_AHB1LPENR_BITS BIT;
};

//////////5.3.16///////////////////
struct RCC_AHB2LPENR_BITS
{
	uint32_t DCMI_LPRN : 1;
	uint32_t r1 : 3;
	uint32_t CRYP_LPRN : 1;
	uint32_t HASH_LPRN : 1;
	uint32_t RNG_LPRN : 1;
	uint32_t OTGFS_LPRN : 1;
	uint32_t r2 : 24;
};

union RCC_AHB2LPENR
{
	uint32_t  ALL;
	struct RCC_AHB2LPENR_BITS BIT;
};

/////////5.3.17//////////////////
struct RCC_AHB3LPENR_BITS
{
	uint32_t FMC_LPEN : 1;
	uint32_t QSPI_LPEN : 1;
	uint32_t r1 : 30;
};

union RCC_AHB3LPENR
{
	uint32_t  ALL;
	struct RCC_AHB3LPENR_BITS BIT;
};

///////////5.3.18///////////
struct RCC_APB1LPENR_BITS
{
	uint32_t TIM2_LPEN : 1;
	uint32_t TIM3_LPEN : 1;
	uint32_t TIM4_LPEN : 1;
	uint32_t TIM5_LPEN : 1;
	uint32_t TIM6_LPEN : 1;
	uint32_t TIM7_LPEN : 1;
	uint32_t TIM12_LPEN : 1;
	uint32_t TIM13_LPEN : 1;
	uint32_t TIM14_LPEN : 1;
	uint32_t LPTMI1 : 1;
	uint32_t r1 : 1;
	uint32_t WWDG_LPEN : 1;
	uint32_t r2 : 2;
	uint32_t SPI2_LPEN : 1;
	uint32_t SPI3_LPEN : 1;
	uint32_t SPDIFRX_LPEN : 1;
	uint32_t USART2_LPEN : 1;
	uint32_t USART3_LPEN : 1;
	uint32_t USART4_LPEN : 1;
	uint32_t USART5_LPEN : 1;
	uint32_t I2C1_LPEN : 1;
	uint32_t I2C2_LPEN : 1;
	uint32_t I2C3_LPEN : 1;
	uint32_t I2C4_LPEN : 1;
	uint32_t CAN1_LPEN : 1;
	uint32_t CAN2_LPEN : 1;
	uint32_t CEC_LPEN : 1;
	uint32_t PWP_LPEN : 1;
	uint32_t DAC_LPEN : 1;
	uint32_t UART7_LPEN : 1;
	uint32_t UART8_LPEN : 1;
};

union RCC_APB1LPENR
{
	uint32_t  ALL;
	struct RCC_APB1LPENR_BITS BIT;
};

//page 181       5.3.19
struct RCC_APB2LPENR_BITS
{
	uint32_t TIM1_LPEN : 1;
	uint32_t TIM8_LPEN : 1;
	uint32_t res1 : 2;
	uint32_t USART1_LPEN : 1;
	uint32_t USART6_LPEN : 1;
	uint32_t res2 : 2;
	uint32_t ADC1_LPEN : 1;
	uint32_t ADC2_LPEN : 1;
	uint32_t ADC3_LPEN : 1;
	uint32_t SDMMC1_LPEN : 1;
	uint32_t SPI1_LPEN : 1;
	uint32_t SPI4_LPEN : 1;
	uint32_t SYSCFG_LPEN : 1;
	uint32_t res3 : 1;
	uint32_t TIM9_LPEN : 1;
	uint32_t TIM10_LPEN : 1;
	uint32_t TIM11_LPEN : 1;
	uint32_t res4 : 1;
	uint32_t SPI5_LPEN : 1;
	uint32_t SPI6_LPEN : 1;
	uint32_t SAI1_LPEN : 1;
	uint32_t SAI2_LPEN : 1;
	uint32_t res5 : 2;
	uint32_t LTDC_LPEN : 1;
	uint32_t res6 : 5;
	//Total sum 32
};

union RCC_APB2LPENR
{
	uint32_t ALL;
	struct RCC_APB2LPENR_BITS BIT;
};

//page 183 chapter 5.3.20

struct RCC_BDCR_BITS
{
	uint32_t LSEON : 1;
	uint32_t LSERDY : 1;
	uint32_t LSEBYP : 1;
	uint32_t LSEDRV: 2;
	uint32_t res1 : 3;
	uint32_t RTCSEL : 2;
	uint32_t res2 : 5;
	uint32_t RTCEN : 1;
	uint32_t BDRST : 1;
	
	uint32_t res3 : 15;
	
	//Total sum 32
};

union RCC_BDCR
{
	uint32_t ALL;
	struct RCC_BDCR_BITS BIT;
};

/****************************/
//page 184 topic 5.3.21
struct RCC_CSR_BITS
{
	uint32_t LSION : 1;
	uint32_t LSIRDY : 1;
	uint32_t res : 22;
	uint32_t RMVF : 1;
	uint32_t BOR_RSTF : 1;
	uint32_t PIN_RSTF : 1;
	uint32_t POR_RSTF : 1;
	uint32_t SFT_RSTF : 1;
	uint32_t IWDG_RSTF : 1;
	uint32_t WWDG_RSTF : 1;
	uint32_t LPWR_RSTF : 1;
	

	//Total sum 32
};

union RCC_CSR
{
	uint32_t ALL;
	struct RCC_CSR_BITS BIT;
};
/****************************/
//page 186 topic 5.3.22
struct RCC_SSCGR_BITS
{
	uint32_t MODPER : 13;
	uint32_t INCSTEP : 3;
	uint32_t NCSTEP : 12;
	uint32_t res : 2;
	uint32_t SPR_EAD_SEL : 1;
	uint32_t SSCG_EN : 1;
	
	//Total sum 32
};

union RCC_SSCGR
{
	uint32_t ALL;
	struct RCC_SSCGR_BITS BIT;
};
/*********************************/
//page 187 topic 5.3.23
struct RCC_PLLI2SCFGR_BITS
{
	uint32_t res1 : 6;
	uint32_t PLLI2SN: 9;
	uint32_t res2 : 1;
	uint32_t PLLI2SP : 2;
	uint32_t res3 : 6;
	uint32_t PLLI2SQ : 4;
	uint32_t PLLI2SR : 3;
	uint32_t res : 1;
	
	//Total sum 32
};

union RCC_PLLI2SCFGR
{
	uint32_t ALL;
	struct RCC_PLLI2SCFGR_BITS BIT;
};
/**********************************/
//page 190 topic 5.3.24
struct RCC_PLLSAICFGR_BITS
{
	uint32_t res1 : 6;
	uint32_t PLLSAIN : 9;
	uint32_t res2 : 1;
	uint32_t PLLSAIP: 2;
	uint32_t res3 : 6;
	uint32_t PLLSAIQ: 4;
	uint32_t PLLSAIR : 3;
	uint32_t res4 : 1;
	
	//Total sum 32
};

union RCC_PLLSAICFGR
{
	uint32_t ALL;
	struct RCC_PLLSAICFGR_BITS BIT;
};
/*********************************/
//page 191 topic 5.3.25
struct RCC_DCKCFGR1_BITS
{
	uint32_t PLLI2SDIVQ : 5;
	uint32_t res1 : 3;
	uint32_t PLLSAIDIVQ : 5;
	uint32_t res2 : 3;
	uint32_t PLLSAIDIVR : 2;
	uint32_t res3 : 2;
	uint32_t SAI1SEL : 2;
	uint32_t SAI2SEL : 2;
	uint32_t TIMPRE : 1;
	
	uint32_t res : 7;
	
	//Total sum 32
};

union RCC_DCKCFGR1
{
	uint32_t ALL;
	struct RCC_DCKCFGR1_BITS BIT;
};
/**********************************/


/////////////5.3.26///////////
struct RCC_DCKCFGR2_BITS
{
	uint32_t UART1_SEL : 2;
	uint32_t UART2_SEL : 2;
	uint32_t UART3_SEL : 2;
	uint32_t UART4_SEL : 2;
	uint32_t UART5_SEL : 2;
	uint32_t USART6_SEL : 2;
	uint32_t UART7_SEL : 2;
	uint32_t UART8_SEL : 2;
	uint32_t I2C1_SEL : 2;
	uint32_t I2C2_SEL : 2;
	uint32_t I2C3_SEL : 2;
	uint32_t I2C4_SEL : 2;
	uint32_t LPTIM_SEL : 2;
	uint32_t CECSE_SEL : 1;
	uint32_t CK48M_SEL : 1;
	uint32_t SDMMC1_SEL : 1;
	uint32_t r1 : 3;
};

union RCC_DCKCFGR2
{
	uint32_t  ALL;
	struct RCC_DCKCFGR2_BITS BIT;
};

typedef struct 
{
	union RCC_CR 				CR;
	union RCC_PLL_CFGR  PLL_CFGR;
	union RCC_CFGR      CFGR;
	union RCC_CIR       CIR; 
	union RCC_AHB1RSTR  AHB1RSTR;
	union RCC_AHB2RSTR  AHB2RSTR;
	union RCC_AHB3RSTR  AHB3RSTR;
	uint32_t      RESERVED0;
	union RCC_APB1RSTR   APB1RSTR;
	union RCC_APB2RSTR   APB2RSTR;
		uint32_t      RESERVED1;
		uint32_t      RESERVED2;
	union RCC_AHB1ENR		 AHB1ENR;	
	union RCC_AHB2ENR		 AHB2ENR;
	union RCC_AHB3ENR		 AHB3ENR;
	uint32_t      RESERVED3;
	union RCC_APB1ENR		 APB1ENR;
  union RCC_APB2ENR		 APB2ENR;
	uint32_t      RESERVED4;
	uint32_t      RESERVED5;
	union RCC_AHB1LPENR	 AHB1LPENR;
	union RCC_AHB2LPENR	 AHB2LPENR;
	union RCC_AHB3LPENR	 AHB3LPENR;
	uint32_t      RESERVED6;
	union RCC_APB1LPENR  APB1LPENR;
	union RCC_APB2LPENR  APB2LPENR;
	uint32_t      RESERVED7;
	uint32_t      RESERVED8;
	union RCC_BDCR       BDCR;
	union RCC_CSR				 CSR;
	uint32_t      RESERVED9;
	uint32_t      RESERVED10;
	union RCC_SSCGR      SSCGR;
	union RCC_PLLI2SCFGR PLLI2SCFGR;
	union RCC_PLLSAICFGR PLLSAICFGR;
	union RCC_DCKCFGR1   DCKCFGR1;
	union RCC_DCKCFGR2   DCKCFGR2;
} RCC_TypeDef_TIS;	

void HAL_RCC_OscConfig_TIS(void);
int HAL_RCC_ClockConfig_TIS(uint32_t FLatency);
uint32_t HAL_RCC_GetSysClockFreq(void);
//void SystemCoreClockUpdate(void);

//extern struct _RCC_TypeDef_TIS RCC_TIS;

//typedef struct
//{
//  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
//  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
//  __IO uint32_t CFGеR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
//  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
//  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
//  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
//  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
//  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
//  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
//  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
//  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
//  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
//  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
//  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
//  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
//  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
//  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
//  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
//  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
//  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
//  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
//  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
//  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
//  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
//  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
//  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
//  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
//  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
//  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
//  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
//  __IO uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
//  __IO uint32_t DCKCFGR1;      /*!< RCC Dedicated Clocks configuration register1,                 Address offset: 0x8C */
//  __IO uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x90 */

//} RCC_TypeDef;

//void HAL_RCC_OscConfig_TIS(void);

#endif
