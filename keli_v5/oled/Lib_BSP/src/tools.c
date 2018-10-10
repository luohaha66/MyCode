/*******************************************************************************
* File:    tools.c 
* Author:  Farsight Design Team
* Version: V1.00
* Date:    2011.06.21
* Brief:   Tools program body
********************************************************************************
********************************************************************************
* History:
* 2011.05.10:  V1.00		   initial version
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "lpc11xx.h"
#include "gpio.h"
#include "uart.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* External global variables -------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
* Function Name  : delay_ms.
* Description    : ms delay.
* Input          : - ms: number of ms
* Output         : None
* Return         : None
*******************************************************************************/
void delay_ms(uint32_t ms)
{
  uint32_t	tim_now, tim_max, tim_cnt, reload_numb, tim_remain;
  uint32_t	i;

  tim_now = SysTick->VAL;
  tim_max = SysTick->LOAD;  
  tim_cnt = 48000 * ms;
  reload_numb = tim_cnt / tim_max;
  tim_remain = tim_cnt % tim_max;

  
  if(reload_numb > 0)
  {
    for(i=0; i<reload_numb; i++)
    {
      while(SysTick->VAL < tim_now);
  	  while(SysTick->VAL > tim_now);
    }
  }
  
  if(tim_remain)
  {
    if(tim_remain < tim_now)
    {
      while(SysTick->VAL > (tim_now-tim_remain));
    }
    else if(tim_remain == tim_now)
    {
      while(SysTick->VAL < tim_now);
    }
    else
    {
      while(SysTick->VAL < tim_now);
  	  while(SysTick->VAL > (tim_max-(tim_remain-tim_now)));
    }
  }   
} 

/**** End of File ****/
