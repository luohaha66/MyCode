/*******************************************************************************
* File:    temp_hum.c 
* Author:  FarSight Design Team
* Version: V1.00
* Date:    2011.06.21
* Brief:   Temperature & humidity program
*******************************************************************************/ 

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "LPC11xx.h"
#include "gpio.h"
#include "oled2864.h"
#include "key.h"
#include "tools.h"
#include "temp_hum.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern volatile uint32_t p3_2_counter;
extern volatile uint32_t p3_2_tc;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
* Function Name  : Read_Temp_Hum
* Description    : Read Temp & Hum.
* Input          : - temp : temp buf pointer.
*                  - hum : hum buf pointer.
* Output         : - temp[0] : temp x. part
*                  - temp[1] : temp .x part
*                  - hum[0] : hum x. part
*                  - hum[1] : hum .x part
* Return         : - 1, checksum ok
*                  - 0, checksum fail
*******************************************************************************/
uint32_t Read_Temp_Hum(uint8_t *l_temp,uint8_t *h_temp,uint8_t *l_hump,uint8_t *h_hump)
{
  uint32_t	cnt_last;
  uint8_t	chksum, chk;
  uint32_t	tc1, tc;
  uint32_t	i;

  p3_2_counter = 0;
  cnt_last = p3_2_counter;

  GPIOIntDisable(PORT1, 5);

  GPIOSetDir(PORT1, 5, 1);			// Set PIO1_5 to output
  GPIOSetValue(PORT1, 5, 0);
  delay_ms(30);
  GPIOSetValue(PORT1, 5, 1);

  GPIOSetDir(PORT1, 5, 0);
  GPIOSetInterrupt(PORT1, 5, 0, 0, 0);
  GPIOIntEnable(PORT1, 5);

  for(i=0; i<3; i++)				 // the start and answer signal
  {
    GPIOSetInterrupt(PORT1, 5, 0, 0, i&0x01);
    while(p3_2_counter == cnt_last);
    cnt_last = p3_2_counter;
  }

  for(i=0; i<40; i++)
  {
	GPIOSetInterrupt(PORT1, 5, 0, 0, 1);
    while(p3_2_counter == cnt_last);
    cnt_last = p3_2_counter;
	tc1 = p3_2_tc;

	GPIOSetInterrupt(PORT1, 5, 0, 0, 0);
    while(p3_2_counter == cnt_last);
    cnt_last = p3_2_counter;

    if(p3_2_tc < tc1)
	{
	  tc = tc1 - p3_2_tc;			//tc:the high lever time
	}
	else
	{
	  tc = 48000 - (p3_2_tc - tc1);
	}

	if(i < 8)
	{
	  *h_hump <<= 1;
	  if(tc >= 2328)     //
	    *h_hump |= 0x01;
	}
	else if(i < 16)
	{
	  *l_hump <<= 1;
	  if(tc >= 2328)
	    *l_hump |= 0x01;
	}
	else if(i < 24)
	{
	  *h_temp <<= 1;
	  if(tc >= 2328)
	    *h_temp |= 0x01;
	}
	else if(i < 32)
	{
	  *l_temp <<= 1;
	  if(tc >= 2328)
	    *l_temp |= 0x01;
	}
	else
	{
	  chksum <<= 1;
	  if(tc >= 2328)
	    chksum |= 0x01;
	}
  }

  GPIOSetInterrupt(PORT1, 5, 0, 0, 1);
  while(p3_2_counter == cnt_last);

  GPIOIntDisable(PORT1, 5);

  chk = *h_hump;
  chk += *l_hump;
  chk += *h_temp;
  chk += *l_temp;

  if(chk == chksum)
    return 1;
  else
    return 0;
}



