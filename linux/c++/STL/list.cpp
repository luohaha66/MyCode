#include <iostream>
#include <list>

using namespace std;

int main()
{
	int i;
	list<int> l;
	list<int>::iterator ptr;
	for(i = 0; i < 10; i++)
		l.push_front(i);
	ptr = l.begin();
	for(i = 0; i < l.size(); i++)
	{
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;
	for(i = 0; i < 3; i++)
		l.pop_back();
	ptr = l.begin();
	for(i = 0; i < l.size(); i++)
	{
		cout << *ptr << " ";
		ptr++;
	}
	cout << endl;
	return 0; 
}