#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "usart.h"
#include "stdlib.h"
#include "exti.h"
#include "adc.h"

uint16_t valadc=0;


//void ADC_config(void){
//	ADC_InitTypeDef ADC_InitStructure;
//	__IO uint16_t ADCConvertedValue;
//	
//	/* System clocks configuration ---------------------------------------------*/
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

//  /* GPIO configuration ------------------------------------------------------*/
//	GPIO_SETUP(GPIOA,GPIO_Pin_0,GPIO_Mode_AIN,GPIO_Speed_50MHz);

//	 
//  /* ADC1 configuration ------------------------------------------------------*/
//  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
//  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
//  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
//  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
//  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
//  ADC_InitStructure.ADC_NbrOfChannel = 1;
//  ADC_Init(ADC1, &ADC_InitStructure);

//  /* ADC1 regular channel14 configuration */ 
//  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);

//  
//  /* Enable ADC1 */
//  ADC_Cmd(ADC1, ENABLE);

//  /* Enable ADC1 reset calibration register */   
//  ADC_ResetCalibration(ADC1);
//  /* Check the end of ADC1 reset calibration register */
//  while(ADC_GetResetCalibrationStatus(ADC1));

//  /* Start ADC1 calibration */
//  ADC_StartCalibration(ADC1);
//  /* Check the end of ADC1 calibration */
//  while(ADC_GetCalibrationStatus(ADC1));
//     
//  /* Start ADC1 Software Conversion */ 
//  ADC_SoftwareStartConvCmd(ADC1, ENABLE);	
//}










 int main(void)
 {	
		LED_init();
		delay_init();

	ADCx_init(ADC1,ADC_Channel_0);
	 

	 
  while(1)
	{
//		valadc=ADC_read(ADC1,ADC_Channel_0);
		valadc=ADC_av(ADC1,ADC_Channel_0,200);
		delay_ms(100);
	}
}


