#ifndef __PWM_H
#define __PWM_H 			   
#include "sys.h"  
//////////////////////////////////////////////////////////////////////////////////	 


////////////////////////////////////////////////////////////////////////////////// 
	 
typedef enum
{ 
	PP1,
	PP2,
	PP3
}pin_pwm;	 

typedef enum
{ 
	CH1,
	CH2,
	CH3,
	CH4
}ch_pwm;	 
	 
void TIM2_pin(ch_pwm Chanelx,pin_pwm Pin);
void TIM3_pin(ch_pwm Chanelx,pin_pwm Pin);
void TIM4_pin(ch_pwm Chanelx,pin_pwm Pin);
void PWMx_init(TIM_TypeDef * TIMx,ch_pwm Chanelx,pin_pwm Pin,uint16_t ARR,uint16_t PSC);


#endif


/*
 * PWM pins 
 *
 * 	TIMER	|CHANNEL 1				|CHANNEL 2				|CHANNEL 3				|CHANNEL 4
 * 				|PP1	PP2		PP3		|PP1	PP2		PP3		|PP1	PP2		PP3		|PP1	PP2		PP3
 *
 * 	TIM 2	|PA0	PA5		PA15	|PA1	PB3		-			|PA2	PB10	-			|PA3	PB11	-
 * 	TIM 3	|PA6	PB4		PC6		|PA7	PB5		PC7		|PB0	PC8		-			|PB1	PC9		-
 * 	TIM 4	|PB6	PD12	-			|PB7	PD13	-			|PB8	PD14	-			|PB9	PD15	-
 * 	TIM 5	|PA0	PH10	-			|PA1	PH11	-			|PA2	PH12	-			|PA3	PI0		-
 * 	TIM 8	|PC6	PI5		-			|PC7	PI6		-			|PC8	PI7		-			|PC9	PI2		-
 * 	TIM 9	|PA2	PE5		-			|PA3	PE6		-			|-		-		-				|-		-		-
 * 	TIM 10|PB8	PF6		-			|-		-		-				|-		-		-				|-		-		-
 * 	TIM 11|PB9	PF7		-			|-		-		-				|-		-		-				|-		-		-
 * 	TIM 12|PB14	PH6		-			|PB15	PH9		-			|-		-		-				|-		-		-
 * 	TIM 13|PA6	PF8		-			|-		-		-				|-		-		-				|-		-		-
 * 	TIM 14|PA7	PF9		-			|-		-		-				|-		-		-				|-		-		-
 *
*/
//////////////////////////////////////////////////////////////////////////////////