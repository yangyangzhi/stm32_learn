#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x_gpio.h"

#define KEY0    GPIO_Pin_4
#define KEY1    GPIO_Pin_3

typedef enum
{
    KeyUncontinueMode,
    KeyContinueMode,
    KeyInvalid,
}enKeyMode;

void Key_Init();
FlagStatus KeyScan(uint32_t u32Mode, uint16_t u16Key);











#endif

