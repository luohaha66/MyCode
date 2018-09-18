#include "clockwithdate.h"

using namespace std;

int main()
{
	ClockDate cd;
	while(1)
	{
		cd.getClockDate();
		sleep(1);
		system("clear");
	}
}