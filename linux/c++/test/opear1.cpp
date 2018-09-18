#include <iostream>

using namespace std;

class infg{
public:
	infg(int i){ val = i;}
	friend infg operator+(infg& a, infg& b);
	void print()
	{
		cout << val << endl;
	}
private:
	int val;
};

infg operator+(infg& a, infg& b)
{
	return infg(a.val + b. val);
}
int main()
{
	infg a(1);
	infg b(2);
	infg c = (a + b);
	c.print();
}