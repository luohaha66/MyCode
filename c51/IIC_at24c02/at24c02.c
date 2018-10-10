// c51 header
#include <AT89X52.h>
#include <Intrins.h>

// the pin SCL of AT24C02 is connect to pin CN4_5
sbit SCL = P1^5;
sbit SDA = P1^4;

void iic_start(void)
{
    /*the SCL kepp high, the SDA from 1 to 0*/
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
    /*the SCL kepp high, the SDA from 0 to 1*/
    SDA = 0;
    SCL = 1;
    _nop_();
    _nop_();
    SDA = 1;
    // _nop_();
    // _nop_();
    // SCL = 0;
}

void at24c02_write_byte(unsigned char w_data)
{
    unsigned char i = 0;
    for(i = 0; i < 8; i++)
    {
        /*write step: D7D6~D0*/
        /*get the highest of data, then write it*/
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
    /*write the reply sign*/
    SDA = 1;
    _nop_();
    SCL = 1;
    _nop_();
    _nop_();
    SCL = 0;
}

unsigned char at24c02_read_byte(void)
{
    unsigned char r_data = 0;
    unsigned char i = 0;
    for(i = 0; i < 8; i++)
    {
        /*only when the SCL is high, the SDA is stable*/
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

void at24c02_write_char(unsigned char address, unsigned char w_data)
{
    iic_start();
    /*the high 4 bit is specified in chip manual + A2 + A1 + A0 + W/R(0/1)*/
    /*send write signal*/
    at24c02_write_byte(0xa0);
     /*send the address you want to write, 0~FF*/
    at24c02_write_byte(address);
    /*write data*/
    at24c02_write_byte(w_data);
    iic_stop();
}

unsigned char at24c02_read_char(unsigned char address)
{
    unsigned char r_data = 0;
    iic_start();
    /*the high 4 bit is specified in chip manual + A2 + A1 + A0 + W/R(0/1)*/
    /*send write signal*/
    at24c02_write_byte(0xa0);
    /*send the address you want to read, 0~FF*/
    at24c02_write_byte(address);
    /*restart IIC*/
    iic_start();
    /*send read signal*/
    at24c02_write_byte(0xa1);
    /*read data*/
    r_data = at24c02_read_byte();
    iic_stop();
    return r_data;
}

void main(void)
{
    unsigned char r_data = 0;
    r_data = at24c02_read_char(0x03);
    P0 = r_data;
    r_data += 1;
    at24c02_write_char(0x03, r_data);
    while(1)
    {
    }
}