#include <iostream>

using namespace std;


class shape{
public:
	virtual void area(){};
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

void getarea(shape& obj)
{t
	obj.area();
}
int main()
{
	rectangle a;
	getarea(a);
	circle b;
	getarea(b);
	return 0;
}