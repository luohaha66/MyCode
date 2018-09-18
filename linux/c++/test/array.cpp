#include <iostream>
#include <cstdlib>

using namespace std;

class arr{
public:
	arr(int max);
	~arr();
	int& operator[](int i);
private:
	int* aa;
	int len;
};

arr::arr(int max)
{
	len = max;
	aa = new int[len];
}

arr::~arr()
{
	delete []aa;
}

int& arr::operator[](int i)
{
	if (i < len)
		return aa[i];
	exit(-1);
}

int main()
{
	arr b(10);
	for(int i = 0; i < 10; i++)
		b[i] = i;
	for(int i = 0; i < 10; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}