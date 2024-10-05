#include"stm32f44xx.h"
int main(void)
{	int data;
	RCC->AHB1ENR|=1;
	GPIOA->MODER|=0x00000300;
	RCC->APB1ENR|=1<<29;
	DAC->CR|=1;
	while(1)
	{	DAC->DHR12R1=data++&0x0FFF;
	}
}
