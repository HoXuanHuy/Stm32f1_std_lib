#include "spi.h"





void SPI_init(SPI_TypeDef * SPIx,uint16_t Mode, uint16_t Speed){
	
	SPI_InitTypeDef  SPI_InitStructure;
	
	if (SPIx==SPI1){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		if (Mode==SPI_Mode_Master){
			GPIO_SETUP(GPIOA,GPIO_Pin_5,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//SCK
			GPIO_SETUP(GPIOA,GPIO_Pin_6,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//MISO
			GPIO_SETUP(GPIOA,GPIO_Pin_7,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//MOSI
		}
		else if (Mode==SPI_Mode_Slave){
			GPIO_SETUP(GPIOA,GPIO_Pin_5,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//SCK
			GPIO_SETUP(GPIOA,GPIO_Pin_6,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//SIMO
			GPIO_SETUP(GPIOA,GPIO_Pin_7,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//SOMI
		}
	}
	else if (SPIx==SPI2){
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		if (Mode==SPI_Mode_Master){
		GPIO_SETUP(GPIOB,GPIO_Pin_13,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//SCK
		GPIO_SETUP(GPIOB,GPIO_Pin_14,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//MISO
		GPIO_SETUP(GPIOB,GPIO_Pin_15,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//MOSI
		}
		else if (Mode==SPI_Mode_Slave){
		GPIO_SETUP(GPIOB,GPIO_Pin_13,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//SCK
		GPIO_SETUP(GPIOB,GPIO_Pin_14,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//SIMO
		GPIO_SETUP(GPIOB,GPIO_Pin_15,GPIO_Mode_IN_FLOATING,GPIO_Speed_50MHz);//SOMI
		}
	}
	
  /* SPI configuration ------------------------------------------------------*/
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = Mode;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = Speed;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPIx, &SPI_InitStructure);


  /* Enable SPI1 CRC calculation */
  SPI_CalculateCRC(SPIx, ENABLE);

  /* Enable SPI1 */
  SPI_Cmd(SPIx, ENABLE);
}




uint8_t SPI_trans(SPI_TypeDef * SPIx,uint8_t data){

	/* Wait for SPI1 Tx buffer empty */
  while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET){};
		/* Send SPI1 data */
	SPI_I2S_SendData(SPIx, data);
	/* Wait for SPI1 last data reception */
  while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);

 return SPI_I2S_ReceiveData(SPIx);
}




void SPI_send(SPI_TypeDef * SPIx,uint8_t data){
		/* Wait for SPI1 Tx buffer empty */
  while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET){};
		/* Send SPI1 data */
	SPI_I2S_SendData(SPIx, data);
}


uint8_t SPI_receive(SPI_TypeDef * SPIx){
	/* Wait for SPI1 last data reception */
  while (SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);
	
 return SPI_I2S_ReceiveData(SPIx);
}

