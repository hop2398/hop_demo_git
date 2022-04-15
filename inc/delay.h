#ifndef _DELAY_H
#define _DELAY_H

#include <stm32f10x_tim.h>
#include <stm32f10x_rcc.h>
#include <stdint.h>
void timer_init_ms();
void timer_init_us();
void stop_timer();
void delay1ms(); //Delay 1ms or 1us
void delay_ms(uint32_t mSecs);
void delay_us(uint32_t uSecs);
#endif