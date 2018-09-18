#include <iostream>

using namespace std;

template <class T, int max>
class array{
public:
	array();
	void inputdata(int i, T data);
	void printdata(int i);
	~array();
private:
	T *p; 
};

template <class T, int max>
array<T, max>::array()
{
	p = new T[max];
}

template <class T, int max>
array<T, max>::~array()
{
	delete []p;
	p = NULL;
}

template <class T, int max>
void array<T, max>::inputdata(int i, T data)
{
	p[i] = data;
}

template <class T, int max>
void array<T, max>::printdata(int i)
{
	cout << p[i] << " ";
}

int main()
{
	array<int, 20> a;
	for(int i = 0; i < 10; i++)
		a.inputdata(i, i);
	for(int i = 0; i < 10; i++)
		a.printdata(i);
	cout << endl;
	char c = 'a';
	array<char, 20> b;
	for(int i = 0; i < 10; i++)
		b.inputdata(i, c++);
	for(int i = 0; i < 10; i++)
		b.printdata(i);
	cout << endl;
}