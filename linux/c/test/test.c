#include <stdio.h>


int main()
{
	int i = 0, j = 0;
	int a[2][3] = {{2, 5, 8}, {1, 3, 9}};
	int (*p)[3] = &a[0];
	int (*f)[3] = a;
	printf("%p, %p\n", p, p++);
	p = &a[0];
	printf("%p, %p\n", *p, *p++);
	p = &a[0];
	printf("%d, %d\n", **p, *(*p + 1));
	p = &a[0];
	printf("%d, %d\n", **(++p), *((*p + 1)));
	
	printf("%p, %p\n", f, f++);
	f = a;
	printf("%p, %p\n", *f, *f++);
	f = a;
	printf("%d, %d\n", **f, *(*f + 1));
	f = a;
	printf("%d, %d\n", **(++f), *((*f + 1)));
}
