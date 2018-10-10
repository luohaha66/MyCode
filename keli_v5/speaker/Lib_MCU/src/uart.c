/****************************************************************************
 *   $Id:: uart.c 3648 2010-06-02 21:41:06Z usb00423                        $
 *   Project: NXP LPC11xx UART example
 *
 *   Description:
 *     This file contains UART code example which include UART 
 *     initialization, UART interrupt handler, and related APIs for 
 *     UART access.
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
#include "stdarg.h"
#include "stdio.h"

#include "LPC11xx.h"
#include "uart.h"

volatile uint32_t UARTStatus;
volatile uint8_t  UARTTxEmpty = 1;
volatile uint8_t  UARTBuffer[UART0_RBUF_SIZE];
volatile uint32_t UARTCount = 0;
volatile uint32_t UART_op = 0;

/*****************************************************************************
** Function name:		UART_IRQHandler
**
** Descriptions:		UART interrupt handler
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void UART_IRQHandler(void)
{
  uint8_t IIRValue, LSRValue;
  uint8_t Dummy = Dummy;

  IIRValue = LPC_UART->IIR;
    
  IIRValue >>= 1;			/* skip pending bit in IIR */
  IIRValue &= 0x07;			/* check bit 1~3, interrupt identification */
  if (IIRValue == IIR_RLS)		/* Receive Line Status */
  {
    LSRValue = LPC_UART->LSR;
    /* Receive Line Status */
    if (LSRValue & (LSR_OE | LSR_PE | LSR_FE | LSR_RXFE | LSR_BI))
    {
      /* There are errors or break interrupt */
      /* Read LSR will clear the interrupt */
      UARTStatus = LSRValue;
      Dummy = LPC_UART->RBR;	/* Dummy read on RX to clear 
								interrupt, then bail out */
      return;
    }
    if (LSRValue & LSR_RDR)	/* Receive Data Ready */			
    {
      /* If no error on RLS, normal ready, save into the data buffer. */
      /* Note: read RBR will clear the interrupt */
      UARTBuffer[UARTCount++] = LPC_UART->RBR;
      if (UARTCount >= UART0_RBUF_SIZE)
      {
        UARTCount = 0;		/* buffer overflow */
      }	
    }
  }
  else if (IIRValue == IIR_RDA)	/* Receive Data Available */
  {
    /* Receive Data Available */
    UARTBuffer[UARTCount++] = LPC_UART->RBR;
    if (UARTCount >= UART0_RBUF_SIZE)
    {
      UARTCount = 0;		/* buffer overflow */
    }
  }
  else if (IIRValue == IIR_CTI)	/* Character timeout indicator */
  {
    /* Character Time-out indicator */
    UARTStatus |= 0x100;		/* Bit 9 as the CTI error */
  }
  else if (IIRValue == IIR_THRE)	/* THRE, transmit holding register empty */
  {
    /* THRE interrupt */
    LSRValue = LPC_UART->LSR;		/* Check status in the LSR to see if
								valid data in U0THR or not */
    if (LSRValue & LSR_THRE)
    {
      UARTTxEmpty = 1;
    }
    else
    {
      UARTTxEmpty = 0;
    }
  }
  return;
}

#if MODEM_TEST
/*****************************************************************************
** Function name:		ModemInit
**
** Descriptions:		Initialize UART0 port as modem, setup pin select.
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void ModemInit( void )
{
  LPC_IOCON->PIO2_0 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO2_0 |= 0x01;     /* UART DTR */
  LPC_IOCON->PIO0_7 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO0_7 |= 0x01;     /* UART CTS */
  LPC_IOCON->PIO1_5 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO1_5 |= 0x01;     /* UART RTS */
#if 1 
  LPC_IOCON->DSR_LOC	= 0;
  LPC_IOCON->PIO2_1 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO2_1 |= 0x01;     /* UART DSR */

  LPC_IOCON->DCD_LOC	= 0;
  LPC_IOCON->PIO2_2 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO2_2 |= 0x01;     /* UART DCD */

  LPC_IOCON->RI_LOC	= 0;
  LPC_IOCON->PIO2_3 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO2_3 |= 0x01;     /* UART RI */

#else
  LPC_IOCON->DSR_LOC = 1;
  LPC_IOCON->PIO3_1 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO3_1 |= 0x01;     /* UART DSR */

  LPC_IOCON->DCD_LOC = 1;
  LPC_IOCON->PIO3_2 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO3_2 |= 0x01;     /* UART DCD */

  LPC_IOCON->RI_LOC = 1;
  LPC_IOCON->PIO3_3 &= ~0x07;    /* UART I/O config */
  LPC_IOCON->PIO3_3 |= 0x01;     /* UART RI */
#endif
  LPC_UART->MCR = 0xC0;          /* Enable Auto RTS and Auto CTS. */			
  return;
}
#endif

