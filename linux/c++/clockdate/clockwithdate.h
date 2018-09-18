#ifndef _CLOCKWITHDATE_H_
#define _CLOCKWITHDATE_H_

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>

class Clock{
public:
	void getClock();
	int clock_add_seconds(int i);
	int clock_cut_seconds(int i);
private:
	int hour;
	int minutes;
	int seconds;
};

class Date{
public:
	void getDate();
private:
	int month;
	int year;
	int day;
};

class ClockDate : public Clock, public Date{
public:
	void getClockDate();
	void add_seconds();
	void cut_seconds();
private:
	int sec;
};

#endif