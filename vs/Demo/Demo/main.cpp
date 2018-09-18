#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
class vb
{
public:
	virtual int area() = 0;
};

class aa
{
protected:
	int i;
public:
	aa()
	{
		print();
	}
	aa(int j)
	{
		this->i = j;
		cout << "aa()" << i << endl;
	}
	aa(char *s)
	{
		cout << "aa()" << s << endl;
	}
	virtual void print()
	{
		cout << "this is aa   " << i<<endl;
	}
};

class bb : public aa
{
protected:
	int i;
public:
	bb()
	{
		print();
	}
	bb(int j) : aa(j)
	{
		this->i = j;
		cout << "bb()" << i << endl;
	}
	bb(char *s) : aa("this is aa")
	{
		cout << "bb()" << s << endl;
	}
	virtual void print()
	{
		cout << "this is bb   " << i<<endl;
	}
};

class cc : public bb
{
protected:
	int i;
	aa c;
	aa b;
public:
	cc()
	{
		print();
	}
	cc(int j) : bb(j),c("this is c"), b("this is b")
	{
		this->i = j;
		cout << "cc()" << i << endl;
	}
	cc(char *s) : bb("this is bb"),c("this is c"),b("this is b")
	{
		cout << "cc()" << s << endl;
	}
	virtual void print()
	{
		cout << "this is cc   " << endl;
	}
};

template<typename T>
void swwap(T&a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template<typename T>
void print(T& a, T& b)
{
	cout << a << " " << b << endl;
}

template<typename T>
void slectrank(T *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		int index = i;
		T min = a[i];
			for (int j = i + 1; j < len; j++)
			{
				if (a[j] < min)
				{
					min = a[j];
					index = j;
				}
			}
		swap(a[i], a[index]);
	}
}

template<typename T>
void printaa(T *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] <<" " ;
	}
	cout << endl;
}

int Max(int a, int b)
{
	cout << "max1" << endl;
	return (a > b ? a:b);
}

template<typename T>
T Max(T a, T b)
{
	cout << "max2" << endl;
	return (a > b ? a : b);
}

template<typename T>
T Max(T a, T b, T c)
{
	cout << "max3" << endl;
	return static_cast<T>(Max(Max(a, b), c));
}

template<typename T>
class abc
{
public:
	T add(T a, T b);
	T min(T a, T b);
private:
	T i;
};

template<typename T>
T abc<T>::add(T a, T b)
{
	return a + b;
}

template<typename T>
T abc<T>::min(T a, T b)
{
	return a - b;
}

template<typename T1,typename T2>
class test
{
public:
	T1 add(T1 a, T2 b)
	{
		cout << "second" << endl;
		return a + b;
	}
};

template<typename T>
class test<T, T>
{
public:
	T add(T a, T b)
	{
		cout << "first" << endl;
		return static_cast<T>(a + b);
	}
};

template<typename T>
class test<T, int>
{
public:
	T add(T a, int b)
	{
		cout << "third" << endl;
		return static_cast<T>(a + b);
	}
};

template<typename T,int N>
class arraay
{
public:
	void func()
	{
		T arr[N] = { 0 };
		for (int i = 0; i < N; i++)
		{
			T j = static_cast<T>(i);
			arr[i] = j + 1;
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

template<int N>
class couunt
{
public:
	static const int a = couunt<N - 1>::a + N;
};

template<>
class couunt<1>
{
public:
	static const int a = 1;
};


int main(int argc, char* argv[])
{
	return EXIT_SUCCESS;
}