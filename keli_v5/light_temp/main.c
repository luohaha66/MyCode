#include <lpc11xx.h>
#include <tools.h>
#include <light.h>
#include <temp_hum.h>
#include <gpio.h>
#include <oled2864.h>
#include <temp_hum.h>
#include <i2c.h>
#include <stdio.h>
#include <gpio.h>
#include <ssp.h>
#include <acc.h>
#include <key.h>
#include "devcon.h"

void SysTick_Handler()
{

}

int main()
{
	SysTick_Config(48000);
  my_sys_init();
	my_gpio_init();
	
  while (1)
	{
	 if (KEY_Read())
		{
					oled_show();
		}
	}
}


