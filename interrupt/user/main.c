#include "stm32f10x.h"
#include <stdio.h>
#include "delay.h"
#include "usart.h"
#include "key.h"
#include "led.h"
#include "interrupt.h"
#include "wdg.h"
#include "debug.h"
#include "timer.h"
#define Debug  (1)

void Periph_Init()
{
    int x = 0;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(9600);
    delay_init();
    for(x = 0; x < 1; x++)
        delay_ms(1000);
    CheckRestInfo();
    
#if Debug
    printf("uart_init OK !\n");
#endif

    delay_init();
#if Debug
    printf("delay_init OK !\n");
#endif

    LED_Init();
#if Debug
    printf("led_init OK !\n");
#endif

    ExternInterruptInit();
#if Debug
    printf("interrupt_init OK !\n");
#endif

#if 0    
    Iwdg_init(IWDG_Prescaler_64, 0x4E2);
#if Debug
    printf("iwdg_init OK !\n");
#endif

    Wwdg_init(WWDG_Prescaler_8, 0x70);
#if Debug
    printf("wwdg_init OK !\n");
#endif
#endif

    Timer_Init(TIM_Prescaler7200, 4999);
#if Debug
        printf("timer2_init OK !\n");
#endif

    Key_Init();
    return;
}

int main(void)
{
	Periph_Init();
    led0 = 0x0;
	while(1)
	{
        
	}
}
