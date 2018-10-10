// c51 header
#include <AT89X52.h>

void to(void) interrupt 1
{
    TH0 = 0xff;
    TL0 = 0x18;
    P0 = 0x0f;
}

void main(void)
{
    // set timer mode 
    TMOD = 0x01;
    // init value
    TH0 = 0xff;
    TL0 = 0x18;
    // start timer
    TR0 = 1;
    // open interrupt of timer 0
    ET0 = 1;
    // open the global interrupt switchs
    EA = 1;
    while(1)
    {

    }
}