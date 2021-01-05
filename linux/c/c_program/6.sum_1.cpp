#include <iostream>

using namespace std;

class Sum
{
private:
    static int N;
    static int S;
    Sum();
public:
    static int Calculate(int n);
};

int Sum::N = 0;
int Sum::S = 0;

Sum::Sum()
{
    S = S + N;
    N = N - 1;
}

int Sum::Calculate(int n)
{
    int ret = 0;
    Sum* p = NULL;
        
    N = n;
    S = 0; 
    p = new Sum[N]; 
    ret = S;
        
    delete[]p;
    
    return ret;
}

int main()
{
    cout<<Sum::Calculate(10)<<endl;
    cout<<Sum::Calculate(100)<<endl;
    
	return 0;
}

