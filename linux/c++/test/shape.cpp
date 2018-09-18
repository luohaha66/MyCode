#include <iostream>

using namespace std;

class shape{
public:
	virtual void area() = 0;
};

class rectangle : public shape{
public:
	void area();
private:
	float x;
	float y;
};

class circle : public shape{
public:
	void area();
private:
	float r;
};

void rectangle::area()
{
	cin >> x;
	cin >> y;
	cout << "rectangle area is:" << x * y << endl;
}

void circle::area()
{
	cin >> r;
	cout << "circle area is:" << r * r * 3.1415 << endl;
}

int main()
{
	rectangle a;
	a.area();
	circle b;
	b.area();
	return 0;
}