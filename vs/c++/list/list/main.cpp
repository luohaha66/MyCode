#include "list.hpp"

int main()
{
	list<int> a;
	int i = 0;
	for (i = 0; i < 10; i++)
		a.insert(i, i);
	a.display();
	a.del(5);
	a.display();
	return 0;
}