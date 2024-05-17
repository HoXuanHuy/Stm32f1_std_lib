#ifndef __SPI_H
#define __SPI_H 			   
#include "sys.h"  
//////////////////////////////////////////////////////////////////////////////////	 


////////////////////////////////////////////////////////////////////////////////// 
	 
void SPI_init(SPI_TypeDef * SPIx,uint16_t Mode, uint16_t Speed);
uint8_t SPI_trans(SPI_TypeDef * SPIx,uint8_t data);
void SPI_send(SPI_TypeDef * SPIx,uint8_t data);
uint8_t SPI_receive(SPI_TypeDef * SPIx);



#endif

