#include <iostream>

using namespace std;

class infg{
public:
	infg(int i){ val = i;}
	int operator+(infg& b);
	ostream& operator<<(ostream& p);
	void print()
	{
		cout << val << endl;
	}
private:
	int val;
};

int infg::operator+(infg& b)
{
	val = val + b.val;
	return val;
}

ostream& infg::operator<<(ostream& p)
{
			p << val << endl;
}

int main()
{
	infg a(1);
	infg b(2);
	a.operator+(b);
	a.operator<<(cout);
}