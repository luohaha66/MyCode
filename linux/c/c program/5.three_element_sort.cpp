#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

void init(int array[], int len)
{
    srand((unsigned int)(time(NULL)));
    
    for(int i=0; i<len; i++)
    {
        array[i] = rand() % 3;     
    }
}

void print_array(int array[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<array[i]<<" ";
    }
    
    cout<<endl;
}

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

void three_element_sort(int array[], int len)
{
    int* ts = new int[len];
    int p = 0;
    
    if( ts != NULL )
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<len; j++)
            {
                if( array[j] == i )
                {
                    ts[p++] = i;
                }
            }
        }
        
        for(int i=0; i<len; i++)
        {
            array[i] = ts[i];
        }
        
        delete[]ts;
    }
}

void three_element_sort_ex(int array[], int len)
{
    int p0 = 0;
    int p2 = len - 1;
    
    while( array[p0] == 0 ) p0++;
    while( array[p2] == 2 ) p2--;
    
    for(int i=p0; i<=p2;)
    {
        if( array[i] == 0 )
        {
            swap(array[i], array[p0++]);
            
            while( array[p0] == 0 ) p0++;
            
            if( i < p0 ) i = p0;
        }
        else if( array[i] == 2 )
        {
            swap(array[i], array[p2--]);
            
            while( array[p2] == 2 ) p2--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int array[15] = {2, 2, 2, 0, 2, 0, 0, 1, 1, 0, 0, 2, 1, 0, 0};
    
    init(array, 15);
    print_array(array, 15);
    //three_element_sort(array, 15);
    three_element_sort_ex(array, 15);
    print_array(array, 15);
    
	return 0;
}

