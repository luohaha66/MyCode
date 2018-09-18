#ifndef _BUILD_H_
#define _BUILD_H_

#include <iostream>
#include <string.h>

class Build{
public:
	void set(int a, int b, int c, int d);
	void print();
private:
	int num;
	int level_num;
	int room_num;
	int area;
};

class Teach_Build : public Build{
public:
	Teach_Build(const char* n, int a, int b, int c, int d);
	void ShowTeach_Building();
private:
	char name[20];
};

class Dorm_Build : public Build{
public:
	Dorm_Build(const char* n, int a, int b, int c, int d, int e);
	void ShowDorm_Building();
private:
	char name[20];
	int stu_num;
};

#endif