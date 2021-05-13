#ifndef _BSP_USART_H_
#define _BSP_USART_H_

#include "stm32f10x.h"

static USART_TypeDef*Target_Usart[5] = {USART1,USART2,USART3,UART4,UART5};

void Usart_Init(void);
void Usart_Config(void);
void Usart_NVIC_Config(void);
void Usart_GPIO_Config(void);

#endif
