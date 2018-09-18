
#include <iostream>
#include <list>

using namespace std;

class IntStack
{
private:
    list<int> m_stack;
    list<int> m_cmax;
public:
    void push(int v);
    int pop();
    int top();
    int size();
    int max();
};

void IntStack::push(int v)
{
    m_stack.push_front(v);

    if( m_cmax.size() != 0 )
    {
        if( v > m_cmax.front() )
        {
            m_cmax.push_front(v);
        }
        else
        {
            m_cmax.push_front(m_cmax.front());
        }
    }
    else
    {
        m_cmax.push_front(v);
    }
}

int IntStack::pop()
{
    int ret = m_stack.front();

    m_stack.pop_front();
    m_cmax.pop_front();

    return ret;
}

int IntStack::top()
{
    return m_stack.front();
}

int IntStack::size()
{
    return m_stack.size();
}

int IntStack::max()
{
    return m_cmax.front();
}

int main()
{
    IntStack s;
    int array[] = {7, 2, 3, 1, 1, 4, 5};

    for(int i=0; i<sizeof(array)/sizeof(*array); i++)
    {
        s.push(array[i]);
    }

    while( s.size() )
    {
        cout<<s.top()<<endl;
        cout<<s.max()<<endl;

        s.pop();

        cout<<endl;
    }
}
