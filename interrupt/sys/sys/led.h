#ifndef __LED_H__
#define __LED_H__

#define BIT_BAND(addr, bit)  (((addr) - PERIPH_BASE) * 32 + (bit) * 4 + PERIPH_BB_BASE)
#define led0 (*(volatile int *)BIT_BAND(0x40010C0C, 5))
#define led1 (*(volatile int *)BIT_BAND(0x4001180C, 5))

void LED_Init(void);


#endif
