// c51 header
#include <AT89X52.h>

unsigned char rh_h = 0;
unsigned char rh_l = 0;
unsigned char t_h = 0;
unsigned char t_l = 0;
unsigned char check_sum = 0;


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

void lcd1602_write_address(unsigned char x, unsigned char y)
{ 
    x &= 0x0f;
    y &= 0x01; 
    if( y == 0)
    {
        lcd1602_write_directive_busy(x | 0x80);
    }
    else
    {
        lcd1602_write_directive_busy((x + 0x40) | 0x80); 
    }
} 

void lcd1602_display(unsigned char x, unsigned char y, unsigned char d)
{
    lcd1602_write_address(x, y);
    lcd1602_write_data_busy(d);
}

unsigned char DHT_transmit_data(void)
{
    unsigned char d = 0;
    unsigned char i = 0;
    for(i = 0; i < 8; i++)
    {
        // start to transmit 1-bit data, delay 50us
        // while(P3_6 == 1);
        TH0 = 0xFF;
        TL0 = 0xA3;
        TF0 = 0;
        TR0 = 1;
        while(TF0 == 0); // delay 50us
        TR0 = 0;
        // dealy 30 us
        // while(P3_6 == 0);
        TH0 = 0xFF;
        TL0 = 0xC8;
        TF0 = 0;
        TR0 = 1;
        while(TF0 == 0);
        TR0 = 0;
        // judge the bit is 0 or 1
        if(P3_6 == 1)
        {
            d |= 0x01;
            // dealy 40 us
            TH0 = 0xFF;
            TL0 = 0xB6;
            TF0 = 0;
            TR0 = 1;
            while(TF0 == 0);
            TR0 = 0;
        }
        d <<= 1;
    }
    return d;
}

unsigned char MCU_get_data_from_DHT(void)
{
    // data single-bus from high to low
    P3_6 = 1;
    P3_6 = 0;
    //keep it for 20ms, use the timer0
    // init timer0 value
    TH0 = 0x6F;
    TL0 = 0xFF;
    TF0 = 0;
    // start timer0
    TR0 = 1;
    while(TF0 == 0); // delay 20ms
    TR0 = 0; //stop timer0

    // MCU pull up voltage, wait 40us
    P3_6 = 1;
    TH0 = 0xFF;
    TL0 = 0xB6;
    TF0 = 0;
    TR0 = 1;
    while(TF0 == 0); // delay 40us
    TR0 = 0;

    // DHT send out response, keep it for 80us
    TH0 = 0xFF;
    TL0 = 0x6A;
    TF0 = 0;
    TR0 = 1;
    while(TF0 == 0); // delay 80us
    TR0 = 0;

    // DHT pull up voltage, keep it for 80us
    // while(P3_6 == 0);
    TH0 = 0xFF;
    TL0 = 0x6A;
    TF0 = 0;
    TR0 = 1;
    while(TF0 == 0); // delay 80us
    TR0 = 0;

    rh_h = DHT_transmit_data();
    rh_l = DHT_transmit_data();
    t_h = DHT_transmit_data();
    t_l = DHT_transmit_data();
    check_sum = DHT_transmit_data();
    // delay 50us
    TH0 = 0xFF;
    TL0 = 0xA3;
    TF0 = 0;
    TR0 = 1;
    while(TF0 == 0); // delay 50us
    TR0 = 0;
    if(check_sum == rh_h + rh_l + t_h + t_l)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main(void)
{
    int i = 0;
    // set timer0 mode, used for time delay
    TMOD = 0x01;
    // stop timer0
    TR0 = 0;
    // forbid interrupt of timer0
    ET0 = 0;
    // init 1602
    lcd1602_init();
    while(1)
    {
        if(MCU_get_data_from_DHT())
        {
            if(rh_h > 99) rh_h = 0;
            if(t_h > 99) t_h = 0;
            lcd1602_display(0, 0, 'R');
            lcd1602_display(1, 0, 'H');
            lcd1602_display(2, 0, ':');
            lcd1602_display(3, 0, rh_h / 10 + '0');
            lcd1602_display(4, 0, rh_h % 10 + '0');
            lcd1602_display(5, 0, '%');

            lcd1602_display(0, 1, 'T');
            lcd1602_display(1, 1, ':');
            lcd1602_display(2, 1, t_h / 10 + '0');
            lcd1602_display(3, 1, t_h % 10 + '0');
            lcd1602_display(4, 1, 0xDF);
            lcd1602_display(5, 1, 'C');
            for(i = 0; i < 50000; i++);
        }
    }
}