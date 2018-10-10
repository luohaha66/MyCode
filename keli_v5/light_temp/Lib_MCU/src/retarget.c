/*----------------------------------------------------------------------------
 * Name:    Retarget.c
 * Purpose: 'Retarget' layer for target-dependent low level functions
 * Version: V1.0
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * Copyright (c) 2005-2008 Keil Software. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <rt_misc.h>
#include "LPC11xx.h"
#include "uart.h"


#pragma import(__use_no_semihosting_swi)


extern volatile uint32_t UARTCount;
extern volatile uint8_t UARTBuffer[UART0_RBUF_SIZE];

/*----------------------------------------------------------------------------
  external functions
 *----------------------------------------------------------------------------*/
int  PutCh(int ch);
int  GetCh(void);


struct __FILE {
  int handle;                 // Add whatever you need here 
};
FILE __stdout;
FILE __stdin;


/*----------------------------------------------------------------------------
  fputc
 *----------------------------------------------------------------------------*/
int fputc(int ch, FILE *f) {
  return (PutCh(ch));
}

/*----------------------------------------------------------------------------
  fgetc
 *----------------------------------------------------------------------------*/
int fgetc(FILE *f) {
  return (PutCh(GetCh()));
}

/*----------------------------------------------------------------------------
  _ttywrch
 *----------------------------------------------------------------------------*/
void _ttywrch(int ch) {
  PutCh(ch);
}

/*----------------------------------------------------------------------------
  ferror
 *----------------------------------------------------------------------------*/
int ferror(FILE *f) {
                              // Your implementation of ferror
  return EOF;
}

/*----------------------------------------------------------------------------
  _sys_exit
 *----------------------------------------------------------------------------*/
void _sys_exit(int return_code) {
label:  goto label;           // endless loop
}


/*******************************************************************************
* Function Name  : PutCh
* Description    : Send char.
* Input          : - ch : char.
* Output         : None
* Return         : - intput char.
*******************************************************************************/
int PutCh(int ch)
{
  /* Loop until the end of transmission */
  while(!(LPC_UART->LSR & LSR_THRE));
 
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */  
  LPC_UART->THR = ch;

  return ch;
}

/*******************************************************************************
* Function Name  : GetCh
* Description    : Receive char.
* Input          : None
* Output         : None
* Return         : - received char.
*******************************************************************************/
int GetCh(void)
{
  while(UARTCount == 0);

  LPC_UART->IER = IER_THRE | IER_RLS;			/* Disable RBR */
  //UARTSend( (uint8_t *)UARTBuffer, UARTCount );
  UARTCount = 0;
  LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */

  return UARTBuffer[0];
}

/*******************************************************************************
* Function Name  : GetCh_NoIRQ
* Description    : Receive char.
* Input          : None
* Output         : None
* Return         : - received char.
*******************************************************************************/
int GetCh_NoIRQ(void)
{
  while(!(LPC_UART->LSR & LSR_RDR));

  return LPC_UART->RBR;
}


