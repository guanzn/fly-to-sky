#ifndef _led_H
#define _led_H
#include "stm32f10x.h"

void RCC_HSE_Configuration(void);//����PLLʱ��Դ����Ƶϵ��

void LED_Init(void);  //LED��ʼ������
void LED_Display(void);

#endif


