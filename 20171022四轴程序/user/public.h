#ifndef _public_H
#define _public_H
#include "stm32f10x.h"
#include "misc.h"
#include "stm32f10x_exti.h"


/* pid±äÁ¿ */
struct _pid
{
	float kp;
	float ki;
	float kd;
	float integral;
	float newangle;
	float oldangle;	
	float oldoutput;
	float newoutput;
};

#endif


