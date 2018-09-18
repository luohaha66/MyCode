#include <iostream>

using namespace std;

template <class T>
class test{
public:
	test(T x) : val(x){}
	template <class F, class N>
	friend F operator+(test<F>& a, test<N>& b);
private:
	T val;
};

template <class F, class N>
F operator+(test<F>& a, test<N>& b)
{
	return a.val + b.val;
}

int main()
{
	test<int> a(5);
	test<char> b(65);
	cout << a + b << endl;
}