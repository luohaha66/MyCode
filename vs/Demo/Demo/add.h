#pragma once
#ifndef  _add_h_
#define  _add_h_

class MyClass
{
public:
	MyClass();
	~MyClass();
	int sett(int i);
	static int set(int i);
	bool setoperater(char op);
	void setunmber(double p1, double p2);
	bool result(double& p);
private:
	int i;
	static int c;
	char mop;
	double mp1;
	double mp2;
};

#endif // !"add.h"
