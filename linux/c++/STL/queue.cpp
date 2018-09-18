#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int i;
	queue<int> l;
	queue<int>::reference ptr = l.front();
	for(i = 0; i < 10; i++)
		l.push(i);
	for(i = 0; i < l.size(); i++)
	{
		cout << ptr << " ";
		ptr++;
	}
	cout << endl;
	for(i = 0; i < 3; i++)
		l.pop();
	ptr = l.front();
	for(i = 0; i < l.size(); i++)
	{
		cout << ptr << " ";
		ptr++;
	}
	cout << endl;
	return 0;
}