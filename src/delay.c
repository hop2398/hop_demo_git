#include <delay.h>
void timer_init_ms() {
	// Enable clock for TIM2
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_TimeBaseInitTypeDef TIM;
	//TIM_TimeBaseStructInit(&TIM);
	TIM.TIM_Prescaler = 72-1;
	TIM.TIM_Period = UINT16_MAX;
	TIM.TIM_ClockDivision = 0;
	TIM.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM);
	// Enable counter for TIM2
	TIM_Cmd(TIM2,ENABLE);
}
void timer_init_us() {
	// Enable clock for TIM2
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_TimeBaseInitTypeDef TIM;
	//TIM_TimeBaseStructInit(&TIM);
	TIM.TIM_Prescaler = 30-1;
	TIM.TIM_Period = UINT16_MAX;
	TIM.TIM_ClockDivision = 0;
	TIM.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM);
	// Enable counter for TIM2
	TIM_Cmd(TIM2,ENABLE);
}
// Stop timer
void stop_timer() {
	TIM_Cmd(TIM2,DISABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,DISABLE); // Powersavings?
}

void delay1ms()
{
	 TIM_SetCounter(TIM2,0);
	 while(TIM_GetCounter(TIM2)<1000);
}

void delay_ms(uint32_t mSecs) {
	timer_init_ms();

	// Dummy loop with 16 bit count wrap around
	while(mSecs--)
	{
		delay1ms();
	}
	// Stop timer
	stop_timer();
}

// Do delay for nTime microseconds
void delay_us(uint32_t uSecs) {
	timer_init_us();
	TIM_SetCounter(TIM2,0);
	while(TIM_GetCounter(TIM2)<uSecs);
	stop_timer();
}
