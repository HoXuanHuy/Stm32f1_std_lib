#include "usart.h"
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
/*
					TX   	RX
UARST1		PA9		PA10
					PB6		PB7
USART2		PA2		PA3
					PD5		PD6
*/

typedef struct
{
	char* buffer;
	uint16_t buffer_size;
  uint16_t in;
	uint16_t out;
	uint16_t num;
}USART_t;

char USART1_Buffer[100];
char USART2_Buffer[100];

USART_t USART1_ST={USART1_Buffer,100,0,0,0};
USART_t USART2_ST={USART2_Buffer,100,0,0,0};

void USARTtobuffer(USART_t *u, char c){
	
	if (u->in==u->buffer_size){u->in=0;}
	
	u->buffer[u->in]=c;
	u->in++; u->num++;
	
}

uint16_t AT_cmd (USART_TypeDef* USARTx,char* send, char* recei, uint32_t timeout){
	char res[100];
	uint16_t t=0;
	char c=0;
	uint16_t i=0;
	memset(res,'\0',100);
//	printf("%s\r\n",send);
	send_str(USART1,send);
	send_str(USART1,"\r\n");
	
	do{
		c=Get_c(USARTx);
		if (c){
				res[i++]=c;
		if (strstr(res,recei)) return 1;}
		t++;
		delay_ms(1);
		}while (t<timeout);
	return 0;
}



char Get_c(USART_TypeDef* USARTx){
	USART_t *u;
	char c=0;
	if (USARTx==USART1){ u=&USART1_ST;}
	else if (USARTx==USART2){ u=&USART2_ST;}
	if (u->num>0)
	{
		c=u->buffer[u->out];
		u->out++;
		u->num--;
		if (u->out==u->buffer_size) {u->out=0;}
	}
	return c;
}

uint16_t Get_s(USART_TypeDef* USARTx, char* str, uint16_t len){
	
	char c=0;
	uint16_t i=0;
	
	while (i<len)
	{
		c=Get_c(USARTx);
		if (c){ str[i]=c;
			if (str[i]=='\n'){i++; break;}  else i++;
		if (i>len) i=0;
		}
	}
	str[i]='\0';
	return i;
}




 
void USART1_IRQHandler(void)
{
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  {
		USARTtobuffer(&USART1_ST,USART1->DR);//send_data(USART1,USART1->DR);
	}
}


void USART2_IRQHandler(void)
{
  if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
  {
		USARTtobuffer(&USART2_ST,USART2->DR);//send_data(USART1,USART1->DR);
	}
}



void USARTx_init(USART_TypeDef* USARTx,pin_usart Pin,uint32_t baud){
	
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	uint8_t NVIC_IRQChannel; 
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE);//AFIO nam truoc GPIO

	if (USARTx==USART1){NVIC_IRQChannel = USART1_IRQn;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);}
	else if (USARTx==USART2){
	NVIC_IRQChannel = USART2_IRQn;
	RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART2 , ENABLE);}
	
	if (Pin==pin_PA9A10){
		GPIO_SETUP(GPIOA,GPIO_Pin_9,GPIO_Mode_AF_PP,GPIO_Speed_50MHz); //Tx
		GPIO_SETUP(GPIOA,GPIO_Pin_10,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//Rx
	}
	else if (Pin==pin_PB6B7){
		GPIO_SETUP(GPIOB,GPIO_Pin_6,GPIO_Mode_AF_PP,GPIO_Speed_50MHz); //Tx
		GPIO_SETUP(GPIOB,GPIO_Pin_7,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//Rx
	}
	else if (Pin==pin_PA2A3){
		GPIO_SETUP(GPIOA,GPIO_Pin_2,GPIO_Mode_AF_PP,GPIO_Speed_50MHz); //Tx
		GPIO_SETUP(GPIOA,GPIO_Pin_3,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//Rx
	}
	else if (Pin==pin_PD5D6){
		GPIO_SETUP(GPIOD,GPIO_Pin_5,GPIO_Mode_AF_PP,GPIO_Speed_50MHz); //Tx
		GPIO_SETUP(GPIOD,GPIO_Pin_6,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//Rx
	}
	
	

	 
	 
	 

/* USARTy and USARTz configuration ------------------------------------------------------*/
  /* USARTy and USARTz configured as follow:
        - BaudRate = 230400 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - Even parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = baud;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  
  /* Configure USARTy */
  USART_Init(USARTx, &USART_InitStructure);
//  /* Configure USARTz */
//  USART_Init(USART2, &USART_InitStructure);

  
  /* Enable the USARTy Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = NVIC_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);
  /* Enable the USARTy */
  USART_Cmd(USARTx, ENABLE);
}



void send_data (USART_TypeDef* USARTx, char c){
	    while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET) {}
			USARTx->DR = (c & (uint16_t)0x01FF);
//			USARTx->DR = c;
}

void send_str(USART_TypeDef* USARTx, char *s)
{
	while (*s)
	{
		send_data(USARTx,*s++);
	}
}

void send_numint(USART_TypeDef* USARTx,uint16_t n){
	char buff[30];
	sprintf(buff,"%d",n);
	send_str(USARTx,buff);
}

void send_numfloat(USART_TypeDef* USARTx,float n){
	char buff[30];
	sprintf(buff,"%.2f",n);
	send_str(USARTx,buff);
}