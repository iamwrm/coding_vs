#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;


int main()
{
	vector<int> v1 = { 1,2,3,5,7,4,3,1,2,4,5 };

	for (auto it = v1.begin(); it != v1.end(); it++)
	{

		cout << *it;

	}
	cout << endl;



	auto temp = find(v1.begin(), v1.end(), 3);

	v1.erase(temp);



	cout << endl;

	vector<int> v1 = { 1,2,3,5,7,4,3,1,2,4,5 };
	reverse(v1.begin(), v1.end());

	for (auto it = v1.begin(); it != v1.end(); it++)
	{

		cout << *it;

	}

	system("pause");



}