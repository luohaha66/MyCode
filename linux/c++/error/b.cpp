#include <iostream>

using namespace std;

class abc
{
public:
	explicit abc(char c) : ch(c){}
	explicit abc(int i) : val(i){}
	operator int() const
	{
		return val;
	}
	operator char() const
	{
		return ch;
	}
private:
	int val;
	char ch;
};

int main()
{
	abc a(5);
	abc b('c');
	//abc a = 5;//取消隐式类型转换(explicit)
	//abc b = 'c';
	int i = a;
	char c = b; 
	cout << i << c << endl;
	return 0;
}