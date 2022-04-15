#ifndef __I2C_H
#define __I2C_H

#include "stm32f10x.h"
#include "delay.h"
#include <stdint.h>
void i2c_start();
void i2c_stop();
void i2c_write(uint8_t data);
void i2c_write_arr(uint8_t *data, uint8_t length);
void i2c_send_arr(uint8_t addr, uint8_t *arr, uint8_t length);
void i2c_send(uint8_t data);
#endif