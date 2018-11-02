#ifndef __WDG_H__
#define __WDG_H__

void Iwdg_init(uint8_t Prescaler, uint16_t Reload);
void Wwdg_init(uint32_t WWDG_Prescaler, uint8_t WindowValue);

#endif
