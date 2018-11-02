#include "stm32f10x.h"
#include "stdio.h"

void CheckRestInfo()
{
    do
    {
        if(RCC_GetFlagStatus(RCC_FLAG_PORRST))
        {
            printf("上电/掉电复位！\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_SFTRST))
        {
            printf("软件复位！\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST))
        {
            printf("独立看门狗复位！\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_WWDGRST))
        {
            printf("窗口看门狗复位！\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_LPWRRST))
        {
            printf("低功耗复位标志！\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_PINRST))
        {
            printf("NRST引脚复位！\n");
            break;
        }
    }while(0);
    
    RCC_ClearFlag();
}

