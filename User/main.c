#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_basicTim.h"
uint16_t t=0;
int main()
{
	LED_G_GPIO_Config();
	Basic_Tim_Config();
	while(1)
	{
		if(t>=1000)
		{
			t=0;
			ledG_reversal();
		}
	}
}




void TIM6_IRQHandler()
{
	if(TIM_GetITStatus(BASIC_TIM,TIM_IT_Update)==1)
	{
		t++;
		TIM_ClearITPendingBit(BASIC_TIM , TIM_FLAG_Update);
	}
}

