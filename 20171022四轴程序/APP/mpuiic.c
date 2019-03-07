#include "mpuiic.h"
#include "systick.h"

 
 //MPU IIC ��ʱ����
void MPU_IIC_Delay(void)
{
	delay_us(2);
}

//��ʼ��IIC
void MPU_IIC_Init(void)
{					     
  GPIO_InitTypeDef  GPIO_InitStructure; 

RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  GPIO_SetBits(GPIOB,GPIO_Pin_14|GPIO_Pin_15);						 //PB15,PB14 �����	
 
}

//����IIC��ʼ�ź�
void MPU_IIC_Start(void)
{
	MPU_SDA_OUT();     //sda�����
	SDA_H;	  	  
	SCL_H;
	MPU_IIC_Delay();
 	SDA_L;//START:when CLK is high,DATA change form high to low 
	MPU_IIC_Delay();
	SCL_L;//ǯסI2C���ߣ�׼�����ͻ�������� 
	MPU_IIC_Delay();
}	  
//����IICֹͣ�ź�
void MPU_IIC_Stop(void)
{
	MPU_SDA_OUT();//sda�����
	SCL_L;
	SDA_L;//STOP:when CLK is high DATA change form low to high
 	MPU_IIC_Delay();
	SCL_H; 
	SDA_H;//����I2C���߽����ź�
	MPU_IIC_Delay();							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 MPU_IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	MPU_SDA_IN();      //SDA����Ϊ����
	SDA_H;MPU_IIC_Delay();	   
	SCL_H;MPU_IIC_Delay();	 
	while(SDA_read)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			MPU_IIC_Stop();
			return 1;
		}
	}
	SCL_L;//ʱ�����0 	   
	MPU_IIC_Delay();
	return 0;  
} 
//����ACKӦ��
void MPU_IIC_Ack(void)
{
	SCL_L;
	MPU_SDA_OUT();
	SDA_L;
	MPU_IIC_Delay();
	SCL_H;
	MPU_IIC_Delay();
	SCL_L;
}
//������ACKӦ��		    
void MPU_IIC_NAck(void)
{
	SCL_L;
	MPU_SDA_OUT();
	SDA_H;
	MPU_IIC_Delay();
	SCL_H;
	MPU_IIC_Delay();
	SCL_L;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void MPU_IIC_Send_Byte(u8 SendByte)
{                        
   u8 i=8;
	 MPU_SDA_OUT();
   while(i--)
   {
      SCL_L;
		  MPU_IIC_Delay();
      if(SendByte&0x80)
			{SDA_H; } 
      else 
      {  SDA_L;   }
      SendByte<<=1;
		  SCL_H;
      MPU_IIC_Delay();
    }
    SCL_L;
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 MPU_IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	MPU_SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        SCL_L; 
        MPU_IIC_Delay();
		SCL_H;
        receive<<=1;
        if(SDA_read)receive++;   
		MPU_IIC_Delay(); 
    }					 
    if (!ack)
        MPU_IIC_NAck();//����nACK
    else
        MPU_IIC_Ack(); //����ACK   
    return receive;
}


























