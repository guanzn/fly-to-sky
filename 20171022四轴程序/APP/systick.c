#include "systick.h"
void delay(u32 i)
{
		
		while(i--);  //6000000���һ��
}
void delay_us(u32 i)  //�����ʱΪ1864135us
{
		u32 temp;
		SysTick->LOAD = 9*i;    //������װ��ֵ��72MHz��ʹ��
		SysTick->CTRL = 0X01;   //ʹ��systick�������㲻�����жϣ������ⲿʱ�ӣ�
		SysTick->VAL = 0;      //���������
		do
		{
				temp = SysTick->CTRL;  //��ȡ��ǰ������ֵ
		}
		while((temp & 0X01) && (temp & (1<<16)));   //�ȴ�ʱ�䵽��
		SysTick->CTRL = 0; //�رռ�����
		SysTick->VAL  = 0; //��ռ�����
}
void delay_ms(u32 i)  //�����ʱ1864ms
{
		u32 temp;
		SysTick->LOAD = 9000*i;    //������װ��ֵ��72MHz��ʹ��
		SysTick->CTRL = 0X01;   //ʹ��systick�������㲻�����жϣ������ⲿʱ�ӣ�
		SysTick->VAL = 0;      //���������
		do
		{
				temp = SysTick->CTRL;  //��ȡ��ǰ������ֵ
		}
		while((temp & 0X01) && !(temp & (1<<16)));   //�ȴ�ʱ�䵽��
		SysTick->CTRL = 0; //�رռ�����
		SysTick->VAL  = 0; //��ռ�����
}

