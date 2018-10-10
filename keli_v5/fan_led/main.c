#include <lpc11xx.h>
#include <gpio.h>

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
	GPIOInit();
	
	GPIOSetDir(PORT3, 0, 1);
	GPIOSetDir(PORT3, 1, 1);
	GPIOSetDir(PORT0, 2, 1);
	
	GPIOSetValue(PORT0, 2, 0);
	
	while (1)
 {
	 i = 1000;
	 while (i--)
	 {
		GPIOSetValue(PORT3, 0, 0); //set 0
		
		delaya(1000);
		
		GPIOSetValue(PORT3, 1, 0);
		
	 }
		
	 j = 1000;
	 while (j--)
	 {
		GPIOSetValue(PORT3, 0, 1);
		
		delaya(1000);
		
		GPIOSetValue(PORT3, 1, 1); //set 1
	 }
 }
}
