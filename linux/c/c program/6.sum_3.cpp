#include <iostream>

using namespace std;

template<int N>
class Sum
{
public:
    static const int Value = N + Sum<N-1>::Value;
};

template<>
class Sum<0>
{
public:
    static const int Value = 0;
};

int main()
{
    cout<<Sum<10>::Value<<endl;
    cout<<Sum<100>::Value<<endl;
    
	return 0;
}

