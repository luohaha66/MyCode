/*****************************************************************************
 *   light.c:  Driver for the ISL29003 Light-to-Digital Output Sensor
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

#include "lpc11xx.h"
#include "type.h"
#include "i2c.h"
#include "light.h"

/******************************************************************************
 * Defines and typedefs
 *****************************************************************************/

#define LIGHT_I2C_ADDR    (0x44 << 1)

#define ADDR_CMD        0x00
#define ADDR_CTRL       0x01
#define ADDR_IRQTH_HI   0x02
#define ADDR_IRQTH_LO   0x03
#define ADDR_LSB_SENSOR 0x04
#define ADDR_MSB_SENSOR 0x05
#define ADDR_LSB_TIMER  0x06
#define ADDR_MSB_TIMER  0x07

#define ADDR_CLAR_INT   0x40

#define CMD_ENABLE    (1 << 7)
#define CMD_APDCP     (1 << 6)
#define CMD_TIM_EXT   (1 << 5)
#define CMD_MODE(m)  ((m) << 2)
#define CMD_WIDTH(w) ((w) << 0)

#define CTRL_GAIN(g)        ((g) << 2)
#define CTRL_IRQ_PERSIST(p) ((p) << 0)
#define CTRL_IRQ_FLAG       (1 << 5)

/*
 * The Range (k) values are based on Rext = 100k
 */
#define RANGE_K1   973
#define RANGE_K2  3892
#define RANGE_K3 15568
#define RANGE_K4 62272

#define WIDTH_16_VAL (1 << 16)
#define WIDTH_12_VAL (1 << 12)
#define WIDTH_08_VAL (1 << 8)
#define WIDTH_04_VAL (1 << 4)

/******************************************************************************
 * External global variables
 *****************************************************************************/
extern volatile uint8_t I2CMasterBuffer[I2C_BUFSIZE];
extern volatile uint8_t I2CSlaveBuffer[I2C_BUFSIZE];


/******************************************************************************
 * Local variables
 *****************************************************************************/

static uint32_t range = RANGE_K1;
static uint32_t width = WIDTH_16_VAL;

/******************************************************************************
 * Local Functions
 *****************************************************************************/

static uint8_t readCommandReg(void)
{
    I2CMasterBuffer[0] = ADDR_CMD;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 1);

    I2CRead(LIGHT_I2C_ADDR, I2CSlaveBuffer, 1);

    return I2CSlaveBuffer[0];
}


static uint8_t readControlReg(void)
{
    I2CMasterBuffer[0] = ADDR_CTRL;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 1);

    I2CRead(LIGHT_I2C_ADDR, I2CSlaveBuffer, 1);

    return I2CSlaveBuffer[0];
}

/******************************************************************************
 * Public Functions
 *****************************************************************************/

/******************************************************************************
 *
 * Description:
 *    Initialize the ISL29003 Device
 *
 *****************************************************************************/
void light_init (void)
{
    /* nothing to initialize. light_enable enables the sensor */
}

/******************************************************************************
 *
 * Description:
 *    Enable the ISL29003 Device.
 *
 *****************************************************************************/
void light_enable (void)
{
    I2CMasterBuffer[0] = ADDR_CMD;
    I2CMasterBuffer[1] = CMD_ENABLE;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);

    range = RANGE_K1;
    width = WIDTH_16_VAL;
}

/******************************************************************************
 *
 * Description:
 *    Read sensor value
 *
 * Returns:
 *      Read light sensor value (in units of Lux)
 *
 *****************************************************************************/
uint32_t light_read(void)
{
    uint32_t data = 0;

    I2CMasterBuffer[0] = ADDR_LSB_SENSOR;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 1);

    I2CRead(LIGHT_I2C_ADDR, I2CSlaveBuffer, 1);
    data = I2CSlaveBuffer[0];

    I2CMasterBuffer[0] = ADDR_MSB_SENSOR;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 1);

    I2CRead(LIGHT_I2C_ADDR, I2CSlaveBuffer, 1);
    data = (I2CSlaveBuffer[0] << 8 | data);

    /* Rext = 100k */
    /* E = (range(k) * DATA)  / 2^n */

    return (range*data / width);
}

/******************************************************************************
 *
 * Description:
 *    Set ADC work mode
 *
 * Params:
 *    [in]  mode  - the work mode
 *
 *****************************************************************************/
void light_setMode(light_mode_t mode)
{
    uint8_t cmd = readCommandReg();

    /* clear mode */
    cmd &= ~(3 << 2);

    cmd |= CMD_MODE(mode);

    I2CMasterBuffer[0] = ADDR_CMD;
    I2CMasterBuffer[1] = cmd;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);
}

/******************************************************************************
 *
 * Description:
 *    Set the resolution
 *
 * Params:
 *    [in]  newWidth  - new n-bit resolution
 *
 *****************************************************************************/
