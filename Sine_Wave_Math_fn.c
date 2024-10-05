#include "stm32f4xx.h"
void delayUs(int n);
#define WAVEFORM =_LENGTH 256
int sinewave[WAVEFORM_LENGTH];
int main(void)
{
	int i;
	double radians;
	const double m_pi=3.141592;
	radians=(2*m_pi)/WAVEFORM_LENGTH;
	for(i=0;i<WAVEFORM_LENGTH;i++)
	{ sinewave[i]=2000*(sin(radians*i)+1);
	}
	RCC->AHB1ENR|=1;
	GPIOA->MODER|=0x00000300;
	RCC->APB1ENR|=1<29;
	DAC->CR|=1;
	while(1){
		for(i=0;i<WAVEFORM_LENGTH;i++){
			DAC->DHR12R1=sinewave[i];
			delayUs(int n);}
	}
}
void delayUs (int n){
	int i;
	for(;n>0;n--)
	for(i=0;i<3195;i++);
}
