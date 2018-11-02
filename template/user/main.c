#include "stm32f10x.h"
#include <stdio.h>
#include "delay.h"
#include "usart.h"

int main(void)
{
	delay_init();
	uart_init(9600);
	while(1)
	{
		delay_ms(500);
		printf("hello");
	}
}