void light_setWidth(light_width_t newWidth)
{
    uint8_t cmd = readCommandReg();

    /* clear width */
    cmd &= ~(3 << 0);

    cmd |= CMD_WIDTH(newWidth);

    I2CMasterBuffer[0] = ADDR_CMD;
    I2CMasterBuffer[1] = cmd;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);

    switch(newWidth) {
    case LIGHT_WIDTH_16BITS:
        width = WIDTH_16_VAL;
        break;
    case LIGHT_WIDTH_12BITS:
        width = WIDTH_12_VAL;
        break;
    case LIGHT_WIDTH_08BITS:
        width = WIDTH_08_VAL;
        break;
    case LIGHT_WIDTH_04BITS:
        width = WIDTH_04_VAL;
        break;
    }
}

/******************************************************************************
 *
 * Description:
 *    Set new gain/range
 *
 * Params:
 *    [in]  newRange  - new gain/range
 *
 *****************************************************************************/
void light_setRange(light_range_t newRange)
{
    uint8_t ctrl = readControlReg();

    /* clear range */
    ctrl &= ~(3 << 2);

    ctrl |= CTRL_GAIN(newRange);

    I2CMasterBuffer[0] = ADDR_CTRL;
    I2CMasterBuffer[1] = ctrl;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);

    switch(newRange) {
    case LIGHT_RANGE_1000:
        range = RANGE_K1;
        break;
    case LIGHT_RANGE_4000:
        range = RANGE_K2;
        break;
    case LIGHT_RANGE_16000:
        range = RANGE_K3;
        break;
    case LIGHT_RANGE_64000:
        range = RANGE_K4;
        break;
    }
}

/******************************************************************************
 *
 * Description:
 *    Set the interrupt threshold
 *
 * Params:
 *    [in]  luxTh  - the threshold in Lux
 *
 *****************************************************************************/
void light_setHiThreshold(uint32_t luxTh)
{
    uint32_t data = 0;

    data = luxTh * width / range;

    I2CMasterBuffer[0] = ADDR_IRQTH_HI;
    I2CMasterBuffer[1] = ((data >> 8) & 0xff);
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);
}

/******************************************************************************
 *
 * Description:
 *    Set the interrupt threshold
 *
 * Params:
 *    [in]  luxTh  - the threshold in Lux
 *
 *****************************************************************************/
void light_setLoThreshold(uint32_t luxTh)
{
    uint32_t data = 0;

    data = luxTh * width / range;

    I2CMasterBuffer[0] = ADDR_IRQTH_LO;
    I2CMasterBuffer[1] = ((data >> 8) & 0xff);
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);
}

/******************************************************************************
 *
 * Description:
 *    Set the number of integration cycles that are needed before an interrupt
 *    is triggered. The threshold level must have been reached during the set
 *    number of cycles before the interrupt is triggered.
 *
 * Params:
 *    [in]  cycles  - number of integration cycles
 *
 *****************************************************************************/
void light_setIrqInCycles(light_cycle_t cycles)
{
    uint8_t ctrl = readControlReg();

    /* clear irq */
    ctrl &= ~(CTRL_IRQ_FLAG);
    ctrl |= CTRL_IRQ_PERSIST(cycles);

    I2CMasterBuffer[0] = ADDR_CTRL;
    I2CMasterBuffer[1] = ctrl;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);
}

/******************************************************************************
 *
 * Description:
 *    Get interrupt flag status
 *
 * Returns:
 *    The status of the interrupt flag.
 *
 *****************************************************************************/
uint8_t light_getIrqStatus(void)
{
    uint8_t ctrl = readControlReg();

    return ((ctrl & CTRL_IRQ_FLAG) != 0);
}

/******************************************************************************
 *
 * Description:
 *    Clear the interrupt status flag
 *
 *****************************************************************************/
void light_clearIrqStatus(void)
{
    uint8_t ctrl = readControlReg();

    /* clear irq */
    ctrl &= ~(CTRL_IRQ_FLAG);

    I2CMasterBuffer[0] = (ADDR_CTRL | ADDR_CLAR_INT);
    I2CMasterBuffer[1] = ctrl;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);
}

/******************************************************************************
 *
 * Description:
 *    Shutdown the sensor (set in power-down mode).
 *    Enable again by calling light_enable().
 *
 *****************************************************************************/
void light_shutdown(void)
{
    uint8_t cmd = readCommandReg();

    /* first disable ADC code */
    cmd &= ~CMD_ENABLE;

    I2CMasterBuffer[0] = ADDR_CMD;
    I2CMasterBuffer[1] = cmd;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);

    /* second power-down */
    cmd |= CMD_APDCP;
    I2CMasterBuffer[0] = ADDR_CMD;
    I2CMasterBuffer[1] = cmd;
    I2CWrite(LIGHT_I2C_ADDR, I2CMasterBuffer, 2);
}
