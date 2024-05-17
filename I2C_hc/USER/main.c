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







int main(void)
 {	

		LED_init();	 
		delay_init();

	 
  while(1)
	{


	}
}
 
