#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i = 0;
	vector<int> arr;
	vector<int>::iterator ptr;
	for(i = 0; i < 10; i++)
		arr.push_back(i);
	for(i = 0; i < arr.size(); i++)
		cout << arr.at(i) << " ";
	cout << endl;
	ptr = arr.begin(); 
	for(i = 0; i < 10; i++)
	{
		*ptr = i * i;
		ptr++;
	}
	for(i = 0; i < arr.size(); i++)
		cout << arr.at(i) << " ";
	cout << endl;
	arr.erase(ptr - 1);
	for(i = 0; i < arr.size(); i++)
		cout << arr.at(i) << " ";
	cout << endl;
	for(i = 0; i < 3; i++)
		arr.pop_back();
	for(i = 0; i < arr.size(); i++)
		cout << arr.at(i) << " ";
	cout << endl;
	arr.erase(arr.begin(), arr.end());
	return 0;
}