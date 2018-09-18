#include<stdio.h>
#include<malloc.h>
int** malloca(int row,int col)
{
 int** p=(int**)malloc(sizeof(int*)*row);
 int* q=(int*)malloc(sizeof(int)*row*col);
int i=0;
if(p&&q)
{
for(i;i<row;i++)
 p[i]=(q+i*col);
}
else
{
printf("error\n");
 free(p);
free(q);
p=NULL;
}
printf("success\n");
return p;
}
void freea(int** a)
{
free(a[0]);
free(a);
printf("free success\n");
}
int main()
{
int** p=malloca(5,5);
freea(p);
}
