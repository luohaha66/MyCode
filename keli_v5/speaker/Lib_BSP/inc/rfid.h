/*******************************************************************************
* File Name          : rfid.h
* Author             : Farsight Design Team
* Version            : V1.00
* Date               : 2011.06.20
* Description        : RFID program head
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RFID_H
#define __RFID_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "LPC11xx.h"

/* Exported types ------------------------------------------------------------*/
#define RFID_CS(x)		GPIOSetValue(PORT2, 7, x)
#define RFID_CLK(x)		GPIOSetValue(PORT0, 6, x)
#define RFID_MISO(x)	GPIOSetValue(PORT0, 8, x)
#define RFID_MOSI(x)	GPIOSetValue(PORT0, 9, x)

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint8_t RFID_CheckSum(uint8_t *databuf);
uint8_t RFID_Operate(uint8_t *tbuf, uint8_t *rbuf);
void RFID_Test(void);

/* External variables --------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __RFID_H */

/**** End of File ****/
