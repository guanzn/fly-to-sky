#ifndef _USART_H
#define _USART_H
#include "stm32f10x.h"
#include "stm32f10x_usart.h"

void USART1_Init(u32 baud);
void usart1_send_char(u8 c);
#define USART_REC_LEN  			32  	//�����������ֽ��� 32
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;
void mpu6050_send_data(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz);
void usart1_report_imu(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz,short roll,short pitch,short yaw);

#endif
