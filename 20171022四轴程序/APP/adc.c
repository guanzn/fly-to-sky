#include "adc.h"

void adc_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO|RCC_APB2Periph_ADC1,ENABLE);

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//12M  最大14M 设置ADC时钟（ADCCLK）

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;//ADC
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;	//模拟输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);


	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; 
	ADC_InitStructure.ADC_ScanConvMode = DISABLE; 
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; 
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 
	ADC_InitStructure.ADC_NbrOfChannel = 1; 
	ADC_Init(ADC1, &ADC_InitStructure);
	
	//设置指定ADC的规则组通道，设置它们的转化顺序和采样时间
	ADC_RegularChannelConfig(ADC1,ADC_Channel_7,1,ADC_SampleTime_239Cycles5);
	
	ADC_Cmd(ADC1,ENABLE);	

	ADC_ResetCalibration(ADC1);//重置指定的ADC的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));//获取ADC重置校准寄存器的状态
	
	ADC_StartCalibration(ADC1);//开始指定ADC的校准状态
	while(ADC_GetCalibrationStatus(ADC1));//获取指定ADC的校准程序

	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//使能或者失能指定的ADC的软件转换启动功能
}
	u32 adc;
u8 adc_bat(u8 adc_times)
{
	u8 i;

	u8 adc_batV;
	adc=0;
	for(i=0;i<adc_times;i++)//读取50次的AD数值取其平均数较为准确	
	{
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
		delay(60000);//while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//转换结束标志位
		adc = adc+ADC_GetConversionValue(ADC1);//返回最近一次ADCx规则组的转换结果		
		delay(60000);
	}
	adc_batV=adc*2*3.3/4096.0;//由于锂电池供电最大4.3v，其一半电压仅2.15V，故考虑使用一个字节u8来表示电压，此处不乘以2
	return adc_batV;//实际电压的一半，所得数值放大100倍
}



