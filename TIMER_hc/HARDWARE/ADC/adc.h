#ifndef __ADC_H
#define __ADC_H 			   
#include "sys.h"  
//////////////////////////////////////////////////////////////////////////////////	 


////////////////////////////////////////////////////////////////////////////////// 
	 
void ADCx_init(ADC_TypeDef* ADCx,uint8_t chanel);
uint16_t ADC_read(ADC_TypeDef* ADCx,uint8_t chanel);
uint16_t ADC_av(ADC_TypeDef* ADCx,uint8_t chanel,uint8_t n);

#endif

