#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	string mmhex;
	cin >> mmhex;

	int binn = 0;
	for (int jj = 0; jj < mmhex.size(); jj++)
	{
		binn += pow(2, mmhex.size() - jj - 1);
	}

	cout <<hex <<binn;
	cin.get();
	cin.get();

}