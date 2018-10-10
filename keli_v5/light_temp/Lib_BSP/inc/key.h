/*******************************************************************************
* File Name          : key.h
* Author             : Farsight Design Team
* Version            : V1.00
* Date               : 2011.06.20
* Description        : Keyboard program head
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_H
#define __KEY_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#define  KEY_NONE   0
#define  KEY_UP     1
#define  KEY_DOWN   2
#define  KEY_LEFT   3
#define  KEY_RIGHT  4
#define  KEY_SEL    5
#define  KEY_ESC    6

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void KEY_Init(void);
uint16_t KEY_Read(void);

/* External variables --------------------------------------------------------*/

#endif /* __KEY_H */

/**** END OF FILE ****/


