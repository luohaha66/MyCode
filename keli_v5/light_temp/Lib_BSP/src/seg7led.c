/*******************************************************************************
* File:    seg7led.c 
* Author:  FarSight Design Team
* Version: V1.00
* Date:    2011.06.21
* Brief:   Segment 7 LED program body
*******************************************************************************/ 

/* Includes ------------------------------------------------------------------*/
#include "LPC11xx.h"
#include "gpio.h"
#include "seg7led.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
const uint8_t segcode[32] =
{
  // C.FEGBAD
  // 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   b,   C,   d,   E,   F,
  0x48,0x7b,0xd0,0x70,0x63,0x64,0x44,0x79,0x40,0x60,0x41,0x46,0xcc,0x52,0xc4,0xc5,
  //0.,  1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.,  9.,  A.,  b.,  C.,  d.,  E.,  F.,
  0x08,0x3b,0x90,0x30,0x23,0x24,0x04,0x39,0x00,0x20,0x01,0x06,0x8c,0x12,0x84,0x85
};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
* Function Name  : Seg7Led_Init
* Description    : Init segment LED control.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Seg7Led_Init(void)
{
  GPIOSetDir(2, 9, 1);		// CS
  SEG7LED_CS(1);
  GPIOSetDir(2, 10, 1);		// CLK
  SEG7LED_CLK(1);
  GPIOSetDir(2, 11, 1);		// MOSI  
}

/*******************************************************************************
* Function Name  : Seg7Led_Put
* Description    : Output segment to LED.
* Input          : - numb : display number.
* Output         : None
* Return         : None
*******************************************************************************/
void Seg7Led_Put(uint8_t numb)
{
  uint32_t i;

  if(numb >= 0x20)
    numb = 0xff;
  else
    numb = segcode[numb&0x1f];

  SEG7LED_CS(0);

  for(i=0; i<8; i++)
  {
    SEG7LED_CLK(0);
    SEG7LED_MOSI(numb&0x01);
    numb = numb >> 1;
    SEG7LED_CLK(1);
  }

  SEG7LED_CS(1);
}


/**** End of File ****/


