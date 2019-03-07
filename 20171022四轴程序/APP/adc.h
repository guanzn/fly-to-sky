#ifndef _adc_H
#define _adc_H
#include "stm32f10x.h"
#include "systick.h"
void adc_init(void);
u8 adc_bat(u8 adc_times,u8 int_time);

#endif
