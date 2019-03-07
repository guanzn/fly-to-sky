#include "key.h"
#include "systick.h"

void Key_Init()
{
		GPIO_InitTypeDef GPIO_InitStructure;
		
		SystemInit();
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOE, ENABLE);
		GPIO_InitStructure.GPIO_Pin = K_UP;   // | K_DOWN | K_LEFT | K_RIGHT;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
		GPIO_Init( GPIOA, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = K_DOWN | K_LEFT | K_RIGHT;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_Init( GPIOE, &GPIO_InitStructure);
	
		GPIO_ResetBits( GPIOA,K_UP);
	
}
void key_pros()
{
		if(k_up == 1)
		{
				delay_ms(10);
				if(k_up == 1)
				{
						GPIO_Write(GPIOC, 0xfe);
				}
				while(k_up);			
		}
		if(k_down == 0)
		{
				delay_ms(10);
				if(k_down == 0)
				{
						GPIO_Write(GPIOC, 0xfd);
				}
				while(!k_down);			
		}
		if(k_left == 0)
		{
				delay_ms(10);
				if(k_left == 0)
				{
						GPIO_Write(GPIOC, 0xfb);
				}
				while(!k_left);			
		}				
		if(k_right == 0)
		{
				delay_ms(10);
				if(k_right == 0)
				{
						GPIO_Write(GPIOC, 0xf7);
				}
				while(!k_right);			
		}
}
