#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	fstream f_in;
	f_in.open("my_re.txt", ios::in);

	string sentence;
	getline(f_in, sentence);

	vector<string> vs1;

	int start = 0;
	int end = 0;
	for (end = 0; end < sentence.size(); )
	{
		while ((end < sentence.size()) && (sentence[end] != ' '))
		{
			end++;
		}
		vs1.push_back(sentence.substr(start, end - start));
		start = end + 1;
		end = start;

	}

	cout << sentence << endl;


	system("pause");
	string rsentence;
	rsentence = "";
	for (int i = 0; i < vs1.size(); i++)
	{
		rsentence = rsentence + vs1[vs1.size()-i-1] + ' ';
	}
	cout << rsentence;

	system("pause");

}