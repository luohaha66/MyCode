/****************************************************************************
 *   $Id:: pmu.c 3635 2010-06-02 00:31:46Z usb00423                         $
 *   Project: NXP LPC11xx PMU example
 *
 *   Description:
 *     This file contains PMU code example which include PMU 
 *     initialization, PMU interrupt handler, and APIs for PMU
 *     reading.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#include "LPC11xx.h"			/* LPC11xx Peripheral Registers */
#include "type.h"
#include "gpio.h"
#include "pmu.h"

volatile uint32_t pmu_counter = 0;

/*****************************************************************************
** Function name:		WAKEUP_IRQHandler
**
** Descriptions:		WAKEUP Interrupt Handler
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void WAKEUP_IRQHandler(void)
{
  uint32_t regVal;

  /* This handler takes care all the port pins if they
  are configured as wakeup source. */
  regVal = LPC_SYSCON->STARTSRP0;
  if ( regVal != 0 )
  {
	LPC_SYSCON->STARTRSRP0CLR = regVal;
  }
  /* See tracker for bug report. */
  __NOP();
  return;
}

/*****************************************************************************
** Function name:		PMU_Init
**
** Descriptions:		Initialize PMU and setup wakeup source.
**						For Sleep and deepsleep, any of the I/O pins can be 
**						used as the wakeup source.
**						For Deep Powerdown, only pin P1.4 can be used as 
**						wakeup source from deep powerdown. 
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void PMU_Init( void )
{
  uint32_t i;

  /* Enable all clocks, even those turned off at power up. */
  LPC_SYSCON->PDRUNCFG &= ~(WDT_OSC_PD|SYS_OSC_PD|ADC_PD);

  for ( i = 0; i < NUM_OF_WAKESOURCE; i++ )
  {
	NVIC_EnableIRQ((IRQn_Type)(WAKEUP0_IRQn+i));
  }

  /* use port0_0~11 as wakeup source, i/o pin */
  LPC_IOCON->RESET_PIO0_0 &= ~0x07;	
  LPC_IOCON->RESET_PIO0_0 |= 0xE1;	
  GPIOSetDir( PORT0, 0, 0 );	/* Input P0.0 */
  LPC_IOCON->PIO0_1 &= ~0x07;	
  LPC_IOCON->PIO0_1 |= 0x20;	
  GPIOSetDir( PORT0, 1, 0 );	/* Input P0.1 */
  LPC_IOCON->PIO0_2 &= ~0x07;	
  LPC_IOCON->PIO0_2 |= 0x20;	
  GPIOSetDir( PORT0, 2, 0 );	/* Input P0.2 */
  LPC_IOCON->PIO0_3 &= ~0x07;	
  LPC_IOCON->PIO0_3 |= 0x20;	
  GPIOSetDir( PORT0, 3, 0 );	/* Input P0.3 */
  LPC_IOCON->PIO0_4 &= ~0x07;	
  LPC_IOCON->PIO0_4 |= 0x20;	
  GPIOSetDir( PORT0, 4, 0 );	/* Input P0.4 */

  LPC_IOCON->PIO0_5 &= ~0x07;	
  LPC_IOCON->PIO0_5 |= 0x20;	
  GPIOSetDir( PORT0, 5, 0 );	/* Input P0.5 */
  LPC_IOCON->PIO0_6 &= ~0x07;	
  LPC_IOCON->PIO0_6 |= 0x20;	
  GPIOSetDir( PORT0, 6, 0 );	/* Input P0.6 */
  LPC_IOCON->PIO0_7 &= ~0x07;	
  LPC_IOCON->PIO0_7 |= 0x20;	
  GPIOSetDir( PORT0, 7, 0 );	/* Input P0.7 */
  LPC_IOCON->PIO0_8 &= ~0x07;	
  LPC_IOCON->PIO0_8 |= 0x20;	
  GPIOSetDir( PORT0, 8, 0 );	/* Input P0.8 */
  LPC_IOCON->PIO0_9 &= ~0x07;	
  LPC_IOCON->PIO0_9 |= 0x20;	
  GPIOSetDir( PORT0, 9, 0 );	/* Input P0.9 */
  
  LPC_IOCON->SWCLK_PIO0_10 &= ~0x07;	
  LPC_IOCON->SWCLK_PIO0_10 |= 0xE1;	
  GPIOSetDir( PORT0, 10, 0 );	/* Input P0.10 */
  LPC_IOCON->R_PIO0_11 &= ~0x07;	
  LPC_IOCON->R_PIO0_11 |= 0xE1;	
  GPIOSetDir( PORT0, 11, 0 );	/* Input P0.11 */
 
  /* use port1_0 as wakeup source, i/o pin */
  LPC_IOCON->R_PIO1_0 &= ~0x07;	
  LPC_IOCON->R_PIO1_0 |= 0xE1;	
  GPIOSetDir( PORT1, 0, 0 );	/* Input P1.0 */
  
  /* Only edge trigger. activation polarity on P1.0~11 and P1.0 is FALLING EDGE. */
  LPC_SYSCON->STARTAPRP0 = 0x00000000;
  /* Clear all wakeup source */ 
  LPC_SYSCON->STARTRSRP0CLR = 0xFFFFFFFF;
  /* Enable Port0~11 and Port 1.0 as wakeup source. */
  LPC_SYSCON->STARTERP0 = (0x1<<12)|(0xFFF<<0);
  return;
}

/*****************************************************************************
** Function name:		PMU_Sleep
**
** Descriptions:		Put some of the peripheral in sleep mode.
**
** parameters:			SleepMode: 1 is deep sleep, 0 is sleep, 
**						Sleep peripheral module(s)
** Returned value:		None
** 
*****************************************************************************/
void PMU_Sleep( uint32_t SleepMode, uint32_t SleepCtrl )
{
  LPC_SYSCON->PDAWAKECFG = LPC_SYSCON->PDRUNCFG;
  LPC_SYSCON->PDSLEEPCFG = SleepCtrl;
  /* If normal sleep, not deep sleep, don't do anything to SCR reg. */
  if ( SleepMode )
  {
	SCB->SCR |= NVIC_LP_SLEEPDEEP;
  }
  __WFI();
  return;
}

/*****************************************************************************
** Function name:		PMU_PowerDown
**
** Descriptions:		Some of the content should not be touched 
**						during the power down to wakeup process.
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void PMU_PowerDown( void )
{
  uint32_t regVal;

  if ( (LPC_PMU->PCON & (0x1<<11)) != 0x0 )
  {
    /* Check deep power down bits. If deep power down mode is entered, 
    clear the PCON bits. */
    regVal = LPC_PMU->PCON;
    regVal |= (0x1<<11);
    LPC_PMU->PCON = regVal;

    if ( (LPC_PMU->GPREG0 != 0x12345678)||(LPC_PMU->GPREG1 != 0x87654321)
         ||(LPC_PMU->GPREG2 != 0x56781234)||(LPC_PMU->GPREG3 != 0x43218765) )
    {
      while (1);
    }
  }
  else
  {
	/* If in neither sleep nor deep power mode, enter deep power
	down mode now. */
    LPC_PMU->GPREG0 = 0x12345678;
    LPC_PMU->GPREG1 = 0x87654321;
    LPC_PMU->GPREG2 = 0x56781234;
    LPC_PMU->GPREG3 = 0x43218765;
	SCB->SCR |= NVIC_LP_SLEEPDEEP;
    LPC_PMU->PCON = 0x2;
    __WFI();
  }
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
