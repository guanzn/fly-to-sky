#ifndef _systick_H
#define _systick_H
#include "stm32f10x.h"

void delay_us(u32 i);//最大延时为1864135us
void delay_ms(u32 i);//最大延时1864ms
void delay(u32 i);

#endif