/*****************************************************************************
** Function name:		UARTInit
**
** Descriptions:		Initialize UART0 port, setup pin select,
**						clock, parity, stop bits, FIFO, etc.
**
** parameters:			UART baudrate
** Returned value:		None
** 
*****************************************************************************/
void UARTInit(uint32_t baudrate)
{
  uint32_t Fdiv;
  uint32_t regVal;

  UARTTxEmpty = 1;
  UARTCount = 0;
  
  NVIC_DisableIRQ(UART_IRQn);

  LPC_IOCON->PIO1_6 &= ~0x07;    /*  UART I/O config */
  LPC_IOCON->PIO1_6 |= 0x01;     /* UART RXD */
  LPC_IOCON->PIO1_7 &= ~0x07;	
  LPC_IOCON->PIO1_7 |= 0x01;     /* UART TXD */

  /* Enable UART clock */
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);
  LPC_SYSCON->UARTCLKDIV = 0x1;     /* divided by 1 */

  LPC_UART->LCR = 0x83;             /* 8 bits, no Parity, 1 Stop bit */
  regVal = LPC_SYSCON->UARTCLKDIV;
  Fdiv = ((SystemAHBFrequency/regVal)/16)/baudrate ;	/*baud rate */

  LPC_UART->DLM = Fdiv / 256;							
  LPC_UART->DLL = Fdiv % 256;
  LPC_UART->LCR = 0x03;		/* DLAB = 0 */
  LPC_UART->FCR = 0x07;		/* Enable and reset TX and RX FIFO. */

  /* Read to clear the line status. */
  regVal = LPC_UART->LSR;

  /* Ensure a clean start, no data in either TX or RX FIFO. */
  while (( LPC_UART->LSR & (LSR_THRE|LSR_TEMT)) != (LSR_THRE|LSR_TEMT) );
  while ( LPC_UART->LSR & LSR_RDR )
  {
	regVal = LPC_UART->RBR;	/* Dump data from RX FIFO */
  }
 
  /* Enable the UART Interrupt */
  NVIC_EnableIRQ(UART_IRQn);

#if TX_INTERRUPT
  LPC_UART->IER = IER_RBR | IER_THRE | IER_RLS;	/* Enable UART interrupt */
#else
  LPC_UART->IER = IER_RBR | IER_RLS;	/* Enable UART interrupt */
#endif
  return;
}

/*****************************************************************************
** Function name:		UARTSend
**
** Descriptions:		Send a block of data to the UART 0 port based
**						on the data length
**
** parameters:			buffer pointer, and data length
** Returned value:		None
** 
*****************************************************************************/
void UARTSend(uint8_t *BufferPtr, uint32_t Length)
{
  
  while ( Length != 0 )
  {
	  /* THRE status, contain valid data */
#if !TX_INTERRUPT
	  while ( !(LPC_UART->LSR & LSR_THRE) );
	  LPC_UART->THR = *BufferPtr;
#else
	  /* Below flag is set inside the interrupt handler when THRE occurs. */
      while ( !(UARTTxEmpty & 0x01) );
	  LPC_UART->THR = *BufferPtr;
      UARTTxEmpty = 0;	/* not empty in the THR until it shifts out */
#endif
      BufferPtr++;
      Length--;
  }
  return;
}


/*******************************************************************************
* Function Name  : UART0_PutChar
* Description    : Send a char to uart0 channel.
* Input          : c
* Output         : None
* Return         : None
*******************************************************************************/
void UART0_PutChar(char ch)
{
  while(!(LPC_UART->LSR & LSR_THRE));
  LPC_UART->THR = ch;
}

/*******************************************************************************
* Function Name  : uart0_sendstring
* Description    : Send string to uart0 channel.
* Input          : pString	-- 	string
* Output         : None
* Return         : None
*******************************************************************************/
void UART0_PutString(char *pString)
{
  while(*pString)
  {
    UART0_PutChar(*pString++);
  }
}

/*******************************************************************************
* Function Name  : UART0_printf
* Description    : print format string.
* Input          : fmt
* Output         : None
* Return         : None
*******************************************************************************/
void UART0_printf(char *fmt, ...)
{
  char		uart0_pString[101];
  va_list	uart0_ap;

  va_start(uart0_ap, fmt);
  vsnprintf(uart0_pString, 100, fmt, uart0_ap);
  UART0_PutString(uart0_pString);
  va_end(uart0_ap);
}

/*******************************************************************************
* Function Name  : UART0_GetChar
* Description    : print format string.
* Input          : fmt
* Output         : None
* Return         : None
*******************************************************************************/
uint8_t UART0_GetChar(uint8_t *ch)
{
  if(UART_op != UARTCount)
  {
    *ch = UARTBuffer[UART_op];
	UART_op ++;
	if(UART_op >= UART0_RBUF_SIZE)
	  UART_op = 0;

	return 1;
  }

  return 0;
}


/******************************************************************************
**                            End Of File
******************************************************************************/
