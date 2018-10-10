/*******************************************************************************
* File Name          : spi_uart.h
* Author             : Farsight Design Team
* Version            : V1.00
* Date               : 2011.06.20
* Description        : Segment 7 LED program head
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_UART_H
#define __SPI_UART_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "LPC11xx.h"
#include "gpio.h"

/* Exported types ------------------------------------------------------------*/
#define SPI_UART_CS(x)		GPIOSetValue(PORT2, 0, x)
#define SPI_UART_CLK(x)		GPIOSetValue(PORT2, 1, x)
#define SPI_UART_MISO(x)	GPIOSetValue(PORT2, 2, x)		
#define SPI_UART_MOSI(x)	GPIOSetValue(PORT2, 3, x)


// SPI to UART IC is SC16IS752
// Command & Registers

// Command
#define SPI752_READ				0x80
#define SPI752_WRITE			0x00

// Channel
#define SPI752_CH0				0x00
#define SPI752_CH1				0x01

// LCR[7]==0, & LCR!=0xBF
#define SPI752_RHR_R			0x00
#define SPI752_THR_W			0x00
#define SPI752_IER_RW			0x01
#define SPI752_FCR_W			0x02
#define SPI752_IIR_R			0x02
#define SPI752_LCR_RW			0x03
#define SPI752_MCR_RW			0x04
#define SPI752_LSR_R			0x05
#define SPI752_MSR_R			0x06
#define SPI752_SPR_RW			0x07
#define SPI752_TCR_RW			0x06
#define SPI752_TLR_RW			0x07
#define SPI752_TXLVL_R			0x08
#define SPI752_RXLVL_R			0x09
#define SPI752_IODir_RW			0x0A
#define SPI752_IOState_RW		0x0B
#define SPI752_IOIntEna_RW		0x0C
#define SPI752_IOControl_RW		0x0E
#define SPI752_EFCR_RW			0x0F

// LCR[7]==1, & LCR!=0xBF
#define SPI752_DLL_RW			0x00
#define SPI752_DLH_RW			0x01

// LCR==0xBF
#define SPI752_EFR_RW			0x02
#define SPI752_Xon1_RW			0x04
#define SPI752_Xon2_RW			0x05
#define SPI752_Xoff1_RW			0x06
#define SPI752_Xoff2_RW			0x06

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void ZigBee_IRQ_Process(void);
uint8_t SPI752_RegRead(uint8_t Channel, uint8_t Reg);
void SPI752_RegWrite(uint8_t Channel, uint8_t Reg, uint8_t Data);
void SPI752_Init(uint8_t Channel, uint32_t Baud);
void SPI752_PutChar(uint8_t Channel, uint8_t Ch);
void RS485_PutChar(uint8_t Ch);
void RS485_PutString(uint8_t *pStr);
void ZigBee_PutChar(uint8_t Ch);
void ZigBee_PutString(uint8_t *pStr);
uint8_t SPI752_GetChar(uint8_t Channel, uint8_t *Ch);
uint8_t RS485_GetChar(uint8_t *Ch);
uint8_t ZigBee_GetChar(uint8_t *Ch);
void SPI_UART_Test(void);
void ZigBee_Menu_01(uint32_t numb);
void ZigBee_Test(void);


#ifdef __cplusplus
}
#endif

#endif /* __SEG7LED_H */

/**** End of File ****/
