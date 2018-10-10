/*******************************************************************************
* File:    main.c 
* Author:  FarSight Design Team
* Version: V1.00
* Date:    2011.06.21
* Brief:   Main program body
*******************************************************************************/ 

/* Includes ------------------------------------------------------------------*/
#include "LPC11xx.h"
#include "gpio.h"
#include "numbled.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static const uint8_t segmentlut[10] =
{
  // FCPBAGED
  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  0xdb, 0x50, 0x1f, 0x5d, 0xd4, 0xcd, 0xcf, 0x58, 0xdf, 0xdd
};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
* Function Name  : SetSegment
* Description    : Output segment.
* Input          : - n : display number.
* Output         : None
* Return         : None
*******************************************************************************/
void SetSegment(int n)
{
  int i;

  GPIOSetValue(1, 11, 0);

  if(n < 0)
    n = 0;
  else
    n = segmentlut[n];

  for(i=0;i<8;i++)
  {
    if((n>>(7-i))&1)
      GPIOSetValue(0, 9, 0);
    else
      GPIOSetValue(0, 9, 1);

    GPIOSetValue(2, 11, 0);
    GPIOSetValue(2, 11, 1);
  }
  GPIOSetValue(1, 11, 1);
}

/*******************************************************************************
* Function Name  : Init7Segment
* Description    : Init segment.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Init7Segment(void)
{
  // Turn off 7-segment display
  GPIOSetDir(0, 9, 1);		// MOSI
  GPIOSetDir(2, 11, 1);		// CLK
  GPIOSetDir(1, 11, 1);		// CS
  GPIOSetValue(1, 11, 0);
  SetSegment(-1);
}


/**** End of File ****/


