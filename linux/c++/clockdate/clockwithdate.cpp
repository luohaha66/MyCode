#include "clockwithdate.h"

using namespace std;

void Clock::getClock()
{
	time_t t;
	time(&t);
	struct tm* p = localtime(&t);
	hour    = p->tm_hour;
	minutes = p->tm_min;
	seconds = p->tm_sec;
	cout << " " << hour << ":" << minutes << ":" << seconds << endl;
}

int Clock::clock_add_seconds(int i)
{
	if(i > 0 && i < 60)
		seconds = seconds + i;
}

int Clock::clock_cut_seconds(int i)
{
	if(i > 0 && i < 60)
		seconds = seconds - i;
}

void Date::getDate()
{
	time_t t;
	time(&t);
	struct tm* p = localtime(&t);
	year  = p->tm_year + 1900;
	month = p->tm_mon + 1;
	day   = p->tm_mday;
	cout << year << ":" << month << ":" << day;
}

void ClockDate::getClockDate()
{
	getDate();
	getClock();
}

void ClockDate::add_seconds()
{
	cout << "input seconds" << endl;
	cin >> sec;
	clock_add_seconds(sec);
}

void ClockDate::cut_seconds()
{
	cout << "input seconds" << endl;
	cin >> sec;
	clock_cut_seconds(sec);
}