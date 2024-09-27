#include "stm32f407xx.h"
void UART2_SendChar(char c);
void UART2_SendString(char *string);
char UART2_GetChar(void);
void delay(int n);

int main(void)
{
	char data;
	RCC->APB1ENR |= (1<<17);
	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER |= (2<<4);
	GPIOA->MODER |= (2<<6);
	GPIOA->AFR[0] |= (7<<8);
	GPIOA->AFR[0] |= (7<<12);
	USART2->CR1 = 0x00;
	USART2->CR1 |= (1<<13);
	USART2->CR1 &= ~(1<<12);
	USART2->BRR=(3<<0)|(104<<4);
	USART2->CR1 |= (1<<2);
	USART2->CR1 |= (1<<3);
	
	while(1)
	{
		UART2_SendString("RVCE\n");
		delay(1000);
		data=UART2_GetChar();
		UART2_SendChar(data);
		UART2_SendChar('R');
		UART2_SendChar('V');
		UART2_SendChar('C');
		UART2_SendChar('E');
		UART2_SendChar('\n');
	}
}

void UART2_SendString(char *string)
{
	while(*string)UART2_SendChar(*string++);
}

void UART2_SendChar(char c)
{
	USART2->DR=c;
	while(!(USART2->SR&(1<<6)));
}

char UART2_GetChar(void)
{
	char temp;
	while(!(USART2->SR&(1<<5)));
	temp=USART2->DR;
	return temp;
}

void delay(int n)
{
	int i;
	for(;n>0;n--)
	for(i=0;i<3195;i++);
}
