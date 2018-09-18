#include <iostream>

using namespace std;

class my_time{
public:
	void input_data(my_time& a);
	my_time operator+(my_time& b);
	void print();
private:
	char data[20];
	int h;
	int m;
	int s;
};

void my_time::input_data(my_time& a)
{
	cout << "please input time(format: xx:xx:xx):" << endl;
	cin >> data;
	a.h = ((int)(data[0] - '0')) * 10 + (int)(data[1] - '0');
	a.m = ((int)(data[3] - '0')) * 10 + (int)(data[4] - '0');
	a.s = ((int)(data[6] - '0')) * 10 + (int)(data[7] - '0');
	while (a.h < 0 || a.h >= 24 || a.m < 0 || a.m >= 60 || a.s < 0 || a.s >= 60)
	{
		cout << "wrong time, input again:" << endl;
		a.input_data(a);
	}
}

my_time my_time::operator+(my_time& b)
{
		my_time temp;
		int i = 0;
		int j = 0;
		temp.s = s + b.s;
		if(temp.s >= 60)
			{
				i++;
				temp.s = temp.s - 60;
			}
		temp.m = m + b.m + i;
		if(temp.m >= 60)
			{
				j++;
				temp.m = temp.m - 60;
			}
		temp.h = h + b.h + j;
		if(temp.h >= 24)
			temp.h = temp.h - 24;
		return temp;
}

void my_time::print()
{
	cout << "result is:" << endl;
	cout << h << ":" << m << ":" << s <<endl;
}

int main()
{
	my_time a;
	my_time b;
	a.input_data(a);
	b.input_data(b);
	my_time c = a + b;
	c.print();
	return 0;
}