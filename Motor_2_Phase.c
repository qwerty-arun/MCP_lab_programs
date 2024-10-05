#include "stm32f4xx.h"
void delay(int n);
int main(void)
{
	RCC->AHB1ENR|=(0x10|0x01);
	GPIOE->MODER|=0x00000154;
	while(1)
	{ if (GPIOA->IDR &(1<<0))
		{	//anticlockwise
		 	GPIOE->ODR =0x00000009;
		 	delay(1); 
		 	GPIOE->ODR =0x0000000C;
		 	delay(1);
		 	GPIOE->ODR =0x00000006;
		 	delay(1);
		 	GPIOE->ODR =0x00000003;
		 	delay(1);
		}
	else
		{	//clockwise
			GPIOE->ODR =0x00000003;
	 		delay(1); 
	 		GPIOE->ODR =0x00000006;
	 		delay(1);
	 		GPIOE->ODR =0x0000000C;
	 		delay(1);
	 		GPIOE->ODR =0x00000009;
	 		delay(1);
		}
	}
void delay(int n)
{ int i,j;
  for(j=0;j<n;j++)
  for(i=0;i<2200;i++);
}
