#include "adc.h"




/*
* Pinout
 *	CHANNEL			ADC1	ADC2	ADC3
 *	0						PA0		PA0		PA0
 *	1						PA1		PA1		PA1
 *	2						PA2		PA2		PA2
 *	3						PA3		PA3		PA3
 *	4						PA4		PA4		PF6
 *	5						PA5		PA5		PF7
 *	6						PA6		PA6		PF8
 *	7						PA7		PA7		PF9
 *	8						PB0		PB0		PF10
 *	9						PB1		PB1		PF3
 *	10					PC0		PC0		PC0
 *	11					PC1		PC1		PC1
 *	12					PC2		PC2		PC2
 *	13					PC3		PC3		PC3
 *	14					PC4		PC4		PF4
 *	15					PC5		PC5		PF5
 *
 * |----------------------------------------------------------------------
 */



void ADCx_init(ADC_TypeDef* ADCx,uint8_t chanel){
	
	ADC_InitTypeDef ADC_InitStructure;

	if (ADCx==ADC1){RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);}
	else if (ADCx==ADC2){RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);}
	else if (ADCx==ADC3){RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);}
		
	
	if (chanel==ADC_Channel_0){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOA,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_1){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOA,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_2){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_2,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_2,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOA,GPIO_Pin_2,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_3){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_3,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_3,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOA,GPIO_Pin_3,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_4){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_4,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_4,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_6,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_5){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_5,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_5,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_7,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_6){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_6,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_6,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_8,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_7){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOA,GPIO_Pin_7,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOA,GPIO_Pin_7,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_9,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_8){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOB,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOB,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_10,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_9){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOB,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOB,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_3,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_10){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOC,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOC,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOC,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_11){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOC,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOC,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOC,GPIO_Pin_1,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_12){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOC,GPIO_Pin_2,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOC,GPIO_Pin_2,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOC,GPIO_Pin_2,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_13){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOC,GPIO_Pin_3,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOC,GPIO_Pin_3,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOC,GPIO_Pin_3,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_14){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOC,GPIO_Pin_4,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOC,GPIO_Pin_4,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_4,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
	else if (chanel==ADC_Channel_15){
		if (ADCx==ADC1) {GPIO_SETUP(GPIOC,GPIO_Pin_5,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC2) {GPIO_SETUP(GPIOC,GPIO_Pin_5,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
		else if (ADCx==ADC3) {GPIO_SETUP(GPIOF,GPIO_Pin_5,GPIO_Mode_AIN,GPIO_Speed_50MHz);}
	}
		

	

	 
  /* ADCx configuration ------------------------------------------------------*/
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 1;
  ADC_Init(ADCx, &ADC_InitStructure);

  /* ADCx regular channel14 configuration */ 
  ADC_RegularChannelConfig(ADCx, chanel, 1, ADC_SampleTime_239Cycles5);

  
  /* Enable ADCx */
  ADC_Cmd(ADCx, ENABLE);

  /* Enable ADCx reset calibration register */   
  ADC_ResetCalibration(ADCx);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADCx));

  /* Start ADCx calibration */
  ADC_StartCalibration(ADCx);
  /* Check the end of ADC1 calibration */
  while(ADC_GetCalibrationStatus(ADCx));
     
  /* Start ADCx Software Conversion */ 
  ADC_SoftwareStartConvCmd(ADCx, ENABLE);	

}


uint16_t ADC_read(ADC_TypeDef* ADCx,uint8_t chanel)
{
	ADC_RegularChannelConfig(ADCx, chanel, 1, ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADCx,ENABLE);
	
	/* Wait till done */
	while (ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC) == RESET);
	
//	/* Return result */
	return ADC_GetConversionValue(ADCx);	
}

uint16_t ADC_av(ADC_TypeDef* ADCx,uint8_t chanel,uint8_t n)
{
	uint32_t s=0;
	uint8_t i;
	for (i=0;i<n;i++)
	{
	s=s+ADC_read(ADCx,chanel);
	}
	return s/n;
}
