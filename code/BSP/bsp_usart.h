#ifndef _BSP_USART_H_
#define _BSP_USART_H_

#include "stm32f10x.h"

/******************************************
 * 适用stm32f103vet6
 * 串口2的GPIO进行了重映射!
 * 串口123发送函数使用的DMA通道
 * 缓存区最大255(unsigned char)
 *      2021/5/22   庞碧璋
******************************************/

#define USART_RX_SBUFFER_SIZE   64
#define USART_TX_SBUFFER_SIZE   64

//每行第一个元素为有效数据个数
static uint8_t Usart_RX_Sbuffer[5][USART_RX_SBUFFER_SIZE];
static uint8_t Usart_TX_Sbuffer[3][USART_TX_SBUFFER_SIZE];

static USART_TypeDef*Target_Usart[5] = {USART1,USART2,USART3,UART4,UART5};
static DMA_Channel_TypeDef*Usart_Channel[3] = {DMA1_Channel4,DMA1_Channel7,DMA1_Channel2};

void Usart_Init(void);
void Usart_Config(void);
void Usart_NVIC_Config(void);
void Usart_GPIO_Config(void);
void Usart_DMA_Config(void);
void Usart_Enable(void);

uint8_t*Read_Usart_Sbuffer(uint8_t USARTx);
uint8_t Usart_Send(uint8_t USARTx,uint8_t*dat,uint8_t len);
void Usart_Rx_Push(uint8_t USARTx,uint8_t len);
void Usart_Rx_Clear(uint8_t USARTx);

void Usart_Tx_Clear(uint8_t USARTx);
void Usart_Rx_Input(uint8_t USARTx,uint8_t dat);

/*************中断****************/
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);
void DMA1_Channel4_IRQHandler(void);
void DMA1_Channel7_IRQHandler(void);
void DMA1_Channel2_IRQHandler(void);

#endif
