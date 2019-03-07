#include "smg.h"
#include "systick.h"

u8 smg_table[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 
									 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71,};

void Smg_Init()
{
		GPIO_InitTypeDef  GPIO_InitStructure;
		SystemInit();
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = smg_duan;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init( GPIOC, &GPIO_InitStructure);
}
void Smg_Display()
{
		u8 i;
		for(i=0;i<16;i++)
		{
				GPIO_Write( GPIOC, ~(u16)(smg_table[i]));
				delay_ms(500);
		}
	
}


