#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "led.h"
/**********************************************
*
*           led IO�ڳ�ʼ��
*
***********************************************/
void LED_Init(void)
{
 
    GPIO_InitTypeDef  GPIO_InitStructure;
    	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE, ENABLE);

    /* led0 PB.5�˿����� */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; /* ����ͬʱ���ö������ */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_5);
    
    /* led0 PE.5�˿����� */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_SetBits(GPIOE,GPIO_Pin_5);

 return;
}








