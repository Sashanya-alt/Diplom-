#include "stm32f746xx.h" //объявление наших библиотек на 180 строке


int main ()
{
	HAL_RCC_OscConfig_TIS();
	
	RCC_TypeDef_TIS *RCC_LOCAL = (RCC_TypeDef_TIS *)RCC_BASE;
	RCC_LOCAL->AHB1ENR.BIT.GPIOI_EN=1;
	
	MX_GPIO_Init_TIS();
	while(1);
	
}

