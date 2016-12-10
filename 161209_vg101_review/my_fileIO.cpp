#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

class biao
{
public:
	vector<char> name;
	vector<string> value;

};


int main()
{
	fstream f_cin;
	f_cin.open("test.txt", std::ios::in);

	biao b1;

	string line;
	while (getline(f_cin, line))
	{
		b1.name.push_back(line[0]);

		b1.value.push_back(line.substr(2));
	}

	f_cin.close();

	string my_command;
	getline(cin, my_command);
	

	stringstream binary;
	for (auto it = my_command.begin(); it != my_command.end(); it++)
	{
		for (auto itb = b1.name.begin(); itb != b1.name.end(); itb++)
		{
			if (*itb == *it)
			{
				binary << b1.value[itb - b1.name.begin()];
			}
		}
	}

	string mout;
	string mout_q;
	string mout_h;
	binary >> mout;
	cout << mout << endl;
	cout << mout.size() << endl;
	for (int i = 1; 4*i  < mout.size(); i++)
	{
		
			
		cout << mout.substr(0, 4 * i )<<endl;
		mout_q = mout.substr(0, 4 * i);
		mout_h= mout.substr( 4 * i);
	}
	cout << mout_q<<endl;
	cout << mout_h << endl;

	long long int tohex=0;
	for (int i = 0; i < mout_q.size(); i++)
	{
		if(mout[i]=='1')
		tohex += pow(2,mout_q.size()-i-1);
	}
	cout << tohex<<endl;
	cout << hex << tohex;
	cout << mout_h;

	cin.get();
}