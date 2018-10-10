// c51 header
#include <AT89X52.h>

sbit RS = P2 ^ 5;
sbit RW = P2 ^ 4;
sbit E = P2 ^ 3;

void lcd1602_delay_ms(unsigned int ms)
{
    unsigned int k;
    unsigned int t = ms * 100;
    for (k = 0; k < t; k++)
        ;
}

void lcd1602_is_busy()
{
    RS = 0;
    RW = 1;
    P0 = 0xff;
    E = 1;
    while (P0_7 == 1)
        ;
    E = 0;
}

void lcd1602_write_data(unsigned char d)
{
    RS = 1;
    RW = 0;
    P0 = d;
    E = 1;
    E = 0;
}

void lcd1602_write_data_busy(unsigned char d)
{
    lcd1602_is_busy();
    RS = 1;
    RW = 0;
    P0 = d;
    E = 1;
    E = 0;
}

void lcd1602_write_directive(unsigned char command)
{
    RS = 0;
    RW = 0;
    P0 = command;
    E = 1;
    E = 0;
}

void lcd1602_write_directive_busy(unsigned char command)
{
    lcd1602_is_busy();
    RS = 0;
    RW = 0;
    P0 = command;
    E = 1;
    E = 0;
}

void lcd1602_init()
{
    lcd1602_delay_ms(15);
    lcd1602_write_directive(0x38);
    lcd1602_delay_ms(5);
    lcd1602_write_directive(0x38);
    lcd1602_delay_ms(5);
    lcd1602_write_directive(0x38);
    lcd1602_write_directive_busy(0x38);
    lcd1602_write_directive_busy(0x08);
    lcd1602_write_directive_busy(0x01);
    lcd1602_write_directive_busy(0x06);
    lcd1602_write_directive_busy(0x0c);
    lcd1602_write_directive_busy(0x80);
}

unsigned char code string[] = {0x49, 0x20, 0x6c, 0x6f, 0x76, 0x65, 0x20, 0x79, 0x6f, 0x75};
unsigned char code Font[] = {
    0X00,
    0X1F,
    0X20,
    0X20,
    0X20,
    0X20,
    0X20,
    0X10,
    0X10,
    0X20,
    0X20,
    0X20,
    0X20,
    0X20,
    0X1F,
    0X00,
    0X00,
    0X00,
    0X80,
    0X40,
    0X20,
    0X10,
    0X08,
    0X04,
    0X04,
    0X08,
    0X10,
    0X20,
    0X40,
    0X80,
    0X00,
    0X00,
};

// set I/O
sbit U15E3 = P1 ^ 3; // the E3 pin of U15(74HC138) connect to P1_3 pin
sbit U14E3 = P1 ^ 4;

void main(void)
{
    unsigned char i = 0;
    unsigned char m = 0;
    unsigned char n = 0;
    lcd1602_init();
    for (i = 0; i < 10; i++)
    {
        lcd1602_write_data_busy(string[i]);
    }
    while (1)
    {
        P1 = 0;
        P0 = 0;
        P2 = 0;
        P0 = Font[m];
        P2 = Font[m + 16];
        P1 |= m & 0x07; //save the low 3 bits, throw away the high 5 bits, 0 ~7, eight status
        if (m < 8)
        {
            U15E3 = 1;
            U14E3 = 0;
        }
        else
        {
            U14E3 = 1;
            U15E3 = 0;
        }
        if (++m == 16)
        {
            m = 0;
        }
        for (n = 0; n < 80; n++)
            ;
    }
}