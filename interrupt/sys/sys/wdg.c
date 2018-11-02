#include "stm32f10x.h"
#include "wdg.h"


/**********************************************
*
*           iwdg 初始化
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
*           wwdg 初始化
*
***********************************************/

void Wwdg_init(uint32_t WWDG_Prescaler, uint8_t WindowValue)
{
    NVIC_InitTypeDef NVIC_InitStruct;

    /* 首先设置中断优先级分组 */
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* 1、开启窗口看门狗时钟 */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
    /* 2、设置分频系数 */
    WWDG_SetPrescaler(WWDG_Prescaler);
    /* 3、设置上窗口值 */
    WWDG_SetWindowValue(WindowValue);
    /* 4、开启中断 */
    WWDG_EnableIT();

    /* 5、开启总中断 */
    NVIC_InitStruct.NVIC_IRQChannel = WWDG_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);
    /* 6、使能看门狗   使能的时候同样不能大于上窗口值，否则同样会产生复位 */
    WWDG_Enable(WindowValue);

    return;
}










