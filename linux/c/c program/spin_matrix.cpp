#include <iostream>
#include <malloc.h>

using namespace std;

template <int N>
class SpinMatrix
{
private:
    int m_matrix[N][N];
    
    struct Offset
    {
        int dx;
        int dy;
    };
    
    bool valid(int x, int y);
public:
    SpinMatrix();
    void run();
    void println();
    int scale();
};

template <int N>
SpinMatrix<N>::SpinMatrix()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            m_matrix[i][j] = 0;
        }
    }
}

template <int N>
bool SpinMatrix<N>::valid(int x, int y)
{
    bool ret = true;
    
    ret = ret && ((0 <= x) && (x < N));
    ret = ret && ((0 <= y) && (y < N));
    ret = ret && (m_matrix[x][y] == 0);
    
    return ret;
}

template <int N>
void SpinMatrix<N>::run()
{
    const Offset OFFSET[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int OSLEN = sizeof(OFFSET) / sizeof(*OFFSET);
    int cx = 0;
    int cy = 0;
    int cd = 0;
    int i = 1;
    
    do
    {
        m_matrix[cx][cy] = i;
        
        if( !valid(cx + OFFSET[cd].dx, cy + OFFSET[cd].dy) )
        {
            cd = (cd + 1) % OSLEN;
        }
        
        cx += OFFSET[cd].dx;
        cy += OFFSET[cd].dy;
        
        i++;
    } while ( i <= N*N );
}

template <int N>
void SpinMatrix<N>::println()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<m_matrix[i][j]<<'\t';
        }
        
        cout<<endl;
    }
    
    cout<<endl;
}

template <int N>
int SpinMatrix<N>::scale()
{
    return N;
}

int main()
{
	SpinMatrix<3> sm1;
	SpinMatrix<4> sm2;
	
	cout<<"3 * 3: "<<endl;
	
	sm1.run();
	sm1.println();
	
	cout<<"4 * 4: "<<endl;
	
	sm2.run();
	sm2.println();
}

