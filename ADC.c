#include "stm32f407xx.h"
int main(void)
{
	int result;
	RCC->AHB1ENR|=8;
	GPIOD->MODER &= ~(0x03000000);
	GPIOD->MODER |= 0x01000000;
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= 0xC;
	RCC->APB2ENR |= 0x00000100;
	ADC1->CR2 = 0;
	ADC1->SQR3 = 1;
	ADC1->SQR1 = 0;
	ADC1->CR2 |= 1;

	while(1)
	{
		ADC1->CR2 |= 0x40000000;
		while(!(ADC1->SR&2))
		{
		}
		result=ADC1->DR;
		if(result & 0x100)
			GPIOD->BSRR=0x00001000;
		else
			GPIOD->BSRR=0x10000000;
	}
}
