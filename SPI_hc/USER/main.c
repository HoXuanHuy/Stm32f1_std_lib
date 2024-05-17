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
#include "spi.h"

#define LED1 PAout(1)
#define LED2 PAout(7)
#define LED3 PAout(6)

uint8_t a=0;
uint8_t b=0;



int main(void)
 {	

		LED_init();	 
		delay_init();

	SPI_init(SPI1,SPI_Mode_Master,SPI_BaudRatePrescaler_16);
	SPI_init(SPI2,SPI_Mode_Slave,SPI_BaudRatePrescaler_16);

	USARTx_init(USART1,pin_PA9A10,9600);
	 
	
	
//	 send_data(USART1,SPI_trans(SPI1,6));

	 

	 
  while(1)
	{
		
//		printf("%d\n",SPI_trans(SPI1,7));
//		delay_ms(500);
//		printf("%d\n",SPI_trans(SPI2,15));
//		delay_ms(500);
		
//		a=SPI_trans(SPI1,4);
//		b=SPI_trans(SPI2,8);
//		delay_ms(500);
		
		SPI_send(SPI1,15);
		a=SPI_receive(SPI2);
		SPI_send(SPI2,8);
		b=SPI_receive(SPI1);
		
//		SPI_send(SPI1,6);
//		a=SPI_receive(SPI2);
//		printf("%d\n",a);
//		delay_ms(500);
		
	}
}



int fputc(int ch, FILE *f)
{      
send_data(USART1,ch);	
	return ch;
}