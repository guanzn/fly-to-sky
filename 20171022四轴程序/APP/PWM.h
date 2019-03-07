#ifndef _PWM_H
#define _PWM_H
#include "stm32f10x.h"


void PWM_Init(void);
void PWM_Output(int16_t duty1,int16_t duty2,int16_t duty3,int16_t duty4);


#endif


