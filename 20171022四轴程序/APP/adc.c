#include "adc.h"

void adc_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO|RCC_APB2Periph_ADC1,ENABLE);

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//12M  ���14M ����ADCʱ�ӣ�ADCCLK��

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;//ADC
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;	//ģ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);


	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; 
	ADC_InitStructure.ADC_ScanConvMode = DISABLE; 
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; 
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 
	ADC_InitStructure.ADC_NbrOfChannel = 1; 
	ADC_Init(ADC1, &ADC_InitStructure);
	
	//����ָ��ADC�Ĺ�����ͨ�����������ǵ�ת��˳��Ͳ���ʱ��
	ADC_RegularChannelConfig(ADC1,ADC_Channel_7,1,ADC_SampleTime_239Cycles5);
	
	ADC_Cmd(ADC1,ENABLE);	

	ADC_ResetCalibration(ADC1);//����ָ����ADC��У׼�Ĵ���
	while(ADC_GetResetCalibrationStatus(ADC1));//��ȡADC����У׼�Ĵ�����״̬
	
	ADC_StartCalibration(ADC1);//��ʼָ��ADC��У׼״̬
	while(ADC_GetCalibrationStatus(ADC1));//��ȡָ��ADC��У׼����

	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//ʹ�ܻ���ʧ��ָ����ADC�����ת����������
}
	u32 adc;
u8 adc_bat(u8 adc_times)
{
	u8 i;

	u8 adc_batV;
	adc=0;
	for(i=0;i<adc_times;i++)//��ȡ50�ε�AD��ֵȡ��ƽ������Ϊ׼ȷ	
	{
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
		delay(60000);//while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//ת��������־λ
		adc = adc+ADC_GetConversionValue(ADC1);//�������һ��ADCx�������ת�����		
		delay(60000);
	}
	adc_batV=adc*2*3.3/4096.0;//����﮵�ع������4.3v����һ���ѹ��2.15V���ʿ���ʹ��һ���ֽ�u8����ʾ��ѹ���˴�������2
	return adc_batV;//ʵ�ʵ�ѹ��һ�룬������ֵ�Ŵ�100��
}



