#include <iostream>
#include <cmath>

using namespace std;

class dista{
public:
	dista(){
		cout << "Please input the first number location:" << endl;
		cin >> x;
		cin >> y;
		cout << "Please input the second number location:" << endl;
		cin >> x1;
		cin >> y1;
	}
	float dist()
	{
		float a = (x - x1) * (x - x1);
		float b = (y - y1) * (y - y1);
		dis = sqrt(a + b);
		cout << "distance is: " << dis <<endl;
	}
private:
	float x;
	float y;
	float x1;
	float y1;
	float dis;
};


int main()
{
	dista d;
	d.dist();
}