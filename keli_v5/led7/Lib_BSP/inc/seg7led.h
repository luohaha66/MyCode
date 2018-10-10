/*******************************************************************************
* File Name          : seg7led.h
* Author             : Farsight Design Team
* Version            : V1.00
* Date               : 2011.06.20
* Description        : Segment 7 LED program head
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SEG7LED_H
#define __SEG7LED_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "LPC11xx.h"
#include "gpio.h"

/* Exported types ------------------------------------------------------------*/
#define SEG7LED_CS(x)		GPIOSetValue(PORT2, 9, x)
#define SEG7LED_CLK(x)		GPIOSetValue(PORT2, 10, x)		
#define SEG7LED_MOSI(x)		GPIOSetValue(PORT2, 11, x)

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Seg7Led_Init(void);
void Seg7Led_Put(uint8_t numb);

/* External variables --------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __SEG7LED_H */

/**** End of File ****/
