#include "stm32f746xx.h"

void MX_GPIO_Init_TIS()
{	

	GPIO_TypeDef_TIS *GPIOI_LOCAL = (GPIO_TypeDef_TIS *) GPIOI_BASE;
	
	GPIOI_LOCAL->MODER.BIT.MODER1 = 1;


	//Output push-pull  ⻵«򿭨-򮫪੻ (砯豠먠1  𘋵 뮣. 1, 砯豠먠0  𘋵 뮣. 0)
	GPIOI_LOCAL->OTYPER.BIT.OT1 = 0;


	//Low speed
	GPIOI_LOCAL->OSPEEDR.BIT.OSPEEDR1 = 0;


	//󱲠󸠠𝻼󸰧𝽨ÿ
	GPIOI_LOCAL->BSRR.BIT.BR1 = 0;

	
	//ૼ򥰭ನ⭠ÿ 𳭪ö迠

	GPIOI_LOCAL->AFRL.BIT.AFRL1 = 0;
}
