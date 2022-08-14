#include "bps_led.h"

void LED_G_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
}

//void LED_B_GPIO_Config(void)
//{
//	GPIO_InitTypeDef GPIO_InitStruct;
//	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK,ENABLE);
//	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1;
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStruct);
//}

//void LED_R_GPIO_Config(void)
//{
//	GPIO_InitTypeDef GPIO_InitStruct;
//	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK,ENABLE);
//	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_5;
//	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStruct);
//}

void ledG_reversal(void)
{
	static uint8_t n=0;
	if(n==0)
	{
		GPIO_ResetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);
	}
	else
	{
		GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	}
	n=1-n;
}
