#include<cstdio>
#include "add.h"

using namespace std;
int MyClass::c = 9;

int MyClass::sett(int i)
{
	this->i = i;
	printf("%d\n", this->i);
	return this->i;
}

int MyClass::set(int i)
{
	c = i;
	printf("%d\n", c);
	return c;
}

bool MyClass::setoperater(char op)
	{
		bool ret = false;
		if ((op == '+') || (op == '-') || (op == '*') || (op == '/'))
		{
			ret = true;
			mop = op;
		}
		return ret;
	}

void MyClass::setunmber(double p1, double p2)
	{
		mp1 = p1;
		mp2 = p2;
	}

bool MyClass::result(double& p)
	{
		bool ret = true;
		switch (mop)
		{
		case '/':
			if ((-0.00000001<mp2) && (mp2>0.000000001))
			{
				p = mp1 / mp2;
			}
			break;
		case '+':
			p = mp1 + mp2;
			break;
		case '*':
			p = mp1*mp2;
		case '-':
			p = mp1 - mp2;
			break;
		default:
			ret = false;
			break;
		}
		printf("%f\n", p);
		return ret;
	}

MyClass::MyClass()
{
}

MyClass::~MyClass()
{

}