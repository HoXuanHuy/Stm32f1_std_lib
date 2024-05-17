#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"
#include "usart.h"
#include "stdlib.h"
#include "exti.h"
#include "adc.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string.h>

#define LED1 PBout(12)
char buff[30];
char c=0;
char str[30];
char *p;
uint16_t n=0;
uint16_t a=0;
float b=0;
float val, val2;
int val3;
int num19[10];
int i=0;
char* recei;


 int main(void)
 {	
		//LED_init();
		delay_init();

	GPIO_SETUP(GPIOB,GPIO_Pin_12,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
	USARTx_init(USART1,pin_PA9A10,9600);
	LED1=0;
//	do{n=AT_cmd(USART1,"AT","OK",500);}while (n==0);
  while(1)
	{
		
//		  /* Send one byte from USARTy to USARTz */
//    USART_SendData(USART1, 'B');
//    /* Loop until USARTy DR register is empty */ 
//    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
//    {
//    }
//		send_data(USART1,'H');
//		delay_ms(500);
		
		
//		sprintf(buff,"%d",123);
//		send_str(USART1,buff);
//		send_numint(USART1,112);
//		send_numfloat(USART1,12.4);
//		
//		delay_ms(1000);
//		
//		if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET)
//    {
////			c=(USART_ReceiveData(USART1)&(0x7F));
//			
////			c=USART1->DR;
////			send_data(USART1,c);
//			send_data(USART1,USART1->DR);
//    }

//		c=Get_c(USART1);
//		if (c) {send_data(USART1,c);}

//		send_str(USART1,"Hiry");
//		delay_ms(500);
		
//	if(Get_s(USART1,str,sizeof(str))){
//		send_str(USART1,str);
//		if (strstr(str, "LED1on")){LED1=0;}
//		else if (strstr(str, "LED1off")){LED1=1;}
//		}

//	if(Get_s(USART1,str,sizeof(str))){
//		send_str(USART1,str);}

//		if(Get_s(USART1,str,sizeof(str))){
//			p=strtok(str,",");
//			
//			a=atoi(p);
//			send_str(USART1,"So nguyen:");
////			send_str(USART1,p);
//			send_numint(USART1,a);
//			while(p != NULL) {
//				p = strtok(NULL, ",");
//				if(p != NULL) {
//					b=atof(p) ;
//					send_str(USART1,"So thuc:");
//					send_numfloat(USART1,b);
////				send_str(USART1,p);
//				}
//			}
//		}xxxx
		
		
		
//		if(Get_s(USART1,str,sizeof(str))){
//			p=strtok(str,",");
//			
//			if (strstr(str,".")){
//				b=atof(p) ;
//				send_str(USART1,"So thuc:");
//				send_numfloat(USART1,b);
//			}
//			else {
//				a=atoi(p);
//			send_str(USART1,"So nguyen:");
//			send_numint(USART1,a);
//			}
//			
//			while(p != NULL) {
//				p = strtok(NULL, ",");
//				if(p != NULL) {
//					if (strstr(str,".")){
//						b=atof(p) ;
//						send_str(USART1,"So thuc:");
//						send_numfloat(USART1,b);
//					}
//					else {
//						a=atoi(p);
//						send_str(USART1,"So nguyen:");
//						send_numint(USART1,a);
//					}
//				}
//			}
//		}xxx

	if(Get_s(USART1,str,sizeof(str))){
		val = atof(strtok(str, ","));
		val2 = atof(strtok(NULL, ","));
		val3 = atoi(strtok(NULL, "\n"));
		printf("%2.2f-%2.2f-%3d\n", val,val2,val3);
	}
	
//		if(Get_s(USART1,str,sizeof(str))){
//			val = atof(strtok(str, ","));
//			val2 = atof(strtok(NULL, ","));
//			val3 = atoi(strtok(NULL, "\n"));
//			sprintf(str,"%.2f %.2f %d \n",val,val2,val3);
//			send_str(USART1,str);
//		}




//		for ( i=0;i<9;i++){
//			str[i]=str[i+1];
//			}
//		c=Get_c(USART1);
//		if (c){ str[9]=c; a++;}
//		
//		if (a==10){send_str(USART1,str);}xxx


//	c=Get_c(USART1);
//	if(c)
//		{
//	   for (int i=0;i<9;i++) str[i]=str[i+1];
//     str[9]=c;
//	  }
//	delay_ms(50);
//	send_str(USART1,str);	
//	send_str(USART1,"\n");


//	c=Get_c(USART1);
//	if(c)
//		{
//	   for ( i=0;i<9;i++) {str[i]=str[i+1];
//     str[9]=c;
//	  }
//	delay_ms(50);
//	if ((str[0]==0x01)&&(str[9]==0x02)){
//	send_str(USART1,str);	send_str(USART1,"\n");}
//		}


//		send_str(USART1,"Hiry");
//		LED1=!LED1;
//		delay_ms(500);
		
	}
	
}



int fputc(int ch, FILE *f)
{      
//	while((USART1->SR&0X40)==0);
//    USART1->DR = (u8) ch;   
send_data(USART1,ch);	
	return ch;
}

