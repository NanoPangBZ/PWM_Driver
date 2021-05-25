#ifndef _BSP_USART_H_
#define _BSP_USART_H_

#include "stm32f10x.h"

#define USART_RX_SBUFFER_SIZE   64
#define USART_TX_SBUFFER_SIZE   64

//每行第一个元素为有效数据个数
static uint8_t Usart_RX_Sbuffer[5][USART_RX_SBUFFER_SIZE];
static uint8_t Usart_TX_Sbuffer[5][USART_TX_SBUFFER_SIZE];

static USART_TypeDef*Target_Usart[5] = {USART1,USART2,USART3,UART4,UART5};

void Usart_Init(void);
void Usart_Config(void);
void Usart_NVIC_Config(void);
void Usart_GPIO_Config(void);
void Usart_DMA_Config(void);

void Usart_Rx_Input(uint8_t USARTx,uint8_t dat);
uint8_t*Read_Usart_Sbuffer(uint8_t USARTx);

/*************中断****************/
void USART1_IRQHandler(void);

#endif
