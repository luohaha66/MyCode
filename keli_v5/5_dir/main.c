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
	
	GPIOSetDir(PORT1, 4, 0);
	
	GPIOSetDir(PORT0, 2, 1);
	
	GPIOSetDir(PORT3, 0, 1);
	GPIOSetDir(PORT3, 1, 1);
	
	GPIOSetDir(PORT1, 8, 0);
	GPIOSetDir(PORT1, 9, 0);
	GPIOSetDir(PORT1, 10, 0);
	GPIOSetDir(PORT1, 11, 0);
	GPIOSetDir(PORT0, 3, 0);
	
	while(1)
	{
	 if (GPIOGetValue(PORT1, 8) == 0)
	 {
		GPIOSetValue(PORT3, 0, 0);
	 }
	
	 if (GPIOGetValue(PORT1, 9) == 0)
	 {
		GPIOSetValue(PORT3, 0, 1);
	 }
	
	 if (GPIOGetValue(PORT1, 10) == 0)
	 {
		GPIOSetValue(PORT3, 1, 0);
	 }
	
	 if (GPIOGetValue(PORT1, 11) == 0)
	 { 
		GPIOSetValue(PORT3, 1, 1);
	 }
	 
	 if (GPIOGetValue(PORT0, 3) == 0)
	 {
		GPIOSetValue(PORT0, 2, 0);
	 }
	 
	 if (GPIOGetValue(PORT1, 4) == 0)
	 {
		GPIOSetValue(PORT0, 2, 1);
	 }
	}
}

