/*****************************************************************************
 *   acc.c:  Driver for the MMA7455 Accelerometer
 *
 *   Copyright(C) 2009, Embedded Artists AB
 *   All rights reserved.
 *
 ******************************************************************************/

/*
 * NOTE: I2C must have been initialized before calling any functions in this
 * file.
 */

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdio.h>
#include "lpc11xx.h"
#include "i2c.h"
#include "oled2864.h"
#include "key.h"
#include "tools.h"
#include "acc.h"

/******************************************************************************
 * Defines and typedefs
 *****************************************************************************/

#define ACC_I2C_ADDR    (0x1D << 1)

#define ACC_ADDR_XOUTL  0x00
#define ACC_ADDR_XOUTH  0x01
#define ACC_ADDR_YOUTL  0x02
#define ACC_ADDR_YOUTX  0x03
#define ACC_ADDR_ZOUTL  0x04
#define ACC_ADDR_ZOUTH  0x05
#define ACC_ADDR_XOUT8  0x06
#define ACC_ADDR_YOUT8  0x07
#define ACC_ADDR_ZOUT8  0x08
#define ACC_ADDR_STATUS 0x09
#define ACC_ADDR_DETSRC 0x0A
#define ACC_ADDR_TOUT   0x0B
#define ACC_ADDR_I2CAD  0x0D
#define ACC_ADDR_USRINF 0x0E
#define ACC_ADDR_WHOAMI 0x0F
#define ACC_ADDR_XOFFL  0x10
#define ACC_ADDR_XOFFH  0x11
#define ACC_ADDR_YOFFL  0x12
#define ACC_ADDR_YOFFH  0x13
#define ACC_ADDR_ZOFFL  0x14
#define ACC_ADDR_ZOFFH  0x15
#define ACC_ADDR_MCTL   0x16
#define ACC_ADDR_INTRST 0x17
#define ACC_ADDR_CTL1   0x18
#define ACC_ADDR_CTL2   0x19
#define ACC_ADDR_LDTH   0x1A
#define ACC_ADDR_PDTH   0x1B
#define ACC_ADDR_PW     0x1C
#define ACC_ADDR_LT     0x1D
#define ACC_ADDR_TW     0x1E

#define ACC_MCTL_MODE(m) ((m) << 0)
#define ACC_MCTL_GLVL(g) ((g) << 2)


#define ACC_STATUS_DRDY 0x01
#define ACC_STATUS_DOVR 0x02
#define ACC_STATUS_PERR 0x04


/******************************************************************************
 * External global variables
 *****************************************************************************/

/******************************************************************************
 * Local variables
 *****************************************************************************/

static uint8_t getStatus(void)
{
    uint8_t buf[1];

    buf[0] = ACC_ADDR_STATUS;
    I2CWrite(ACC_I2C_ADDR, buf, 1);
    I2CRead(ACC_I2C_ADDR, buf, 1);

    return buf[0];
}

static uint8_t getModeControl(void)
{
    uint8_t buf[1];

    buf[0] = ACC_ADDR_MCTL;
    I2CWrite(ACC_I2C_ADDR, buf, 1);
    I2CRead(ACC_I2C_ADDR, buf, 1);

    return buf[0];
}

static void setModeControl(uint8_t mctl)
{
    uint8_t buf[2];

    buf[0] = ACC_ADDR_MCTL;
    buf[1] = mctl;
    I2CWrite(ACC_I2C_ADDR, buf, 2);
}

/******************************************************************************
 * Local Functions
 *****************************************************************************/

/******************************************************************************
 * Public Functions
 *****************************************************************************/

/******************************************************************************
 *
 * Description:
 *    Initialize the ISL29003 Device
 *
 *****************************************************************************/
void acc_init (void)
{

    /* set to measurement mode by default */

    setModeControl( (ACC_MCTL_MODE(ACC_MODE_MEASURE)
            | ACC_MCTL_GLVL(ACC_RANGE_2G) ));

}

/******************************************************************************
 *
 * Description:
 *    Read accelerometer data
 *
 * Params:
 *   [out] x - read x value
 *   [out] y - read y value
 *   [out] z - read z value
 *
 *****************************************************************************/
void acc_read (int8_t *x, int8_t *y, int8_t *z)
{
    uint8_t buf[1];

    /* wait for ready flag */
    while ((getStatus() & ACC_STATUS_DRDY) == 0);

    /*
     * Have experienced problems reading all registers
     * at once. Change to reading them one-by-one.
     */
    buf[0] = ACC_ADDR_XOUT8;
    I2CWrite(ACC_I2C_ADDR, buf, 1);
    I2CRead(ACC_I2C_ADDR, buf, 1);

    *x = (int8_t)buf[0];

    buf[0] = ACC_ADDR_YOUT8;
    I2CWrite(ACC_I2C_ADDR, buf, 1);
    I2CRead(ACC_I2C_ADDR, buf, 1);

    *y = (int8_t)buf[0];

    buf[0] = ACC_ADDR_ZOUT8;
    I2CWrite(ACC_I2C_ADDR, buf, 1);
    I2CRead(ACC_I2C_ADDR, buf, 1);

    *z = (int8_t)buf[0];
}

/******************************************************************************
 *
 * Description:
 *    Set the g-Range
 *
 * Params:
 *   [in] range - the g-Range
 *
 *****************************************************************************/
void acc_setRange(acc_range_t range)
{
    uint8_t mctl = 0;

    mctl = getModeControl();

    mctl &= ~(0x03 << 2);
    mctl |= ACC_MCTL_GLVL(range);

    setModeControl(mctl);
}

/******************************************************************************
 *
 * Description:
 *    Set sensor mode
 *
 * Params:
 *   [in] mode - the mode to set
 *
 *****************************************************************************/
void acc_setMode(acc_mode_t mode)
{
    uint8_t mctl = 0;

    mctl = getModeControl();

    mctl &= ~(0x03 << 0);
    mctl |= ACC_MCTL_MODE(mode);

    setModeControl(mctl);
}

/*******************************************************************************
* Function Name  : Axis3_Test
* Description    : Light Sensor Test.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Axis3_Test(void)
{
  char		buf[24];
  int32_t	xoff = 0;
  int32_t	yoff = 0;
  int32_t	zoff = 0;
  int8_t	x = 0;
  int8_t	y = 0;
  int8_t	z = 0;

   
  OLED_ClearScreen();
  OLED_DisStrLine(0, 0, "Axis-3");
  

  I2CInit(I2CMASTER, 0);

  acc_init();
  /* Assume base board in zero-g position when reading first value. */
  acc_read(&x, &y, &z);
  xoff = 0-x;
  yoff = 0-y;
  zoff = 0-z;

 // while(1)
 // {	
    /* Accelerometer */
    acc_read(&x, &y, &z);
    x = x+xoff;
    y = y+yoff;
    z = z+zoff;

    snprintf(buf, 20, "Acc x: %d  ", x);
    OLED_DisStrLine(2, 0, (uint8_t *)buf);
	printf("\r\nAcc x: %d,  ", x);

	snprintf(buf, 20, "Acc y: %d  ", y);
    OLED_DisStrLine(3, 0, (uint8_t *)buf);
	printf("Acc y: %d,  ", y);

	snprintf(buf, 20, "Acc z: %d  ", z);
    OLED_DisStrLine(4, 0, (uint8_t *)buf);
	printf("Acc z: %d. ", z);
	
	delay_ms(250);

  //  if(KEY_Read() == KEY_ESC)
  //	 break;
 // }
}


