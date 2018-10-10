// c51 header
#include <AT89X52.h>

unsigned char code LED[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char k = 0;

void INI0(void) interrupt 0
{
    k++;
    P2 = LED[k % 10];
}
 
void main(void)
{
    IT0  = 1;
    EA = 1;
    EX0 = 1;
    while(1)
    {

    }
}