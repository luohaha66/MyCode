#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class my_thread
{
public:
	void create_pth();
	~my_thread();
	void* (*p)(void* arg);
private:
	pthread_t pid;
};

void my_thread::create_pth()
{
	pthread_create(&pid, NULL, p, NULL);
}

my_thread::~my_thread()
{
	pthread_exit(NULL);
}

void* run(void* arg)
{
	while(1)
	{
		cout << "aaaaaa" << endl;
		sleep(1);
	}
}

int main()
{
	my_thread a;
	a.p = run;
	a.create_pth();
	return 0;
}