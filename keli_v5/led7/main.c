#include <lpc11xx.h>
#include <stdio.h>
#include <gpio.h>
#include <led7seg.h>
#include <ssp.h>
#include <seg7led.h>

int main()
{
	SystemInit();
	GPIOInit();
	
	Seg7Led_Init();
	Seg7Led_Put(10);
	
	SysTick_Config(48000);
	
	SPI_IOConfig(0);
	SPI_Init(0, 8, 2);
	
	led7seg_init();
	led7seg_setChar(4, 1);

}

