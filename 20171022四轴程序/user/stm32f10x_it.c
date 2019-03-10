/* Includes ------------------------------------------------------------------*/
#include "public.h"
#include "stm32f10x_it.h"
#include "systick.h"
#include "USART.h"
#include "motorc.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 

#define HEAD1   1
#define HEAD2   2
#define LENGTH  3
#define DATA    4
#define CHECK   5
#define BOTTOM1 6

u8 LengthTotal=0;
u8 RecState = HEAD1;          //接收状态控制
u8 LengthNum=0;
u16 CheckSum=0;    //求和校验
u8 RecOk = 0;       //用于所接受数据是否正常
u8 RecTemp[USART_REC_LEN];  //最大缓存字节数，在USART.H中定义数目
uint8_t Count_1ms,Count_2ms,Count_4ms;
float pitch=0,roll=0,yaw=0; 		//欧拉角
extern u16 acc;
extern u8 DirectX;
extern u8 DirectY;
extern struct _pid x_pitch;
extern struct _pid y_roll;

/**********中断函数*********/
void TIM3_IRQHandler(void)//Timer3中断
{	
	if(TIM3->SR & TIM_IT_Update)
	{     
		TIM3->SR = ~TIM_FLAG_Update;//清除中断标志
		Count_1ms++;
		Count_2ms++;
		Count_4ms++;
  	if(Count_4ms>=4)
		{ 
			Count_4ms = 0;
			if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
			{
				balance_pid(pitch,roll,yaw);
			}
		}
	}
}
void USART1_IRQHandler(void)                	//串口1中断服务程序
	{
	u8 Res,i;
	if(USART_GetITStatus(USART1, USART_IT_ORE) != RESET)  //接收中断
	{USART_ReceiveData(USART1);}
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断
		{
			Res =USART_ReceiveData(USART1);	//读取接收到的数据
			usart1_send_char(Res);
			switch(RecState)
			{
					case HEAD1:
							if(Res == 0xAA)
							{
									RecState = HEAD2;
							}
							break;
					case HEAD2:
							if(Res == 0x5A)
							{
									RecState = LENGTH;
							}
							else if(Res == 0xAA)
							{
									RecState = HEAD2;
							}
							else
							{
									RecState = HEAD1;
							}
							break;
					case LENGTH:
							if(Res <= USART_REC_LEN)
							{
								LengthTotal = Res;
								RecState = DATA;
							}
							else
							{
								RecState = HEAD1;
							}
							break;
					case DATA:
							RecTemp[LengthNum] = Res;
							CheckSum = CheckSum + Res;
							LengthNum = LengthNum + 1;
							if(LengthNum == LengthTotal)
							{
									LengthNum = 0;
									RecState = CHECK;
									CheckSum = CheckSum % 256;
							}
							break;
					case CHECK:
							if(CheckSum == Res)
							{
								RecState = BOTTOM1;
							}
							else
							{
								RecState = HEAD1;
							}
							CheckSum = 0;
							break;
					case BOTTOM1:
							if(Res == 0x4D)
							{
									RecOk = 1;
							}
							RecState = HEAD1;
							break;
			}
				if(RecOk)
				{
					RecOk = 0;
					for(i=0;i<LengthTotal;i++)
					{					
						USART_RX_BUF[i]=RecTemp[i];
					}
					switch(LengthTotal) 
					{
							case 1:
									acc = USART_RX_BUF[0]*50;
									DirectX = 100;
									DirectY = 100;
									break;
							case 3:
									acc = USART_RX_BUF[0]*50;
									DirectX = USART_RX_BUF[1];
									DirectY = USART_RX_BUF[2];
									break;
							case 10:
									acc = USART_RX_BUF[0]*50;
									DirectX = 100;
									DirectY = 100;
									x_pitch.kp = USART_RX_BUF[1]/10.0;
									x_pitch.ki = USART_RX_BUF[2]/10.0;
									x_pitch.kd = USART_RX_BUF[3]/10.0;
									y_roll.kp = USART_RX_BUF[4]/10.0;
									y_roll.ki = USART_RX_BUF[5]/10.0;
									y_roll.kd = USART_RX_BUF[6]/10.0;
									break;
							case 12:
									acc = USART_RX_BUF[0]*50;
									DirectX = USART_RX_BUF[1];
									DirectY = USART_RX_BUF[2];
									x_pitch.kp = USART_RX_BUF[3]/10.0;
									x_pitch.ki = USART_RX_BUF[4]/10.0;
									x_pitch.kd = USART_RX_BUF[5]/10.0;
									y_roll.kp = USART_RX_BUF[6]/10.0;
									y_roll.ki = USART_RX_BUF[7]/10.0;
									y_roll.kd = USART_RX_BUF[8]/10.0;
							
					}
					
				}
   		 
     } 
} 












