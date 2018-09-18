#include <iostream>
#include <cstring>

using namespace std;

class aaa{
public:
	aaa(const char* a){
		q = a;
		}
	friend char* operator+(aaa& s, aaa& b);
private:
	const char *q;
};

char* operator+(aaa& s, aaa& b)
{
	int i = 0;
	int j = 0;
	char* q = new char[30];
	while(*(q + i) =  *(s.q + (i++)));
	i--;
	while(*(q + i + j) = (*(b.q + (j++))));
	*(q + i + j) = '\0';
	return q;
}

int main()
{
	aaa s("hello ");
	aaa b("world");
	cout << s + b << endl;
}