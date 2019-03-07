#include "systick.h"
void delay(u32 i)
{
		
		while(i--);  //6000000大概一秒
}
void delay_us(u32 i)  //最大延时为1864135us
{
		u32 temp;
		SysTick->LOAD = 9*i;    //设置重装数值，72MHz下使用
		SysTick->CTRL = 0X01;   //使能systick，减到零不触发中断，采用外部时钟，
		SysTick->VAL = 0;      //清零计数器
		do
		{
				temp = SysTick->CTRL;  //读取当前倒计数值
		}
		while((temp & 0X01) && (temp & (1<<16)));   //等待时间到达
		SysTick->CTRL = 0; //关闭计数器
		SysTick->VAL  = 0; //清空计数器
}
void delay_ms(u32 i)  //最大延时1864ms
{
		u32 temp;
		SysTick->LOAD = 9000*i;    //设置重装数值，72MHz下使用
		SysTick->CTRL = 0X01;   //使能systick，减到零不触发中断，采用外部时钟，
		SysTick->VAL = 0;      //清零计数器
		do
		{
				temp = SysTick->CTRL;  //读取当前倒计数值
		}
		while((temp & 0X01) && !(temp & (1<<16)));   //等待时间到达
		SysTick->CTRL = 0; //关闭计数器
		SysTick->VAL  = 0; //清空计数器
}

