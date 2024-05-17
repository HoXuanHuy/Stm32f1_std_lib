#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "usart.h"
#include "stdlib.h"
#include "exti.h"
#include "adc.h"
#include "pwm.h"
#include "timer.h"
#include <stdio.h>
#include "inputcapture.h"

#define LED1 PAout(1)
#define LED2 PAout(7)
#define LED3 PAout(6)

//#define trigger PBout(4)
//#define echo PBin(7)

#define TRIG PBout(6)
#define ECHO PBin(7)




//char str[30];
//int val, val2,val3;
//int count=0;




//u32 t=0;

//#define TT 1000000
//u32 ti=0;
//float dis=0;







int main(void)
 {	

		LED_init();	 
		delay_init();
//	PWMx_init(TIM3,CH1,PP1,100,72);
//	PWMx_init(TIM3,CH2,PP1,100,72);
//	PWMx_init(TIM3,CH3,PP1,100,72);
	USARTx_init(USART1,pin_PA9A10, 9600);
	 
//	 SysTick_Config(SystemCoreClock/1000);

//	Timebase_init(TIM2,100,720);
//	GPIO_SETUP(GPIOA,GPIO_Pin_1,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
//	GPIO_SETUP(GPIOA,GPIO_Pin_7,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
//	GPIO_SETUP(GPIOA,GPIO_Pin_6,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
//	 
//	GPIO_SETUP(GPIOB,GPIO_Pin_6,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
//	GPIO_SETUP(GPIOB,GPIO_Pin_7,GPIO_Mode_IN_FLOATING ,GPIO_Speed_50MHz);

	 HCSR04_Init();
//	 trigger=0;
	 
  while(1)
	{

/*	
//		for (int i=0;i<100;i++){
////			TIM4->CCR4=i;
//			TIM3->CCR3=i;
//			delay_ms(50);
//		}
		
//		if (Get_s(USART1,str,sizeof(str))){
//			a=atoi(str);
//			TIM3->CCR3=a;
//		}
		
//	if(Get_s(USART1,str,sizeof(str))){
//		val = atoi(strtok(str, ","));
//		val2 = atoi(strtok(NULL, ","));
//		val3 = atoi(strtok(NULL, "\n"));
//		TIM3->CCR1=val;
//		TIM3->CCR2=val2;
//		TIM3->CCR3=val3;
//	}*///PWM
		
//		LED1=!LED1;
//		t=millis()+1000;
//		while (millis()<t){};


//			if ((millis()-t1)>1000){LED1=!LED1; t1=millis();}
//			if ((millis()-t2)>100){LED2=!LED2; t2=millis();}
			
//			delay_us(4);
//			trigger=1;
//			delay_us(10);
//			trigger=0;
//			ti=TT;
//			while (echo==0){
//				if(ti-- ==0) break;
//			}
//			t=0;
//			while (echo==1){ 
//				delay_us(1);
//				t++;
//			}
//			dis=(t*0.027);
			
			
			send_numfloat(USART1,HCSR04_GetDistance());
			send_str(USART1,"\n");
			delay_ms(100);
			
			
	}
}
 
void TIM2_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
  {
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

