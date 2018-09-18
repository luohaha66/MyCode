#include <iostream>
#include <memory>

using namespace std;

class test
{
public:
	explicit test(){cout << "aa" << endl;}
	virtual ~test(){cout << "bb" << endl;};
	void func(){cout << "cc" << endl;}
};

int main()
{
	//shared_ptr<test> p(new test);
	//test* p = new test;
	shared_ptr<test> p = make_shared<test>();
	p->func();
}