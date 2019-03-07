#include "PWM.h"

void PWM_Init()
{
		TIM_TimeBaseInitTypeDef TIM_InitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;
		TIM_OCInitTypeDef TIM_OCInitTypeDef;
		
		RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE);
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE);

//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		/******   设置TIM3参数    ******/	//PWM频率 = 72000000 / 6 / 1000 = 12Khz
		TIM_InitStructure.TIM_Period = 1000-1;  //35999预分频下，2000为一秒
		TIM_InitStructure.TIM_Prescaler = 6-1; //预分频系统自动加1，故需要减一
		TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseInit( TIM2, &TIM_InitStructure);
		TIM_Cmd( TIM2, ENABLE); //定时器使能
	
		/*  配置GPIO的模式和IO口 */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
//		GPIO_PinRemapConfig( GPIO_FullRemap_TIM2, ENABLE);
	
		TIM_OCInitTypeDef.TIM_OCMode = TIM_OCMode_PWM1;
		TIM_OCInitTypeDef.TIM_OutputState = TIM_OutputState_Enable; //PWM输出使能
		TIM_OCInitTypeDef.TIM_OCPolarity = TIM_OCPolarity_High;
		TIM_OC1Init( TIM2, &TIM_OCInitTypeDef);
		TIM_OC2Init( TIM2, &TIM_OCInitTypeDef);
		TIM_OC3Init( TIM2, &TIM_OCInitTypeDef);
		TIM_OC4Init( TIM2, &TIM_OCInitTypeDef);
		
		TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
		TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
		TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
		TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

}
void PWM_Output(int16_t duty1,int16_t duty2,int16_t duty3,int16_t duty4)
{
	if(duty1>1000)	duty1=1000;
	if(duty1<0)		duty1=0;
	if(duty2>1000)	duty2=1000;
	if(duty2<0)		duty2=0;
	if(duty3>1000)	duty3=1000;
	if(duty3<0)		duty3=0;
	if(duty4>1000)	duty4=1000;
	if(duty4<0)		duty4=0;
	
	TIM2->CCR1 = duty1;
	TIM2->CCR2 = duty2;
	TIM2->CCR3 = duty3;
	TIM2->CCR4 = duty4;
}

