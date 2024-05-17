#include "timer.h"



void Timebase_init(TIM_TypeDef * TIMx,uint16_t ARR,uint16_t PSC){
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	uint16_t nvic_irq;
	
	
	if (TIMx==TIM2) {RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);nvic_irq=TIM2_IRQn;}
	else if (TIMx==TIM3) {RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);nvic_irq=TIM3_IRQn;}
	else if (TIMx==TIM4) {RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);nvic_irq=TIM4_IRQn;}
	



  /* Enable the TIM2 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = nvic_irq;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

  /* ---------------------------------------------------------------
    TIM2 Configuration: Output Compare Timing Mode:
    TIM2 counter clock at 6 MHz
    CC1 update rate = TIM2 counter clock / CCR1_Val = 146.48 Hz
    CC2 update rate = TIM2 counter clock / CCR2_Val = 219.7 Hz
    CC3 update rate = TIM2 counter clock / CCR3_Val = 439.4 Hz
    CC4 update rate = TIM2 counter clock / CCR4_Val = 878.9 Hz
  --------------------------------------------------------------- */


  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = ARR-1;
  TIM_TimeBaseStructure.TIM_Prescaler = PSC-1;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure);


/* TIM IT enable */
  TIM_ITConfig(TIMx, TIM_IT_Update, ENABLE);

  /* TIM2 enable counter */
  TIM_Cmd(TIMx, ENABLE);
}