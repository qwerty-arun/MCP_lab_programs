#include "stm32f4xx.h"
void delayUs(int n);
int main(void){
	int i;
	const static int sinewave[]={2048,3071,3821,4095,3821,3071,2048,1024,274,0,274,1024};
	RCC>AHB1ENR|=1;
	GPIOA->MODER|=0x00000300;
	RCC->APB1ENR|=1<<29;
	DAC->CR|=1;
	while (1)
	{	for(i=0;i<sizeof(sinewave)/sizeof(int);i++)
		{	DAC->DHR12R1=sinewave[i];
			delayUs(10);
		}
	}
}
void delayUs (int n){
	int i;
	for(;n>0;n--)
	for(i=0;i<3;i++);
}
