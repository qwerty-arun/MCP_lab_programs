#include "stm32f4xx.h"
void UART2_SendChar(char c);			//it is UART only not USART here
void UART2_SendString(char*string);
char UART2_GetChar(void);
void delay(int n);
int main(void)
{	char data;
	RCC->APB1ENR|=(1<<17);
	RCC->AHB1ENR|=(1<<0);
	GPIOA->MODER|=(2<<4);
	GPIOA->MODER|=(2<<6);
	GPIOA->AFR[0] |=(7<<8);
	GPIOA->AFR[0] |=(7<<12);
	USART2->CR1=0x00;				// here it is USART not UART
	USART2->CR1|=(1<<13);
	USART2->CR1&=~(1<<12);
	USART2->BRR=(3<<0)|(104<<4);	// HERE baud rate is set to 9600 not 115200(in lab manual it is mentioned)
	USART2->CR1 |=(1<<2);
	USART2->CR1 |=(1<<3);
	while (1)
	{	UART2_SendString("Hello world\n"); //here put the string that is given to you in exam
		delay(1000);
		//the below code is not required if they mention only one string
		data=UART2_GetChar();
		UART2_SendChar(data);
		UART2_SendChar("R");
		//same as it is in above line you can send the string but the earlier one is preferrable
	}
}
void  UART2_SendString(char*string)
{	while(*string)UART2_SendChar(*string++);
}
void UART2_SendChar(char c)
{	USART2->DR =c;
	while(!(USART2->SR&(1<<6)));
}
// the below code is optional 
char UART2_GetChar(void)
{	char temp;
	while(!(USART2->SR&(1<<5)));
	temp=USART2->DR;
	return temp;
}
void delay(int n)
{	int i;
	for(;n>0;n--)
	for(i=0;i<3195;i++);
}
