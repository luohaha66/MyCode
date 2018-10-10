#include <lpc11xx.h>
#include <stdio.h>

#define GPIO3DATA (*(volatile unsigned int*)0x50033ffc)
#define GPIO3DIR  (*(volatile unsigned int*)0x50038000)
	
#define GPIO0DATA (*(volatile unsigned int*)0x50003ffc)
#define GPIO0DIR (*(volatile unsigned int*)0x50008000)
	
#define GPIO1DATA (*(volatile unsigned int*)0x50013ffc)
#define GPIO1DIR (*(volatile unsigned int*)0x50018000)
	
void delays()
{
	int i,j;
	for (i = 0;i < 10; i++);
	for (j = 0;j < 33; j++);                                                                          
}

void delaya(unsigned int n)
{
	int i;
	for(i = 0; i< n; i++);
	delays();
}
int main()
{
	int i = 1000;
	int j = 1000;
	
	SystemInit();
	
	GPIO0DIR |= (1 << 2);
	GPIO1DIR |= (1 << 0);
	
	GPIO0DATA &= ~(1 << 2);
	GPIO1DATA &= ~(1 << 0);

	GPIO3DIR |= (1 << 0) | (1 << 1);
	
	while (1)
 {
	 i = 1000;
	 while (i--)
	 {
		GPIO3DATA &= ~(1 << 0); //set 0
		
		delaya(1000);
		
		GPIO3DATA &= ~(1 << 1);
		
	 }
		
	 j = 1000;
	 while (j--)
	 {
		GPIO3DATA |= (1 << 1);
		
		delaya(1000);
		
		GPIO3DATA |= (1 << 0); //set 1
	 }
 }
}
