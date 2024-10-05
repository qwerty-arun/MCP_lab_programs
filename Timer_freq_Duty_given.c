#include "stm32f4xx.h"
void T_ON(void);
void T_OFF(void);
int main(void)
{	RCC->AHB1ENR|=1;
	GPIOA->MODER &=~0x00000C00;
	GPIOA->MODER |=0x00000400;
	RCC->APB1ENR |=1;
	TIM2->PSC=1600-1;
	while(1)
	{ T_OFF();
	  T_ON();
	}
}
void T_OFF(void)
{	TIM2->ARR=8-1;
	TIM2->CNT=0;
	TIM2->CR1|=1;
	while(!(TIM2->SR&1)){}
		TIM2->SR&=~1;
		GPIOA->ODR=~GPIOA->ODR;
}
void T_ON(void)
{	TIM2->ARR=12-1;
	TIM2->CNT=0;
	TIM2->CR1|=1;
	while(!(TIM2->SR&1)){}
	TIM2->SR&=~1;
	GPIOA->ODR=~GPIOA->ODR;
}
