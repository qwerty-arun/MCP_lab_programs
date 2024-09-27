#include "stm32f407xx.h"
void delay(int n);

int main(void)
{
	RCC->AHB1ENR |= (0x10|0x01);
	GPIOE->MODER |= 0x00000154;
	while(1)
	{
		if(GPIOA->IDR &(1<<0))
		{
			GPIOE->ODR = 0x00000010;
			delay(1);
			GPIOE->ODR = 0x00000008;
			delay(1);
			GPIOE->ODR = 0x00000004;
			delay(1);
			GPIOE->ODR = 0x00000002;
			delay(1);
		}
		else
		{
			GPIOE->ODR = 0x00000002;
			delay(1);
			GPIOE->ODR = 0x00000004;
			delay(1);
			GPIOE->ODR = 0x00000008;
			delay(1);
			GPIOE->ODR = 0x00000010;
			delay(1);
		}
	}
}

void delay(int n)
{
	int i,j;
	for(j=0;j<n;j++)
	for(i=0;i<2200;i++);
}
