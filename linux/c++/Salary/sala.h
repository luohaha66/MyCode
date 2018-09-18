#ifndef _SALA_H_
#define _SALA_H_

#include <iostream>
#include <string.h>

class employee{
public:
	void set(const char* n, int a, float b);
	void print();
private:
	int num;
	char name[20];
	float salary;
};

class main_ager : public employee{
public:
	main_ager(const char* n, int a, float b);
	void mprint();
};

class technician : public employee{
public:
	 technician(const char* n, int a);
	 void mprint();
private:
	float salary;
	int hours;
};

class salesman : public employee{
public:
	 salesman(const char* n, int a);
	 void mprint();
private:
	float salary;
	int sale;
};

class salesmanager : public employee{
public:
	 salesmanager(const char* n, int a);
	 void mprint();
private:
	float salary;
	int sale;
};

#endif