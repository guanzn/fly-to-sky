#include "timer3.h"

void Timer3_Init()
{
		NVIC_InitTypeDef NVIC_InitStructure;
		TIM_TimeBaseInitTypeDef TIM_InitStructure;
		
		RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE);
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		/******   设置TIM3参数    ******/
		TIM_InitStructure.TIM_Period = 2000; //72预分频下，1000为一毫秒
		TIM_InitStructure.TIM_Prescaler = 72 - 1; //预分频系统自动加1，故需要减一
		TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseInit( TIM3, &TIM_InitStructure);
		TIM_Cmd( TIM3, ENABLE); //定时器使能
		TIM_ITConfig( TIM3, TIM_IT_Update, ENABLE);  //中断使能
	
		/******   设置NVIC参数    ******/
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	
	
	
}

