#ifndef __TIMER_H__
#define __TIMER_H__

typedef enum 
{
    TIM_Prescaler7200 = 7199,
}enTIM_Prescaler;
    
void Timer_Init(uint16_t TIM_Prescaler, uint16_t TIM_Period);

#endif
