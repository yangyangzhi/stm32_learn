#include "stm32f10x.h"
#include "interrupt.h"

/**********************************************
*
*           外部中断初始化 key1
*
***********************************************/
void ExternInterruptInit()
{
    NVIC_InitTypeDef NVIC_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;
    
    /* 配置中断分组 */
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    /* 使用外部中断注意使能AFIO时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);

    /* 1、GPIO 初始化为输入模式 */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_3;
    GPIO_Init(GPIOE, &GPIO_InitStruct);
    /* 2、配置中断线 */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);

    /* 3、配置中断模式，使能EXTI中断 */
    EXTI_InitStruct.EXTI_Line = EXTI_Line3;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct);

    /* 4、打开 NVIC 中断，设置中断优先级 */
    NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&NVIC_InitStruct);
    
    return;
}









