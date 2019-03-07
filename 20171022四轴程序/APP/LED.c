#include "led.h"
#include "public.h"

void RCC_HSE_Configuration(void) //HSE??PLL??,PLL??SYSCLK 
{ 
	ErrorStatus HSEStartUpStatus;
	RCC_DeInit(); //������RCC�Ĵ�������Ϊȱʡֵ 
	RCC_HSEConfig(RCC_HSE_ON); // �����ⲿ���پ���HSE��HSE����򿪣�ON��
  HSEStartUpStatus = RCC_WaitForHSEStartUp();  
	if(HSEStartUpStatus == SUCCESS) //�ȴ�HSE����SUCCESS:HSE�����ȶ��Ҿ���
	{  
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);//  
		 RCC_PCLK2Config(RCC_HCLK_Div1); //     
		 RCC_PCLK1Config(RCC_HCLK_Div2); /*????AHB??(PCLK1)RCC_HCLK_Div2��APB1?? = HCLK / 2*/
		 RCC_PLLConfig(RCC_PLLSource_HSE_Div2, RCC_PLLMul_9);//PLLCK = 16MHz/2*9=72MHz  
		 RCC_PLLCmd(ENABLE); 	 /*ʹ��PLL */ 
		 while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET){} ;//�ȴ�PLL���� 
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);  //��PLL����Ϊϵͳʱ��Դ 
		 while(RCC_GetSYSCLKSource() != 0x08);     //�ȴ�ϵͳʱ��Դ������
  }
}

void LED_Init()  //LED��ʼ������
{
		GPIO_InitTypeDef 	GPIO_InitStructure;//����һ���ṹ�������������ʼ��GPIO
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); /* ����GPIOʱ�� */
//	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

		/*  ����GPIO��ģʽ��IO�� */
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

