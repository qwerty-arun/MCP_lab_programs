#include "stm32f4xx.h"
void delay(int n);

int main(void)
{
	RCC->AHB1ENR |= (0x10 | 0x01);   // Enable clock for GPIOA and GPIOE
	GPIOE->MODER |= 0x00000154;      // Set GPIOE pins for output

	// Rotate 30 degrees clockwise (17 steps for a 1.8° step angle motor): 30/1.8 nearly equals 17
	for (int step = 0; step < 17; step++)
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

void delay(int n)
{
	int i, j;
	for (j = 0; j < n; j++)
		for (i = 0; i < 2200; i++);
}
