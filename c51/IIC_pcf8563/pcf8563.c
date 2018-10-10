// c51 header
#include <AT89X52.h>
#include <Intrins.h>

// the pin SCL of pcf8563 is connect to pin CN4_5
sbit SCL = P1^1;
sbit SDA = P1^0;

void iic_start(void)
{
    SDA = 1;
    SCL = 1;
    _nop_();
    _nop_();
    SDA = 0;
    _nop_();
    _nop_();
    SCL = 0;
}

void iic_stop(void)
{
    SDA = 0;
    SCL = 1;
    _nop_();
    _nop_();
    SDA = 1;
    // _nop_();
    // _nop_();
    // SCL = 0;
}

void pcf8563_write_byte(unsigned char w_data)
{
    unsigned char i = 0;
    for(i = 0; i < 8; i++)
    {
        if(w_data & 0x80)
        {
            SDA = 1;
        }
        else
        {
            SDA = 0;
        }
        _nop_();
        _nop_();
        SCL = 1;
        _nop_();
        w_data = w_data << 1;
        SCL = 0;
        _nop_();
    }
    SDA = 1;
    _nop_();
    SCL = 1;
    _nop_();
    _nop_();
    SCL = 0;
}

unsigned char pcf8563_read_byte(void)
{
    unsigned char r_data = 0;
    unsigned char i = 0;
    for(i = 0; i < 8; i++)
    {
        r_data = r_data << 1;
        SDA = 1;
        SCL = 1;
        _nop_();
        _nop_();
        if(SDA == 1)
        {
            r_data = r_data | 0x01;
        }
        else
        {
            r_data = r_data & 0xfe;
        }
        SCL = 0;
        _nop_();
        _nop_();
    }
    return r_data;
}

/*channel: 0~3*/
unsigned char pcf8563_read_char(unsigned char address)
{
    unsigned char r_data = 0;
    iic_start();
    /*the high 4 bit is specified in chip manual + A2 + A1 + A0 + W/R(0/1)*/
    /*send write signal*/
    pcf8563_write_byte(0xA2);
    /*write the register address*/
    pcf8563_write_byte(address);
    /*restart*/
    iic_start();
    /*send read signal*/
    pcf8563_write_byte(0xA3);
    /*read data register*/
    r_data = pcf8563_read_byte();
    iic_stop();
    return r_data;
}

void pcf8563_write_char(unsigned char address,unsigned char w_data)
{
    iic_start();
    /*the high 4 bit is specified in chip manual + A2 + A1 + A0 + W/R(0/1)*/
    /*send write signal*/
    pcf8563_write_byte(0xA2);
    /*send the write address*/
    pcf8563_write_byte(address);
    /*write data to data register*/
    pcf8563_write_byte(w_data);
    iic_stop();
}

void delay(void)
{
    int i = 0;
    for(i = 0; i < 20000; i++);
}


void main(void)
{
    unsigned char r_data = 0;
    //ensure it is starting
    pcf8563_write_char(0x00, 0x00);
    while(1)
    {
        r_data = pcf8563_read_char(0x02);
        P0 = r_data;
        delay();
    }
}