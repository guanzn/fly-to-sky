#include "USART.h"

//拆字节
#define BYTE0(dwTemp)       (*(char *)(&dwTemp))   //0-7位
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1)) //8-15
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2)) //16-23
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))   //24-31
	

u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
void USART1_Init(u32 baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;	//声明一个结构体变量，用来初始化GPIO
	USART_InitTypeDef  USART_InitStructure;	  //串口结构体定义
	NVIC_InitTypeDef NVIC_InitStructure;//中断结构体定义
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	 //打开时钟
	
	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;  //TX			   //串口输出PA9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	    //复用推挽输出
	GPIO_Init(GPIOA,&GPIO_InitStructure);  /* 初始化串口输入IO */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//RX			 //串口输入PA10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;		  //模拟输入
	GPIO_Init(GPIOA,&GPIO_InitStructure); /* 初始化GPIO */

	/* 设置NVIC参数 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);    
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 	   //打开USART1的全局中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 	 //抢占优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 			//响应优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			 //使能
	NVIC_Init(&NVIC_InitStructure);
	
	USART_InitStructure.USART_BaudRate=baud;   //波特率设置为9600	//波特率
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;		//数据长8位
	USART_InitStructure.USART_StopBits=USART_StopBits_1;			//1位停止位
	USART_InitStructure.USART_Parity=USART_Parity_No;				//无效验
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //失能硬件流
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;	 //开启发送和接受模式
	USART_Init(USART1,&USART_InitStructure);	/* 初始化USART1 */

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//使能或者失能指定的USART中断 接收中断
	USART_Cmd(USART1, ENABLE);		   /* 使能USART1 */	
	USART_ClearFlag(USART1,USART_FLAG_TC);//清除USARTx的待处理标志位




}

void usart1_send_char(u8 c)
{

	USART1->DR=c;  
	while((USART1->SR&0X40)==0);//等待上一次发送完毕    	
} 

//传送数据给匿名四轴上位机软件(V2.6版本)
//fun:功能字. 0XA0~0XAF
//data:数据缓存区,最多28字节!!
//len:data区有效数据个数
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//最多28字节数据 
	send_buf[len+3]=0;	//校验数置零
	send_buf[0]=0X88;	//帧头
	send_buf[1]=fun;	//功能字
	send_buf[2]=len;	//数据长度
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//复制数据
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//计算校验和	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//发送数据到串口1 
}
//发送加速度传感器数据和陀螺仪数据
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
void mpu6050_send_data(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz)
{
	u8 tbuf[12]; 
	tbuf[0]=(aacx>>8)&0XFF;
	tbuf[1]=aacx&0XFF;
	tbuf[2]=(aacy>>8)&0XFF;
	tbuf[3]=aacy&0XFF;
	tbuf[4]=(aacz>>8)&0XFF;
	tbuf[5]=aacz&0XFF; 
	tbuf[6]=(gyrox>>8)&0XFF;
	tbuf[7]=gyrox&0XFF;
	tbuf[8]=(gyroy>>8)&0XFF;
	tbuf[9]=gyroy&0XFF;
	tbuf[10]=(gyroz>>8)&0XFF;
	tbuf[11]=gyroz&0XFF;
	usart1_niming_report(0XA1,tbuf,12);//自定义帧,0XA1
}	
//通过串口1上报结算后的姿态数据给电脑
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
//roll:横滚角.单位0.01度。 -18000 -> 18000 对应 -180.00  ->  180.00度
//pitch:俯仰角.单位 0.01度。-9000 - 9000 对应 -90.00 -> 90.00 度
//yaw:航向角.单位为0.1度 0 -> 3600  对应 0 -> 360.0度
void usart1_report_imu(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz,short roll,short pitch,short yaw)
{
	u8 tbuf[28]; 
	u8 i;
	for(i=0;i<28;i++)tbuf[i]=0;//清0
	tbuf[0]=(aacx>>8)&0XFF;
	tbuf[1]=aacx&0XFF;
	tbuf[2]=(aacy>>8)&0XFF;
	tbuf[3]=aacy&0XFF;
	tbuf[4]=(aacz>>8)&0XFF;
	tbuf[5]=aacz&0XFF; 
	tbuf[6]=(gyrox>>8)&0XFF;
	tbuf[7]=gyrox&0XFF;
	tbuf[8]=(gyroy>>8)&0XFF;
	tbuf[9]=gyroy&0XFF;
	tbuf[10]=(gyroz>>8)&0XFF;
	tbuf[11]=gyroz&0XFF;	
	tbuf[18]=(roll>>8)&0XFF;
	tbuf[19]=roll&0XFF;
	tbuf[20]=(pitch>>8)&0XFF;
	tbuf[21]=pitch&0XFF;
	tbuf[22]=(yaw>>8)&0XFF;
	tbuf[23]=yaw&0XFF;
	usart1_niming_report(0XAF,tbuf,28);//飞控显示帧,0XAF
}  
//以上来自
void Data_Send_Status(float Pitch,float Roll,float Yaw)
{
	unsigned char j=0;
	unsigned char _cnt=0;
	unsigned int _temp;
	u8 data_to_send[50];
	_temp = (int)(Roll);//*100);
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = 0-(int)(Pitch);//*100);
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = (int)(Yaw);//*100);
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = 0;
		
//串口发送数据
	for(j=0;j<_cnt;j++)
		usart1_send_char(data_to_send[j]);
}




