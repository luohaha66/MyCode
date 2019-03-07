/*******************************************************************************
* File:    temp_hum.h 
* Author:  FarSight Design Team
* Version: V1.00
* Date:    2011.06.21
* Brief:   Temperature & humidity head
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TEMP_HUM_H
#define __TEMP_HUM_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "LPC11xx.h"
#include "data_type.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint32_t Read_Temp_Hum(uint8_t *l_temp,uint8_t *h_temp,uint8_t *l_hum,uint8_t *h_hum);
void Temp_Hum_Test(void);

/* External variables --------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* __TEMP_HUM_H */

/**** End of File ****/