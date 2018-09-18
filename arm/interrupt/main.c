/**********************led**************************/
#define GPX2CON *(volatile unsigned int*)0x11000C40
#define GPX2DAT *(volatile unsigned int*)0x11000C44

/**********************key**************************/
#define EXT_INT41CON *(volatile unsigned int*)0x11000E04
#define EXT_INT41_MASK *(volatile unsigned int*)0x11000F04
#define EXT_INT41_PEND *(volatile unsigned int*)0x11000F44
#define GPX1CON *(volatile unsigned int*)0x11000C20

/**********************gic**************************/
#define ICCICR_CPU0 *(volatile unsigned int*)0x10480000
#define ICCPMR_CPU0 *(volatile unsigned int*)0x10480004
#define ICCIAR_CPU0 *(volatile unsigned int*)0x1048000C
#define ICCEOIR_CPU0 *(volatile unsigned int*)0x10480010
#define ICDDCR      *(volatile unsigned int*)0x10490000
#define ICDISER_CPU *(volatile unsigned int*)0x10490104
#define ICDICPR_CPU *(volatile unsigned int*)0x10490284
#define ICDIPTR_CPU *(volatile unsigned int*)0x10490838

/**********************uart**************************/
#define GPA1CON     *(volatile unsigned int*)0x11400020

#define ULCONn      *(volatile unsigned int*)0x13820000
#define UCONn       *(volatile unsigned int*)0x13820004
#define UTRSTATn    *(volatile unsigned int*)0x13820010
#define UTXHn       *(volatile unsigned int*)0x13820020
#define URXHn       *(volatile unsigned int*)0x13820024
#define UBRDIVn     *(volatile unsigned int*)0x13820028
#define UFRACVALn   *(volatile unsigned int*)0x1382002c


static int flag = 1;

void delay()
{
    int i=0xffffff;
    while(i--)
    {
        ;
    }
}

void led_on(void)
{
    GPX2DAT = GPX2DAT | 0x1<<7;
}

void led_off(void)
{
    GPX2DAT = GPX2DAT & ~(0x1<<7);
}

void sendch(char ch)
{
    while(!(UTRSTATn & (0x1<<2)));
    UTXHn = ch;
}

void irq_handler(void)
{
    int irqnum = ICCIAR_CPU0&0x3FF;
    if (flag % 2 != 0)
    	{
    		led_off();
    		flag++;
    	}
    else 
    	{
    		led_on();
    		flag++;
    	}	
    EXT_INT41_PEND = EXT_INT41_PEND | 0x1<<1;
    ICDICPR_CPU = ICDICPR_CPU | 0x1<<25;
    ICCEOIR_CPU0 = irqnum;
}

void key_init(void)
{
    GPX1CON = GPX1CON | (0xf<<4);
    EXT_INT41CON = EXT_INT41CON & ~(0x7<<4) | (0x2<<4);
    EXT_INT41_MASK = EXT_INT41_MASK & ~(0x1<<1);
}

void gic_init(void)
{
    ICDDCR = 0x1;                           //通道开启  分发器到cpu interface
    ICDISER_CPU = ICDISER_CPU| (0x1<<25);     //使能57号中断
    ICDIPTR_CPU = ICDIPTR_CPU & ~(0xff<<8) | (0x1<<8);   //57向cpu0发送
    ICCICR_CPU0 = 0x1;
    ICCPMR_CPU0 = 0xff;
}

void uart_init(void)
{
    GPA1CON = GPA1CON & ~0xff | 0x22;
    ULCONn = 0x3;
    UCONn = UCONn & ~0xf | 0x1<<2 | 0x1;
    UBRDIVn = 53;
    UFRACVALn = 4;
}

void main(void)
{
		GPX2CON = GPX2CON & ~(0xf<<28) | (0x1<<28);
    uart_init();
    gic_init();
    key_init();
    while(1)
    {
        ;
    }
}