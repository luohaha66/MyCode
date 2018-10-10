#include <stdio.h>
#include <string.h>
#include "LPC11xx.h"
#include "read_temp_light.h"
#include "temp_hum.h"
#include "light.h"
#include "i2c.h"
#include "spi_uart.h"
#include "gpio.h"

void collect_data(uint8_t *temp, uint8_t *hum,uint32_t *light)
{
		uint8_t i;

		i = Read_Temp_Hum(temp,hum)	;
		I2CInit(I2CMASTER, 0);

  		light_init();
  		light_enable();
  		light_setRange(LIGHT_RANGE_4000);
		
		light[0] = light_read();

		if(i != 0)
		{
			printf("temp:%d.%d------hum:%d.%d------light:%d\r\n",temp[0],temp[1],hum[0],hum[1],light[0]);
			OLED_ClearScreen();
			snprintf(buf, 16, "Temp: %d.%d  ", temp[0], temp[1]);
			OLED_DisStrLine(0, 0, (uint8_t *)buf);
			snprintf(buf, 16, "Hum: %d.%d  ", hum[0], hum[1]);
			OLED_DisStrLine(2, 0, (uint8_t *)buf);
			snprintf(buf,8,"Light: %d  ",light[0]);
			OLED_DisStrLine(4, 0, (uint8_t *)buf);

			counter1 = 0;
		}		
}