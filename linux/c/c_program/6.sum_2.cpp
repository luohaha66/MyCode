#include <iostream>

using namespace std;

typedef int(Func)(int);

int end_func(int n);
int recusive_func(int n);

Func* Array[] = 
{
    end_func,     // 0
    recusive_func // 1
};

int end_func(int n)
{
    return n;
}

int recusive_func(int n)
{
    return n + Array[!!(n-1)](n-1);
}

int sum(int n)
{
    return recusive_func(n);
}

int main()
{
    cout<<sum(10)<<endl;
    cout<<sum(100)<<endl;
    
	return 0;
}

