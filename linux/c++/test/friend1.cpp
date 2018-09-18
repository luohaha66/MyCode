#include <iostream>

using namespace std;

class B;
class A{
public:
	A(int i)
	{
		x = i;
	}
	friend void show(B &);
private:
	static int x;
};

int A::x = 10;

class B{
public:
	B(int i)
	{
		x = i;
	}
private:
	int x;
	friend void show(B &);
};

void show(B &b)
	{
		cout << b.x <<" "<< A::x << endl;
	}

int main()
{
	A a(5);
	B b(15);
	show(b);
	return 0;
}