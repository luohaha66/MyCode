#include <iostream>

using namespace std;

class my_time{
public:
	void input_data();
	my_time operator+(my_time& b);
	void print();
private:
	int h;
	int m;
	int s;
};

void my_time::input_data()
{
	cout << "please input hour:" << endl;
	cin >> h;
	while(h < 0 || h > 24)
	{
		cout << "wrong hour, please input again:" << endl;
		cin >> h;
	}
	
	cout << "please input minutes:" << endl;
	cin >> m;
	while(m < 0 || m > 60)
	{
		cout << "wrong minutes, please input again:" << endl;
		cin >> m;
	}
	
	cout << "please input seconds:" << endl;
	cin >> s;
	while(s < 0 || s > 60)
	{
		cout << "wrong seconds, please input again:" << endl;
		cin >> s;
	}	
}

my_time my_time::operator+(my_time& b)
{
		my_time temp;
		int i = 0;
		int j = 0;
		temp.s = s + b.s;
		if(temp.s > 60)
			{
				i++;
				temp.s = temp.s - 60;
			}
		temp.m = m + b.m + i;
		if(temp.m > 60)
			{
				j++;
				temp.m = temp.m - 60;
			}
		temp.h = h + b.h + j;
		if(temp.h > 24)
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
	a.input_data();
	b.input_data();
	my_time c = a + b;
	c.print();
	return 0;
}