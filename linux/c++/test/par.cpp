#include <iostream>

using namespace std;

class A{
public:
	void print() { cout << "aaa" << endl; }
	void setval(int x) { val = x;}
private:
	int val;
};

class B : virtual public A{
public:
		void setval(int x) { val = x;}
private:
	int val;
};

class C : virtual public A{
public:
		void setval(int x) { val = x;}
private:
	int val;
};

class D : public B, public C{
public:
	void setval(int x){ val = x;}
private:
	int val;
};

int main()
{
	D aaa;
	aaa.print();
}