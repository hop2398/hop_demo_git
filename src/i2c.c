#include <i2c.h>
void i2c_start()
{
	scl1;
	delay_us(1);
	sda1;
	delay_us(5);
	sda0;
	delay_us(5);
	scl0;
	delay_us(3);
}

void i2c_stop()
{
  sda0;
  delay_us(3);
  scl1;
  delay_us(3);
  sda1;
  delay_us(5);
}
void i2c_write(uint8_t data)
{
		for (uint8_t i = 0 ; i < 8 ; i++)
		{
			if (data & 0x80)
			{
				sda1;
			}
			else 
			{
				sda0;
			}
			delay_us(3);
			scl1;
			delay_us(5);
			scl0;
			delay_us(3);
			data = data] << 1;
		}
		sda1;
		delay_us(3);
		scl1;
		delay_us(10);
		scl0;
		delay_us(3);
	} 
}
void i2c_write_arr(uint8_t *data, uint8_t length)
{
	uint8_t i = 0 ;
	for (uint8_t length_index = 0 ; length_index < length ; length_index++)
	{
		for (i = 0 ; i < 8 ; i++)
		{
			if (data[length_index] & 0x80)
			{
				sda1;
			}
			else 
			{
				sda0;
			}
			delay_us(3);
			scl1;
			delay_us(5);
			scl0;
			delay_us(3);
			data[length_index] = data[length_index] << 1;
		}
		sda1;
		delay_us(3);
		scl1;
		delay_us(10);
		scl0;
		delay_us(3);
	} 
}

void i2c_send_arr(uint8_t addr, uint8_t *arr, uint8_t length)
{
	i2c_start();
	i2c_write_arr(arr,length);
	i2c_stop();
}
void i2c_send(uint8_t data)
{
	i2c_start();
	i2c_write(data);
	i2c_stop();
}

