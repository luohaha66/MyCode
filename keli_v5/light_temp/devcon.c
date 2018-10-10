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
#include <timer32.h>
#include <adc.h>

void my_sys_init(void)
{
	SystemInit();
	GPIOInit();
	
	SPI_IOConfig(0);
	SPI_Init(0, 8, 2);
	
	I2CInit(I2CMASTER, 0);

  light_init();
  light_enable();
  light_setRange(LIGHT_RANGE_4000);
	
	OLED_Init_I();
	acc_init();
	ADCInit(ADC_CLK);
}

void my_gpio_init(void)
{
	GPIOSetDir(PORT0, 2, 1);
	
	GPIOSetDir(PORT3, 0, 1);
	GPIOSetDir(PORT3, 1, 1);
	
	GPIOSetDir(PORT1, 1, 1);
	GPIOSetValue(PORT1, 1, 1);
	
	KEY_Init();
}

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
			disable_timer32(1);
		break;
	}
}


void oled_show(void)
{		
				char buf[32] = {0};
				int light_val = 0;
				uint8_t	temp[2], hum[2];
				char		buff[20];
				uint32_t	i;
				char buffers[128];
				uint32_t adc;		
				int adv;
				
				char		buffs[24];
				int32_t	xoff = 0;
				int32_t	yoff = 0;
				int32_t	zoff = 0;
				int8_t	x = 0;
				int8_t	y = 0;
				int8_t	z = 0;
				uint8_t tstatus = 0;
				int bit = 1;
				int nbit = 1;
				
	while(1)
	{
        /*Axis-3 control */
				OLED_DisStrLine(0, 0, "Axis-3");
				acc_read(&x, &y, &z);
				x = x + xoff;
				y = y + yoff;
				z = z + zoff;

				snprintf(buffs, 20, "Acc x: %d  ", x);
				OLED_DisStrLine(1, 0, (uint8_t *)buffs);

				snprintf(buffs, 20, "Acc y: %d  ", y);
				OLED_DisStrLine(2, 0, (uint8_t *)buffs);

				snprintf(buffs, 20, "Acc z: %d  ", z);
				OLED_DisStrLine(3, 0, (uint8_t *)buffs);
			
				/* light control */
				light_val = light_read();
		
				if(bit)
				{	
		
					if (light_val > 1000)
					{
						/* led off */
						GPIOSetValue(PORT3, 0, 1);
						
						GPIOSetValue(PORT3, 1, 1); //set 1
						delay_ms(100);
					}
					
					else
					{
						 /* led on */
						GPIOSetValue(PORT3, 0, 0); //set 0
						
						GPIOSetValue(PORT3, 1, 0);
						delay_ms(100);
					}
				}

				sprintf(buf, "Light: %d", light_val);
				OLED_DisStrLine(4, 0, (uint8_t*)buf);
			
				/* temp&hum control */
				i = Read_Temp_Hum(temp, hum);
				tstatus = temp[0] + temp[1] / 10;
				
				if (nbit)
				{
					if(tstatus > 27)
					{
							/* fan&beep on */
							GPIOSetValue(PORT0, 2, 0);
							speaker_op(1);
						  delay_ms(100);
					}
					else
					{
							/* fan&beep off */
							GPIOSetValue(PORT0, 2, 1);
							speaker_op(0);
						  delay_ms(100);
					}
				}
				
				if(i){
					if(temp[0]&0x80){
						temp[0] &= 0x7f;
							snprintf(buff, 16, "Temp: -%d.%d  ", temp[0], temp[1]);
					}
					else{
						snprintf(buff, 16, "Temp: %d.%d  ", temp[0], temp[1]);
					}
					OLED_DisStrLine(5, 0, (uint8_t *)buff);
					snprintf(buff, 16, "Hum:  %d.%d  ", hum[0], hum[1]);
					OLED_DisStrLine(6, 0, (uint8_t *)buff);
				 }
				 
				 delay_ms(100);
				 
				 /*adc control */
				 adc = ADCRead(0);
				 adv = adc * 3.3 / 1023 * 10;
		     snprintf(buffers, 128, "ADC : %d.%dV", adv/10, adv%10);
		
		     OLED_DisStrLine(7, 0, (uint8_t *)buffers);
				 delay_ms(100);

				 
				 if ( !GPIOGetValue(PORT1, 10) )
				 { 
					 /* led on */
					GPIOSetValue(PORT3, 0, 0); //set 0
					
					GPIOSetValue(PORT3, 1, 0);
					 
					bit = 1;
				 }
					
					if ( !GPIOGetValue(PORT1, 11) )
					{
					 /* led off */
					GPIOSetValue(PORT3, 0, 1);
					
					GPIOSetValue(PORT3, 1, 1); //set 1
						
					bit = 0;
					}
					
				  if ( !GPIOGetValue(PORT1, 8) )
					 {
						 /* fan on */
						GPIOSetValue(PORT0, 2, 0);
						nbit = 0;
					 }
					 
					if ( !GPIOGetValue(PORT1, 9) )
					 {
						 /* fan off */
						GPIOSetValue(PORT0, 2, 1);
						nbit = 1;
					 }
					 
					 if( !GPIOGetValue(PORT1, 4) )
					 {
						OLED_ClearScreen();
						GPIOSetValue(PORT0, 2, 1);
						GPIOSetValue(PORT3, 0, 1);
				    GPIOSetValue(PORT3, 1, 1);
						 
						delay_ms(300);
						break;
					 }
					 
					delay_ms(1500);
			 
				  OLED_ClearScreen();
					 
					
	 }
}



