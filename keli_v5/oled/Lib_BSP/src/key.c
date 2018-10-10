/******************** (C) COPYRIGHT 2011 FS ************************************
* File Name          : key.c
* Author             : FS_11C14 Application Team
* Version            : V1.00
* Date               : 06/20/2011
* Description        : Keyboard's service routines
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "lpc11xx.h"
#include "gpio.h"
#include "key.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : KEY_Init
* Description    : Init the keyboard GPIO ports pins.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void KEY_Init(void)
{
  GPIOSetDir(PORT0, 3, 0);
  GPIOSetDir(PORT1, 4, 0);

  GPIOSetDir(PORT1, 8, 0);
  GPIOSetDir(PORT1, 9, 0);
  GPIOSetDir(PORT1, 10, 0);
  GPIOSetDir(PORT1, 11, 0);
}

/*******************************************************************************
* Function Name  : KEY_Read
* Description    : Reads key from demoboard.
* Input          : None
* Output         : None
* Return         : Return RIGHT, LEFT, SEL, UP, DOWN, USER or NONE
*******************************************************************************/
uint16_t KEY_Read(void)
{ 
  // "UP" key is pressed
  if(!GPIOGetValue(PORT1, 8))
  { 
    return KEY_UP; 
  }

  // "DOWN" key is pressed
  if(!GPIOGetValue(PORT1, 9))
  { 
    return KEY_DOWN; 
  }

  // "LEFT" key is pressed
  if(!GPIOGetValue(PORT1, 10))
  { 
    return KEY_LEFT; 
  }

  // "RIGHT" key is pressed
  if(!GPIOGetValue(PORT1, 11))
  { 
    return KEY_RIGHT; 
  }

  // "SEL" key is pressed
  if(!GPIOGetValue(PORT0, 3))
  { 
    return KEY_SEL; 
  }

  // "ESC" key is pressed
  if(!GPIOGetValue(PORT1, 4))
  { 
    return KEY_ESC; 
  }
  	
  return KEY_NONE;
}


/**** END OF FILE ****/

