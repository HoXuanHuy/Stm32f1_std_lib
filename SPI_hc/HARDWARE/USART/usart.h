#ifndef __USART_H
#define __USART_H 			   
#include "sys.h"  
//////////////////////////////////////////////////////////////////////////////////	 
typedef enum
{ pin_PA9A10,
	pin_PB6B7,
	pin_PA2A3,
	pin_PD5D6,
}pin_usart;



////////////////////////////////////////////////////////////////////////////////// 
void USARTx_init(USART_TypeDef* USARTx,pin_usart Pin,uint32_t baud);
void send_data (USART_TypeDef* USARTx, char c);
void send_str(USART_TypeDef* USARTx, char *s);
void send_numint(USART_TypeDef* USARTx,uint16_t n);
void send_numfloat(USART_TypeDef* USARTx,float n);
char Get_c(USART_TypeDef* USARTx);
uint16_t Get_s(USART_TypeDef* USARTx, char* str, uint16_t len);
uint16_t AT_cmd (USART_TypeDef* USARTx,char* send, char* recei, uint32_t timeout);

#endif

