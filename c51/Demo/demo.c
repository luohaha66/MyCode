
// c51 header
#include <AT89X52.h>

// with code, it will be put to flash
// without, it will be put to raw, raw is very small
unsigned char code LED[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char code LIGHT[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
                              0x40, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0x00};

// set I/O port, sbit = system bit
sbit U15A0 = P1 ^ 0; // the A0 pin of U15(74HC138) connect to P1_0 pin
sbit U15A1 = P1 ^ 1;
sbit U15A2 = P1 ^ 2;
sbit U15E3 = P1 ^ 3;

void main(void)
{
    //
    unsigned int a = 0;
    unsigned char c = 0;
    unsigned char d = 0;
    unsigned int f = 0;
    /* code */
    while (1)
    {
        P2 = 0;
        if (c == 16)
        {
            c = 0;
        }
        if (++f == 10000)
        {
            f = 0;
        }
        if (d == 0)
        {
            P1 = 0x0b;
            P2 = LED[f/1000];
        }
        else if (d == 2)
        {
            P1 = 0x0a;
            P2 = LED[(f % 1000) / 100];
        }
        else if (d == 3)
        {
            P1 = 0x09;
            P2 = LED[(f % 100) / 10];
        }
        else
        {
            P1 = 0x08;
            P2 = LED[f % 10];
        }
        if (++d == 4)
        {
            d = 0;
        }
        P0 = LIGHT[c++];
        for (a = 0; a < 1000; a++)
            ;
    }
}
