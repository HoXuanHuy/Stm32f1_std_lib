#ifndef __EXTI_H
#define __EXTI_H 			   
#include "sys.h"  
//////////////////////////////////////////////////////////////////////////////////	 


////////////////////////////////////////////////////////////////////////////////// 
	 
void EXTIx_init(GPIO_TypeDef* GPIOx,u16 Pin,EXTITrigger_TypeDef EXTI_Trigger);
#endif