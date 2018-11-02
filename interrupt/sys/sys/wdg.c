#include "stm32f10x.h"
#include "wdg.h"


/**********************************************
*
*           iwdg ��ʼ��
*
***********************************************/
void Iwdg_init(uint8_t Prescaler, uint16_t Reload)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    IWDG_SetPrescaler(Prescaler);
    IWDG_SetReload(Reload);
    IWDG_ReloadCounter();
    IWDG_Enable();

    return;
}

/**********************************************
*
*           wwdg ��ʼ��
*
***********************************************/

void Wwdg_init(uint32_t WWDG_Prescaler, uint8_t WindowValue)
{
    NVIC_InitTypeDef NVIC_InitStruct;

    /* ���������ж����ȼ����� */
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* 1���������ڿ��Ź�ʱ�� */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
    /* 2�����÷�Ƶϵ�� */
    WWDG_SetPrescaler(WWDG_Prescaler);
    /* 3�������ϴ���ֵ */
    WWDG_SetWindowValue(WindowValue);
    /* 4�������ж� */
    WWDG_EnableIT();

    /* 5���������ж� */
    NVIC_InitStruct.NVIC_IRQChannel = WWDG_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);
    /* 6��ʹ�ܿ��Ź�   ʹ�ܵ�ʱ��ͬ�����ܴ����ϴ���ֵ������ͬ���������λ */
    WWDG_Enable(WindowValue);

    return;
}










