#include <lpc11xx.h>
#include <gpio.h>
#include <timer32.h>



void speaker_op(uint8_t pwn_set)
{
	volatile uint32_t period = 50;
	switch (pwn_set)
	{
		case 1:
			LPC_TMR32B1->PR = 0x7f;
			init_timer32PWM(1, period, MATCH0);
			enable_timer32(1);
		break;
		
		case 0:
		break;
	}
}

int main()
{
	SystemInit();
	GPIOInit();
	GPIOSetDir(PORT1, 1, 1);
	GPIOSetValue(PORT1, 1, 1);
	
	speaker_op(1);
	
}

