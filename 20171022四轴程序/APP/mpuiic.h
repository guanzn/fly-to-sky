#ifndef __MPUIIC_H
#define __MPUIIC_H
#include "stm32f10x.h"


#define MPU_SDA_IN()  {GPIOB->CRH&=0XF0FFFFFF;GPIOB->CRH|=(unsigned int)8<<24;}//GPIOB7�޸�iic��io���޸Ĵ˴�
#define MPU_SDA_OUT() {GPIOB->CRH&=0XF0FFFFFF;GPIOB->CRH|=(unsigned int)3<<24;}
//IO��������	 
/*ģ��IIC�˿�������붨��*/
#define SCL_H         GPIOB->BSRR = GPIO_Pin_15
#define SCL_L         GPIOB->BRR  = GPIO_Pin_15
   
#define SDA_H         GPIOB->BSRR = GPIO_Pin_14
#define SDA_L         GPIOB->BRR  = GPIO_Pin_14

#define SCL_read      GPIOB->IDR  & GPIO_Pin_15
#define SDA_read      GPIOB->IDR  & GPIO_Pin_14

//IIC���в�������


//IIC���в�������
void MPU_IIC_Delay(void);				//MPU IIC��ʱ����
void MPU_IIC_Init(void);                //��ʼ��IIC��IO��				 
void MPU_IIC_Start(void);				//����IIC��ʼ�ź�
void MPU_IIC_Stop(void);	  			//����IICֹͣ�ź�
void MPU_IIC_Send_Byte(u8 SendByte);			//IIC����һ���ֽ�
u8 MPU_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 MPU_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void MPU_IIC_Ack(void);					//IIC����ACK�ź�
void MPU_IIC_NAck(void);				//IIC������ACK�ź�

#endif
















