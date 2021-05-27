#include <stdio.h>
#include "stm32f10x.h"

#include "bsp_led.h"
#include "bsp_tim.h"
#include "bsp_usart.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	static uint8_t Test[5] = "abcde";

	LED_Init();
	Usart_Init();

	LED_CTR(2,1);

	while(1)
	{
		Usart_Sned(1,Test,4);
	}
}

