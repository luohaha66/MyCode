#include <iostream>

using namespace std;

class F{
public:
	float operator()(float i, float j);
};

float F::operator()(float i, float j)
{
	return (i + 5) * j;
}

int main()
{
	F f;
	cout << f(1.5, 2.2) <<endl;
	return 0;
}