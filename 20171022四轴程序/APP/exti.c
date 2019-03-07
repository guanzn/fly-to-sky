#include "exti.h"

void Exti_Init()   //外部中断2初始化
{
		GPIO_InitTypeDef GPIO_InitStructure;
		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		
		SystemInit();
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin = k1_left;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init( GPIOE, &GPIO_InitStructure);
	
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	
		EXTI_InitStructure.EXTI_Line = EXTI_Line2;
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStructure);
	
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
		NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn; //打开EXTI2全局中断
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //主中断级为0，最高
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;   //从中断级为0
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //使能
		NVIC_Init( &NVIC_InitStructure);
}




