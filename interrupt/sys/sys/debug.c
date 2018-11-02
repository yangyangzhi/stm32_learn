#include "stm32f10x.h"
#include "stdio.h"

void CheckRestInfo()
{
    do
    {
        if(RCC_GetFlagStatus(RCC_FLAG_PORRST))
        {
            printf("�ϵ�/���縴λ��\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_SFTRST))
        {
            printf("�����λ��\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST))
        {
            printf("�������Ź���λ��\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_WWDGRST))
        {
            printf("���ڿ��Ź���λ��\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_LPWRRST))
        {
            printf("�͹��ĸ�λ��־��\n");
            break;
        }
        if(RCC_GetFlagStatus(RCC_FLAG_PINRST))
        {
            printf("NRST���Ÿ�λ��\n");
            break;
        }
    }while(0);
    
    RCC_ClearFlag();
}

