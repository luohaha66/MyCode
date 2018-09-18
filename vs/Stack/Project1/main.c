#include<stdio.h>
#include<malloc.h>
#include"Cstack.h"
#include"Behind.h"
#include"Count.h"

int main(int argc, char* argv[])
{
	int c;
	char a[20];
	printf("please input the expresssion which you want to count:\n");
	scanf_s("%s", a,20);
	transform(a);
	printf("\n");
	return 0;
}