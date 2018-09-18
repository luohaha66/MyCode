#include "house.h"

using namespace std;

int main()
{
	Teach_Build tb("Main Teach Build", 59, 6, 66, 18000);
	Dorm_Build db("Boy Dorm", 41, 5, 75, 3750, 300);
	tb.ShowTeach_Building();
	cout << endl;
	db.ShowDorm_Building();
	return 0;
}