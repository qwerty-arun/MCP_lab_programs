#include "stm32f4xx.h"
void delay(int n);
int main(void)
{	RCC->AHB1ENR|=9;
	GPIOD->MODER|=0x01000000;
	GPIOA->MODER&=0xFFFFFFFC;
 	while (1)
	{	if(GPIOA->IDR &0x0001)
			GPIOD->BSRR=0x00001000;
		else
			GPIOD->BSRR=0x10000000;
	}
}
void delay(int n)
{	int i;
	for(;n>0;n--)
	for (i=0;i<3195;i++);
}
