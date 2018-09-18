#include "sala.h"

using namespace std;

void employee::set(const char* n, int a, float b)
{
	strcpy(name, n);
	num = a;
	salary = b;
}

void employee::print()
{
	cout << "Employee Number:" << num << endl;
	cout << "Employee Name:" << name << endl;
	cout << "Employee salary:" << salary << endl;
	cout << endl;
}

main_ager::main_ager(const char* n, int a, float salary)
{
	set(n, a, salary);
}

void main_ager::mprint()
{
	print();
}

technician::technician(const char* n, int a)
{
	cout <<"<<<<<<<<<<<<<<<<<<< technician salary >>>>>>>>>>>>>>>>>>>" <<endl;
	cout << "Please input the hours of the technician work everyday:" << endl;
	cin >> hours;
	hours = hours * 20;
	salary = 100 * hours;
	set(n, a, salary);
	cout << endl;
}

void technician::mprint()
{
	print();
}
	
salesman::salesman(const char* n, int a)
{
	cout <<"<<<<<<<<<<<<<<<<<<< salesman salary >>>>>>>>>>>>>>>>>>>>" <<endl;
	cout << "Please input the sale of the current month:" << endl;
	cin >> sale;
	salary = sale * 0.04;
	set(n, a, salary);
	cout << endl;
}

void salesman::mprint()
{
	print();
}

salesmanager::salesmanager(const char* n, int a)
{
	cout <<"<<<<<<<<<<<<<<<<<< salesmanager salary >>>>>>>>>>>>>>>>>>" <<endl;
	cout << "Please input the sale of the current month with the deparment:" << endl;
	cin >> sale;
	salary = sale * 0.005 + 5000;
	set(n, a, salary);
	cout << endl;
}

void salesmanager::mprint()
{
	print();
}
