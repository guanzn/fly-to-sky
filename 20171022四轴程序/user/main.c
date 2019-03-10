#include "public.h"
#include "systick.h"
#include "PWM.h"
#include "timer3.h"
#include "led.h"
#include "adc.h"
#include "stm32f10x_usart.h"
#include "USART.h"
#include "mpu6050.h"
#include "mpuiic.h"
#include "motorc.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 

struct _pid x_pitch;
struct _pid y_roll;
struct _pid z_yaw;
struct _pid direct;
u16 acc;
u8 DirectX =100;
u8 DirectY=100;

int main()	
{
	x_pitch.kp = 6;
	x_pitch.ki = 0;
	x_pitch.kd = 10;
	y_roll.kp = 6;
	y_roll.ki = 0;
	y_roll.kd = 10;
	z_yaw.kd =2;
	direct.kp = 2;
	direct.ki = 0;
	direct.kd = 5;
	SystemInit();
	RCC_HSE_Configuration();
	LED_Init();
	LED_Display();
	PWM_Init();
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	USART1_Init(9600);
	MPU_Init();				//初始化MPU6050 
	while(mpu_dmp_init()){}
	LED_Display();
	Timer3_Init();
 		
	while(1)
	{
		u16 batV;
		batV = adc_bat(50)*100;   //实际电压的一半，所得数值放大100倍
		usart1_send_char(0xAA);
		usart1_send_char(0x5A);
		usart1_send_char(01);
		usart1_send_char(batV%256);
		usart1_send_char(batV%256);
		usart1_send_char(0x4D);
		delay(50000);
			
	}
	
}


