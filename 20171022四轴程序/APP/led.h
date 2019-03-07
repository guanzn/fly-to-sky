#ifndef _led_H
#define _led_H
#include "stm32f10x.h"

void RCC_HSE_Configuration(void);//设置PLL时钟源及倍频系数

void LED_Init(void);  //LED初始化函数
void LED_Display(void);

#endif


