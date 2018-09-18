#include <iostream>
#include <stdio.h>

using namespace std;

class A{
public:
	A(){
        printf("A constrution.\n");
    }
    ~A(){
        printf("A deconstrution.\n");
    }
	void funA();
	virtual  void funB();
};

void A::funA(){
	printf("A::funA ...\n");
} 
   
void A::funB(){
	printf("A::funB ...\n");
}
 
class B : public A{
public:
	B(){
		printf("B constrution.\n");
	}
	~B(){
		printf("B deconstrution.\n");
	}
	void funA();
	virtual  void funB();
};

void B::funA(){
	printf("B::funA ...\n");
}

void B::funB(){
	printf("B::funB ...\n");
} 

int main()
{
    A *a = new B();
    B b;
	  a->funA();
    a->funB();
    b.funA();
    b.funB();
    delete a;
}