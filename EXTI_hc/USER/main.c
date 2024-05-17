#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "usart.h"
#include "stdlib.h"
#include "exti.h"


#define LED1 PBout(12)
#define button PAin(5)
#define button1 PBin(9)


//void EXTI0_Config(void)
//{
//	EXTI_InitTypeDef   EXTI_InitStructure;
//	GPIO_InitTypeDef   GPIO_InitStructure;
//	NVIC_InitTypeDef   NVIC_InitStructure;
//  /* Enable GPIOA clock */
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//  
//  /* Configure PA.00 pin as input floating */
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);

//  /* Enable AFIO clock */
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

//  /* Connect EXTI0 Line to PA.00 pin */
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

//  /* Configure EXTI0 line */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line0;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);

//  /* Enable and set EXTI0 Interrupt to the lowest priority */
//  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
//}



void EXTI9_5_IRQHandler(void)
{
	delay_ms(20);
	if (button==1)
	{
		LED1=!LED1;
//    EXTI_ClearITPendingBit(EXTI_Line5);
	}
	if (button1==1){
		LED1=!LED1;
//    EXTI_ClearITPendingBit(EXTI_Line9);
	}
	EXTI_ClearITPendingBit((EXTI_Line9)|EXTI_Line5);
//  if(EXTI_GetITStatus(EXTI_Line0) != RESET)
//  {
//		LED1=!LED1;
//    /* Clear the  EXTI line 0 pending bit */
//    EXTI_ClearITPendingBit(EXTI_Line0);
//  }
}







 int main(void)
 {	
		LED_init();
		delay_init();

		GPIO_SETUP(GPIOB,GPIO_Pin_12,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
		LED1=1;
		EXTIx_init(GPIOA,GPIO_Pin_5,EXTI_Trigger_Rising);
		EXTIx_init(GPIOB,GPIO_Pin_9,EXTI_Trigger_Rising);
	 
  while(1)
	{
		
		
	}
}


