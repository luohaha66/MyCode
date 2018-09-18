#include <iostream>

using namespace std;

template<typename T, int N, int M>
bool find_in_matrix(T matrix[N][M], T value) // O(N + M)
{
    if( (matrix[0][0] <= value) && (value <= matrix[N-1][M-1]) )
    {
        int r = 0;
        int c = M - 1;
        
        while( (r < N) && (c >= 0) )
        {
            if( value == matrix[r][c] )
            {
                return true;
            }
            else if( value < matrix[r][c] )
            {
                c--;
            }
            else
            {
                r++;
            }
                
        }
    }
    
    return false;
}

int main()
{
    int matrix[4][4] = 
    {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15},
    };
    
    cout<<find_in_matrix<int, 4, 4>(matrix, 7)<<endl;
    
    return 0;
}
