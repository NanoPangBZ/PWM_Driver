#include <stdio.h>
#include "stm32f10x.h"

#include "bsp_led.h"
#include "bsp_tim.h"
#include "bsp_usart.h"
#include "bsp_key.h"
#include "bsp_spi.h"

#include "StreetMotor_driver.h"
#include "oled12864_driver.h"
#include "vofa_driver.h"

#include "test_app.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	LED_Init();
	OLED_SPI_Init();
	Key_Init();
	PWM_Init();
	Usart_Init();

	SPI_RST_SET();

	while(1)
	{
		//OLED12864_Init();
	}
}
