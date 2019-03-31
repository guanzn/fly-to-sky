#include "timer3.h"

void Timer3_Init()
{
		NVIC_InitTypeDef NVIC_InitStructure;
		TIM_TimeBaseInitTypeDef TIM_InitStructure;
		
		RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE);
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		/******   ����TIM3����    ******/
		TIM_InitStructure.TIM_Period = 2000; //72Ԥ��Ƶ�£�1000Ϊһ����
		TIM_InitStructure.TIM_Prescaler = 72 - 1; //Ԥ��Ƶϵͳ�Զ���1������Ҫ��һ
		TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseInit( TIM3, &TIM_InitStructure);
		TIM_Cmd( TIM3, ENABLE); //��ʱ��ʹ��
		TIM_ITConfig( TIM3, TIM_IT_Update, ENABLE);  //�ж�ʹ��
	
		/******   ����NVIC����    ******/
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	
	
	
}

