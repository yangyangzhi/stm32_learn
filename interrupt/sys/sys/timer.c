#include "stm32f10x.h"
#include "timer.h"
#include "stm32f10x_tim.h"

void Timer_Init(uint16_t TIM_Prescaler, uint16_t TIM_Period)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    /* 1������ʹ�� */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    /* 2����ʱ����ʼ�� */
    TIM_TimeBaseInitStruct.TIM_Prescaler = TIM_Prescaler;
    TIM_TimeBaseInitStruct.TIM_Period = TIM_Period;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);

    /* 3���ж����� */
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    /* 4�������жϿ������ж� */
    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);

    /* ʹ�ܶ�ʱ�� */
    TIM_Cmd(TIM2, ENABLE);
    
}

























