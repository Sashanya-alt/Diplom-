#include "stm32f746xx.h"

void MX_GPIO_Init_TIS()
{	
	//䫿 렬﮷ꨍ
	//PA7 - 筠÷負÷򮠷 鶴 GPIOA
	//鶴 PA7/PA6 - 𘋢
	GPIO_TypeDef_TIS *GPIOI_MY = (GPIO_TypeDef_TIS *) GPIOI_BASE;
	
	GPIOI_MY->MODER.BIT.MODER1 = 1;


	//Output push-pull  ⻵«򿭨-򮫪੻ (砯豠먠1  𘋵 뮣. 1, 砯豠먠0  𘋵 뮣. 0)
	GPIOI_MY->OTYPER.BIT.OT1 = 0;


	//Low speed
	GPIOI_MY->OSPEEDR.BIT.OSPEEDR1 = 0;


	//󱲠󸠠𝻼󸰧𝽨ÿ
	GPIOI_MY->BSRR.BIT.BR1 = 0;

	
	//ૼ򥰭ನ⭠ÿ 𳭪ö迠

	GPIOI_MY->AFRL.BIT.AFRL1 = 0;
}
