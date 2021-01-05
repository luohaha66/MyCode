#include<stdio.h>
#define STRUCT(type) typedef struct _tag_##type type;\
struct _tag_##type
STRUCT(student)
{
int i;
char *name;
};
typedef struct _tag_aa aa; struct _tag_aa
{
int i;
};
int main()
{
student s;
aa a;
a.i=1;
s.i =1;
s.name="sadas";
printf("%d %d %s\n",a.i,s.i,s.name);
}
