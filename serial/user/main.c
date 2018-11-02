#include "stm32f10x.h"
//#include "stm32f10x_conf.h"
#include <stdio.h>
#include "delay.h"
#include "led.h"
#include "usart.h"
#define L (*(volatile int*)0x40010C0C)
#define L1 (*(volatile int*)0x4001180C)

int main(void)
{
	delay_init();
    LED_Init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Usart1_Init(9600);
	while(1)
	{
        delay_ms(200);
        L ^= 0x20;
	}
}



