//c51 header
#include <AT89X52.h> 

unsigned char recv_data = 0;
void uart_probe(void) interrupt 4
{
    // if RI, there is some data received
    if(RI == 1)
    {
        recv_data = SBUF;
        P0 = recv_data;
        RI = 0; // clear RI
        SBUF = recv_data + 1; // send the data
        while(!TI);
    }
    if(TI) TI = 0; // clear TI
}

void main(void)
{
    TMOD &= 0x0F; //empty high 4 bit
    TMOD |= 0x20; // set timer1 mode, auto reset 
    // init value, use time1
    TH1 = 0xFA;
    TL1 = 0xFA;
    // start timer
    TR1 = 1;
    // set uart mode and enable recv
    SCON = 0x50;
    // opne uart interuppt
    ES = 1;
    // open the global interrupt switchs
    EA = 1;
    while(1)
    {
    }
}