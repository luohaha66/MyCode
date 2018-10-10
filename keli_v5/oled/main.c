#include <lpc11xx.h>
#include <oled2864.h>
#include <gpio.h>
#include <ssp.h>
#include <tools.h>
#include <temp_hum.h>

void SysTick_Handler()
{
}

int main()
{
	SystemInit();
	GPIOInit();
	SysTick_Config(48000);
	
	SPI_IOConfig(0);
	SPI_Init(0, 8, 2);
	
	OLED_Init_I();
	OLED_ClearScreen();
	
	GPIOSetDir(PORT1, 8, 0);
	GPIOSetDir(PORT1, 9, 0);
	GPIOSetDir(PORT1, 10, 0);
	GPIOSetDir(PORT1, 11, 0);
	GPIOSetDir(PORT0, 3, 0);
	
	while(1)
	{
		if (GPIOGetValue(PORT0, 3) == 0)
		{
			Temp_Hum_Test();
		}
	}
}

