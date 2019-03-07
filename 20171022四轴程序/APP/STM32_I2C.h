#ifndef __MYIIC_H
#define __MYIIC_H
#include "sys.h"
#include "stdint.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//IIC���� ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/9
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
 	   		   
//IO��������
// #define SDA_IN()  {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=8<<11;}
// #define SDA_OUT() {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=3<<11;}

// #define SDA_IN()  {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=0X00080000;}
// #define SDA_OUT() {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=0X00030000;}

//IO��������	 
#define IIC_SCL_6050    PBout(10) //SCL
#define IIC_SDA_6050    PBout(11) //SDA	 
#define READ_SDA_6050   PBin(11)  //����SDA 

// #define IIC_SCL    PAout(11) //SCL
// #define IIC_SDA    PAout(12) //SDA	 
// #define READ_SDA   PAin(12)  //����SDA 

/*****************************************************************
�����Ǵ�DMP�ļ�ֱ��COPY������
******************************************************************/

//#define CLI()      __set_PRIMASK(1)  
//#define SEI()      __set_PRIMASK(0)

#define BYTE0(dwTemp)       (*(char *)(&dwTemp))
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

#define true 1
#define false 0 
#define bool  uint8_t

#define TRUE  0
#define FALSE -1

/*
#define MPU6050_READRATE			1000	//6050��ȡƵ��
#define MPU6050_READTIME			0.001	//6050��ȡʱ����
#define EE_6050_ACC_X_OFFSET_ADDR	0
#define EE_6050_ACC_Y_OFFSET_ADDR	1
#define EE_6050_ACC_Z_OFFSET_ADDR	2
#define EE_6050_GYRO_X_OFFSET_ADDR	3
#define EE_6050_GYRO_Y_OFFSET_ADDR	4
#define EE_6050_GYRO_Z_OFFSET_ADDR	5
*/
//0��ʾд
#define	I2C_Direction_Transmitter   0
//����ʾ��
#define	I2C_Direction_Receiver      1	 
/*====================================================================================================*/
/*====================================================================================================*/
bool i2cWriteBuffer(uint8_t addr_, uint8_t reg_, uint8_t len_, uint8_t *data);
bool i2cWrite(uint8_t addr_, uint8_t reg_, uint8_t data);
bool i2cRead(uint8_t addr_, uint8_t reg_, uint8_t len, uint8_t* buf);
void i2cInit(void);
uint16_t i2cGetErrorCounter(void);
static void i2cUnstick(void);

int8_t i2cwrite(uint8_t addr, uint8_t reg, uint8_t len, uint8_t * data);
int8_t i2cread(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf);
/*====================================================================================================*/
/*====================================================================================================*/


#endif
















