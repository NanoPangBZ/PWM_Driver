#include <stdio.h>
#include "stm32f10x.h"

#include "bsp_led.h"
#include "bsp_tim.h"
#include "bsp_usart.h"

void LED_Test(void)
{
	for(uint8_t temp=0;temp<4;temp++)
		LED_CTR(temp,1);
}

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	PWM_Init();
	LED_Init();

	LED_Test();
	for(uint8_t temp=0;temp<16;temp++)
		PWM_Out(temp,10000);
	while(1);
}

