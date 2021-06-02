#include <stdio.h>
#include "stm32f10x.h"

#include "bsp_led.h"
#include "bsp_tim.h"
#include "bsp_usart.h"
#include "bsp_key.h"

#include "StreetMotor_driver.h"
#include "vofa_driver.h"

#include "test_app.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	static uint8_t Test[13] = "HelloWorld!\r\n";

	LED_Init();
	Key_Init();
	PWM_Init();
	Usart_Init();

	while(1)
	{
		Usart_Send(1,Test,13);
	}
}
