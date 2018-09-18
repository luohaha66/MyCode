#include "sala.h"

using namespace std;

int main()
{
	main_ager a("Luo Ha Ha", 1, 8000);
	technician b("Er Pang", 2);
	salesman c("Duan Gong Zi", 3);
	salesmanager d("Huang Pi Fu", 4);
	a.mprint();
	b.mprint();
	c.mprint();
	d.mprint();
}