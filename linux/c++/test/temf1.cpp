#include <iostream>

using namespace std;

template <class T>
class test{
public:
	test(T x) : val(x){}
  T operator+(test<T>& b);
private:
	T val;
};

template <class T>
T test<T>::operator+(test<T>& b)
{
	return val + b.val;
}

int main()
{
	test<int> a(5);
	test<int> b(65);
	cout << a + b << endl;
}