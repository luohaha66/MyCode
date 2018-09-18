#define TCFG0 *(volatile unsigned int*)0x139d0000
#define TCFG1 *(volatile unsigned int*)0x139d0004
#define TCON *(volatile unsigned int*)0x139d0008
#define TCNTB0 *(volatile unsigned int*)0x139d000c
#define TCMPB0 *(volatile unsigned int*)0x139d0010
#define GPD0CON *(volatile unsigned int*)0x114000a0

void gpio_init(void)
{
	GPD0CON &= (~0xf);
	GPD0CON |= 0x2;
}

void timer_init(void)
{
	gpio_init();
	TCFG0 &= (~0xff);
	TCFG0 |= 0xf9;
	TCFG1 &= (~0xf);
	TCFG1 |= 0x2;
	TCNTB0 = 5000;
	TCMPB0 = 2500;
	TCON &= (~0xf);
	TCON |= 1 << 3 | 1 << 1;
}


void beep_on(void)
{
	TCON &= (~(1 << 1));
	TCON |= 1 << 0;
}

void beep_off(void)
{
	TCON &= ~(1 << 0);
}

void main(void)
{
	timer_init();
	beep_on();
}