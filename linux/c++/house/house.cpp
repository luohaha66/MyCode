#include "house.h"

using namespace std;

void Build::set(int a, int b, int c, int d)
{
	num = a;
	level_num = b;
	room_num = c;
	area = d;
}

void Build::print()
{
	cout << "Building number: " << num << "   " << "Building Level Number: " << level_num << endl;
	cout << "Room Number: " << room_num << "   " << "Area: " << area << endl;
}

Teach_Build::Teach_Build(const char* n, int a, int b, int c, int d)
{
	set(a, b, c, d);
	strcpy(name, n);
}

void Teach_Build::ShowTeach_Building()
{
	cout << "Building name: " << name << endl;
	print();
}

Dorm_Build::Dorm_Build(const char* n, int a, int b, int c, int d, int e)
{
	set(a, b, c, d);
	strcpy(name, n);
	stu_num = e;
}

void Dorm_Build::ShowDorm_Building()
{
	cout << "Building name: " << name << endl;
	print();
	cout << "How many students can live in:  " << stu_num <<endl;
}