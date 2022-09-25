#include "stm32f746xx.h" //объявление наших библиотек на 180 строке

int main ()
{	
	//Объявление локальной переменной RCC
	RCC_TypeDef_TIS *RCC_LOCAL = (RCC_TypeDef_TIS *)RCC_BASE;
	
	//Инициализация осцилятора
	HAL_RCC_OscConfig_TIS();
	
	//инициализация делителей для шин
	HAL_RCC_ClockConfig_TIS(0xf);
	
	//обновление системнй частоты
	SystemCoreClockUpdate();
	SystemCoreClock = HAL_RCC_GetSysClockFreq(); 
	
	//включение и инициализация GPIOI (PI1)
	RCC_LOCAL->AHB1ENR.BIT.GPIOI_EN=1;
	MX_GPIO_Init_TIS();
	
	//включение и инициализация TIM7
	RCC_LOCAL->APB1ENR.BIT.TIM7_EN = 1;
	HAL_TIM_Init();
	
	while(1){

	}
	
	
}

