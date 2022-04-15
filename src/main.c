#include "stm32f10x.h"
#include <stdint.h>
#include "stm32f10x_pwr.h"
#include "stm32f10x_gpio.h"
void Delay_1_Ms(void)
{	
	SysTick->LOAD = 72 * 1000-1;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while (!(SysTick->CTRL & (1 << 16))) {
	}
}

void Delay_Ms(uint32_t u32Delay)
{
	while (u32Delay) {
		Delay_1_Ms();
		--u32Delay;
	}
}
void delay_us(volatile uint16_t micro_second)
{
	uint32_t b = micro_second * 8;
	while(b--);
}

void delay(volatile uint16_t a)
{
	uint32_t b = a * 800;
	while(b--);
}
int main()
{
	RCC_HSEConfig (RCC_HSE_ON);
	RCC_PLLConfig (RCC_PLLSource_HSE_Div1 ,  RCC_PLLMul_9);
	RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);
	RCC_HCLKConfig (RCC_SYSCLK_Div1);
	RCC_PCLK2Config (RCC_HCLK_Div1);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_Inits;
	GPIO_Inits.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_Inits.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Inits.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_Inits);
	// GPIOB->ODR |= (1<<12);
	// Delay_Ms(500);
	// GPIOB->ODR &= 1<<12);
	// Delay_Ms(500);
  while (1)
  {
	  for (volatile uint16_t i = 0 ; i<= 100 ; i++)
	  {
		  GPIOB->ODR |= (1<<12);
		  delay(100-i);
		  GPIOB->ODR &= ~(1<<12);
		  delay(i);
	  }
	   for (volatile uint16_t i = 0 ; i<= 100 ; i++)
	  {
		  GPIOB->ODR |= (1<<12);
		  delay(i);
		  GPIOB->ODR &= ~(1<<12);
		  delay(100-i);
	  }
  }
}