/*******************************************************************************
* File:    rfid.c 
* Author:  FarSight Design Team
* Version: V1.00
* Date:    2011.06.21
* Brief:   RFID program
*******************************************************************************/ 

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "LPC11xx.h"
#include "gpio.h"
#include "ssp.h"
#include "oled2864.h"
#include "key.h"
#include "tools.h"
#include "rfid.h"
#include "menu.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
const uint8_t RFID_READ_MOD_TYPE_01[2] = {0x02, 0x01};
const uint8_t RFID_READ_CARD_20[2] = {0x02, 0x20};
const uint8_t RFID_READ_DATA_BLOCK_21[10] =  {0x0a, 0x21, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; 
const uint8_t RFID_WRITE_DATA_BLOCK_22[26] = {0x1a, 0x22, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                              0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
										      0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10}; 


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/*******************************************************************************
* Function Name  : RFID_CheckSum
* Description    : Init RFID control.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint8_t RFID_CheckSum(uint8_t *databuf)
{ 
  uint8_t	numb, chksum;
  uint32_t	i;

  numb = databuf[0]-1;
  for(i=0; i<databuf[0]; i++)
  {
    if(databuf[i] == 0xaa)
	  numb ++;
  }

  chksum = databuf[0];
  while(numb)
  {
    chksum ^= databuf[numb];
    numb --;
  }

  return chksum;
}

/*******************************************************************************
* Function Name  : RFID_Operate
* Description    : Output segment to LED.
* Input          : - numb : display number.
* Output         : None
* Return         : None
*******************************************************************************/
uint8_t RFID_Operate(uint8_t *tbuf, uint8_t *rbuf)
{
  uint8_t	chksum;
  uint32_t	i, j, rnumb;

  SPI_Init(0, 8, 128);
  delay_ms(1);
  RFID_CS(0);

  chksum = RFID_CheckSum(tbuf);

  SPI_PutGet(0, 0xaa);
  delay_ms(1);

  i = 0;
  rbuf[i] = SPI_PutGet(0, 0xbb);
  i ++;
  delay_ms(1);

  for(j=0; j<tbuf[0]; j++)
  {
    rbuf[i] = SPI_PutGet(0, tbuf[j]);
	i ++;
    delay_ms(1);
  }

  rbuf[i] = SPI_PutGet(0, chksum);
  i ++;

  delay_ms(500);

  rbuf[0] = 1;

  SPI_PutGet(0, 0);
  delay_ms(1);
  
  if(SPI_PutGet(0, 0) != 0xaa)
  {
    SPI_Init(0, 8, 2);
    return 0;
  }

  delay_ms(1);
  
  if(SPI_PutGet(0, 0) != 0xbb)
  {
    SPI_Init(0, 8, 2);
    return 0;
  }
	
  delay_ms(1);
	 
  switch(tbuf[1])
  {
    case 0x01:
	  rnumb = 8 + 2 + 1;
	  break;

	case 0x20:
	  rnumb = 4 + 2 + 1;
	  break;

	case 0x21:
	  rnumb = 16 + 2 + 1;
	  break;

	case 0x22:
	  rnumb = 2 + 1;
	  break;

	default:
	  rnumb = 4 + 2 + 1;
	  break;
  }

  for(j=0, i=0; j<rnumb; j++, i++)
  {
    rbuf[i] = SPI_PutGet(0, 0);
	delay_ms(1);
  }

  RFID_CS(1);

  delay_ms(1);

  SPI_Init(0, 8, 2);

  return i;
}

/*******************************************************************************
* Function Name  : ZigBee_Test
* Description    : ZigBee test.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RFID_Test(void)
{
  Menu_TypeDef	menu;
  uint16_t	key, x;
  uint8_t	rbuf[36], chksum;
  char		buf[8];
  uint32_t	i, j;


  menu.max_numb = 2;
  menu.numb = 1;
  menu.title = "RFID";
  menu.item[0] = "1.Read Card";
  menu.item[1] = "2.Write Card";
  
  Dis_Menu(menu);

  delay_ms(250);

  // use port2_8 as input event, ZigBee interrupt.
  GPIOSetDir(PORT2, 8, 0);
  // port2_8 interrupt. edge, single trigger, falling edges.
  //GPIOSetInterrupt(PORT2, 8, 0, 0, 0);
  //GPIOIntEnable(PORT2, 8);
  
  while(menu.numb)
  {
	if(!GPIOGetValue(PORT2, 8))
    { 
	  delay_ms(200);

      j = RFID_Operate((uint8_t *)RFID_READ_DATA_BLOCK_21, rbuf);
	  
      printf("\r\n");	
      for(i=0, x=0; i<j; i++)
      {
		if(x <= 108)
		{
		  snprintf(buf, 4, "%02X ", rbuf[i]);
		  OLED_DisChar(2-1 + 5, x, 0, buf[0]);
          x += 6;
          OLED_DisChar(2-1 + 5, x, 0, buf[1]);
          x += 6;
          OLED_DisChar(2-1 + 5, x, 0, buf[2]);
          x += 6;
        }
        printf("%02X ", rbuf[i]);
      }

      chksum = RFID_CheckSum(rbuf);

      if(chksum == rbuf[rbuf[0]])
      {
        OLED_DisStrLine(2-1 + 6, 0, "Ok  ");
        printf("\r\nOk ");
      }
      else
      {
		OLED_DisStrLine(2-1 + 5, 0, "                     ");
        OLED_DisStrLine(2-1 + 6, 0, "Fail");
        printf("\r\nFail ");
      }
	  
	  delay_ms(200); 
    }

    key = KEY_Read();

    switch(key)
	{
	  case KEY_UP:
	    if(menu.numb > 1)
		  menu.numb --;
		else
		  menu.numb = menu.max_numb;
		Dis_Menu(menu);
		break;

	  case KEY_DOWN:	    
		if(menu.numb < menu.max_numb)
		  menu.numb ++;
		else
		  menu.numb = 1;
		Dis_Menu(menu);
		break;

	  case KEY_SEL:
	    switch(menu.numb)
		{
		  case 1:
		    printf("\r\nRFID Read");		    
			j = RFID_Operate((uint8_t *)RFID_READ_DATA_BLOCK_21, rbuf);
	  
	        printf("\r\n");	
            for(i=0, x=0; i<j; i++)
            {
			  if(x <= 108)
			  {
			    snprintf(buf, 4, "%02X ", rbuf[i]);
			    OLED_DisChar(2-1 + 5, x, 0, buf[0]);
	            x += 6;
				OLED_DisChar(2-1 + 5, x, 0, buf[1]);
	            x += 6;
				OLED_DisChar(2-1 + 5, x, 0, buf[2]);
	            x += 6;
	          }
              printf("%02X ", rbuf[i]);
            }

            chksum = RFID_CheckSum(rbuf);

            if(chksum == rbuf[rbuf[0]])
	        {
	          OLED_DisStrLine(2-1 + 6, 0, "Ok  ");
              printf("\r\nOk ");
	        }
            else
	        {
			  OLED_DisStrLine(2-1 + 5, 0, "                     ");
	          OLED_DisStrLine(2-1 + 6, 0, "Fail");
              printf("\r\nFail ");
	        }
		    break;

		  case 2:
		    printf("\r\nRFID Write");		    
			j = RFID_Operate((uint8_t *)RFID_WRITE_DATA_BLOCK_22, rbuf);
	  
	        printf("\r\n");	
            for(i=0, x=0; i<j; i++)
            {
			  if(x <= 108)
			  {
			    snprintf(buf, 4, "%02X ", rbuf[i]);
			    OLED_DisChar(2-1 + 5, x, 0, buf[0]);
	            x += 6;
				OLED_DisChar(2-1 + 5, x, 0, buf[1]);
	            x += 6;
				OLED_DisChar(2-1 + 5, x, 0, buf[2]);
	            x += 6;
	          }
              printf("%02X ", rbuf[i]);
            }

            chksum = RFID_CheckSum(rbuf);

            if(chksum == rbuf[rbuf[0]])
	        {
	          OLED_DisStrLine(2-1 + 6, 0, "Ok  ");
              printf("\r\nOk ");
	        }
            else
	        {
			  OLED_DisStrLine(2-1 + 5, 0, "                     ");
	          OLED_DisStrLine(2-1 + 6, 0, "Fail");
              printf("\r\nFail ");
	        }
		    break;

		  default:
		    break;
		}
	    break;
	  
	  case KEY_ESC:	    	    
        menu.numb = 0;		
	    break;
		
	  default:
	    break; 
	}

	if((key!=KEY_NONE) && (menu.numb!=0))
	{
	  delay_ms(250);
	}
  }
}

/*******************************************************************************
* Function Name  : RFID_Test
* Description    : RFID Test.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/*
void RFID_Test(void)
{
  uint8_t	rbuf[36], chksum;
  uint32_t	i, j;

  OLED_ClearScreen();
  OLED_DisStrLine(0, 0, "RFID");
  printf("\r\nRFID\r\n");

  while(KEY_Read() != KEY_ESC)
  {
    if(KEY_Read() == KEY_SEL)
	{
      j = RFID_Operate((uint8_t *)RFID_READ_DATA_BLOCK_21, rbuf);
	  
	  printf("\r\n");	
      for(i=0; i<j; i++)
      {
        printf("%02X ", rbuf[i]);
      }

      chksum = RFID_CheckSum(rbuf);

      if(chksum == rbuf[rbuf[0]])
	  {
	    OLED_DisStrLine(2-1 + 6, 0, "ok  ");
        printf("ok");
	  }
      else
	  {
	    OLED_DisStrLine(2-1 + 6, 0, "fail");
        printf("fail");
	  }
	}
  }
}
*/
	

/**** End of File ****/


