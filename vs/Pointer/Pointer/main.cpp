#include<cstdio>
#include"Pointer.hpp"
#include<iostream>
#include<stdexcept>
#include<typeinfo>
#define DIV_ERROR -1
using namespace std;

class DIV_Error : public logic_error
{
public:
	DIV_Error(const char* s) :logic_error(s)
	{
	}
};

double DIV(double a, double b)
{
	if ((-0.0000001 < b) && (b <0.00000001))
	{
		throw DIV_Error("DIV by zero");
	}
	return a / b;
}

void test()try
{
	DIV(5, 0);
}
catch (exception& e)
{
	cout << e.what() << endl;
}
class par
{
public:
	virtual ~par()
	{
	}
	
};
class chi : public par
{
public:
	int add(int a, int b)
	{
		return a + b;
	}
};

void test(par* p)
{
	if (typeid(*p)==typeid(chi))
	{
		chi* c = dynamic_cast<chi*>(p);
		if (c != NULL)
		{
			cout << c->add(1, 2) << endl;
		}
	}
}

class A
{
private:
	static int i;
public:
	A()
	{
		cout << "bbb" << endl;
	}
	A(const A&)
	{
		cout << "ccc" << endl;
	}
	~A()
	{
		cout << "aaaa" << endl;
	}
	A(int v)
	{
		cout << "ddd" << endl;
	}
};

A f(A& a)
{
	A aa = a;
	return aa;
}

A play(A a)
{
	return a;
}
int A::i = 0;



int main(int argc, char* argv[])
{ 
	return EXIT_SUCCESS;

}