#include "slist.h"
#include "search.h"

void myprintf(slist* list, int i)
{
	printf("id: %d \n", list->list_data[i].id);
	printf("age: %d \n", list->list_data[i].age);
	printf("name: %s \n", list->list_data[i].name);
}

void search_stu()
{
	slist* list = creatslist();
	data stu0, stu1, stu2, findstu;
	stu0.id = 1;
	strcpy_s(stu0.name, 3, "xi");
	stu0.age = 18;

	stu1.id = 2;
	strcpy_s(stu1.name, 3, "ha");
	stu1.age = 19;

	stu2.id = 3;
	strcpy_s(stu2.name, 30, "ying ying guai huang hai lei");
	stu2.age = 20;

	findstu.id = 3;

	insert_data(list, 0, stu0);
	insert_data(list, 1, stu1);
	insert_data(list, 2, stu2);
	display(list, myprintf);

	int i = find_element_data(list, findstu);
	printf("the student name you want to get is: %s\n", list->list_data[i].name);
}

int main()
{
	int a[] = {5, 1, 2, 4, 3};
	int i = sizeof(a) / sizeof(*a);
	merge_rank(a, i);
	my_display(a, i);
}