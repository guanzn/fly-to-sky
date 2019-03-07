#include "led.h"
#include "public.h"

void RCC_HSE_Configuration(void) //HSE??PLL??,PLL??SYSCLK 
{ 
	ErrorStatus HSEStartUpStatus;
	RCC_DeInit(); //将外设RCC寄存器重设为缺省值 
	RCC_HSEConfig(RCC_HSE_ON); // 设置外部高速晶振（HSE）HSE晶振打开（ON）
  HSEStartUpStatus = RCC_WaitForHSEStartUp();  
	if(HSEStartUpStatus == SUCCESS) //等待HSE起振，SUCCESS:HSE晶振稳定且就绪
	{  
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);//  
		 RCC_PCLK2Config(RCC_HCLK_Div1); //     
		 RCC_PCLK1Config(RCC_HCLK_Div2); /*????AHB??(PCLK1)RCC_HCLK_Div2棗APB1?? = HCLK / 2*/
		 RCC_PLLConfig(RCC_PLLSource_HSE_Div2, RCC_PLLMul_9);//PLLCK = 16MHz/2*9=72MHz  
		 RCC_PLLCmd(ENABLE); 	 /*使能PLL */ 
		 while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET){} ;//等待PLL启动 
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);  //将PLL设置为系统时钟源 
		 while(RCC_GetSYSCLKSource() != 0x08);     //等待系统时钟源的启动
  }
}

void LED_Init()  //LED初始化函数
{
		GPIO_InitTypeDef 	GPIO_InitStructure;//声明一个结构体变量，用来初始化GPIO
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); /* 开启GPIO时钟 */
//	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

		/*  配置GPIO的模式和IO口 */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
}  

void LED_Display()
{
	u16 i;
	for(i=0;i<2;i++)
	{
		GPIO_SetBits( GPIOB, GPIO_Pin_1);
		delay(2000000);   
		GPIO_ResetBits( GPIOB, GPIO_Pin_1);
		delay(2000000);
	}		
}

