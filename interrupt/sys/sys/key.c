#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "delay.h"
#include "key.h"

void Key_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    
    /* key0 GPIO_Pin_4, key1 GPIO_Pin_3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;				 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    return;
}

/* Mode 为1时连续 */
FlagStatus KeyScan(uint32_t u32Mode, uint16_t u16Key)
{
    static uint8_t u8Key = SET;

    if(KeyContinueMode == u32Mode)
    {
        u8Key = SET;
    }
    
    if(u8Key && !GPIO_ReadInputDataBit(GPIOE, u16Key))
    {
        delay_ms(10);
        if(!GPIO_ReadInputDataBit(GPIOE, u16Key))
        {
            u8Key = RESET;
            return SET;
        }
    }
    else if(GPIO_ReadInputDataBit(GPIOE, u16Key))
    {
        u8Key = SET;
    }
    return RESET;
}






