#include <iostream>

using namespace std;

class myerror
{
public:
	explicit myerror(const char* msg) : errmsg(msg){}
	virtual ~myerror() noexcept{}
	const char* what() const noexcept;
private:
	const char* errmsg;
}; 

const char* myerror::what() const noexcept
{
	return errmsg;
}

int ex_div(int x, int y) throw(myerror)
{
	if (y != 0)
		return x/y;
	throw myerror("Divisor is zero");	
}

int main()
{
	int x = 1, y = 0;
	try
	{
		ex_div(x, y);
	}
	catch(const myerror& iserr)
	{
		cout << iserr.what() << endl;
	}
	return 0;
}