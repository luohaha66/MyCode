#include <iostream>

using namespace std;

class B;
class A{
public:
	A(int i)
	{
		x = i;
	}
	friend class B;
private:
	int x;
};

class B{
public:
	B(int i)
	{
		x = i;
	}
	void show(B &, A &);
private:
	int x;
};

void B::show(B &b, A &a)
	{
		cout << b.x <<" "<< a.x << endl;
	}

int main()
{
	A a(5);
	B b(15);
	b.show(b, a);
	return 0;
}