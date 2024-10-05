#include "stm32f4xx.h"
int main(void)
{	int data=0;
	int direction=1;
	RCC->AHB1ENR|=1;
	GPIOA->MODER|=0x00000300;
	RCC->APB1ENR|=(1<<29);
	DAC->CR|=1;
	while(1)
	{	DAC->DHR12R1=data&0x0FFF;
		if(data>=0x0FFF)
		{ direction=-1;
		}
		else if(data<=0)
		{ direction =1;
		}
		data+=direction;
	}
}
