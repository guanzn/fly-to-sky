#ifndef __MPUIIC_H
#define __MPUIIC_H
#include "stm32f10x.h"


#define MPU_SDA_IN()  {GPIOB->CRH&=0XF0FFFFFF;GPIOB->CRH|=(unsigned int)8<<24;}//GPIOB7修改iic的io需修改此处
#define MPU_SDA_OUT() {GPIOB->CRH&=0XF0FFFFFF;GPIOB->CRH|=(unsigned int)3<<24;}
//IO操作函数	 
/*模拟IIC端口输出输入定义*/
#define SCL_H         GPIOB->BSRR = GPIO_Pin_15
#define SCL_L         GPIOB->BRR  = GPIO_Pin_15
   
#define SDA_H         GPIOB->BSRR = GPIO_Pin_14
#define SDA_L         GPIOB->BRR  = GPIO_Pin_14

#define SCL_read      GPIOB->IDR  & GPIO_Pin_15
#define SDA_read      GPIOB->IDR  & GPIO_Pin_14

//IIC所有操作函数


//IIC所有操作函数
void MPU_IIC_Delay(void);				//MPU IIC延时函数
void MPU_IIC_Init(void);                //初始化IIC的IO口				 
void MPU_IIC_Start(void);				//发送IIC开始信号
void MPU_IIC_Stop(void);	  			//发送IIC停止信号
void MPU_IIC_Send_Byte(u8 SendByte);			//IIC发送一个字节
u8 MPU_IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 MPU_IIC_Wait_Ack(void); 				//IIC等待ACK信号
void MPU_IIC_Ack(void);					//IIC发送ACK信号
void MPU_IIC_NAck(void);				//IIC不发送ACK信号

#endif
















