#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int find = 1;
	for (int i = 1; (i <= a) && (i <= b); ++i)
	{
		if ((a%i == 0) && (b%i == 0))
		{
			find = i;
		}
	}
	return find;
}

class my_rationalnum
{
public:
	string upper;
	string lower;
public:
	my_rationalnum()
	{
		upper = "0";
		lower = "1";
	}

	void show()
	{
		int u = atoi(upper.c_str());
		int l = atoi(lower.c_str());
		cout << u << "/" << l << endl;
	}

	my_rationalnum operator+(my_rationalnum b)
	{
		
		my_rationalnum temp;
		int u1 = atoi(upper.c_str());
		int l1 = atoi(lower.c_str());
		int u2 = atoi(b.upper.c_str());
		int l2 = atoi(b.lower.c_str());
		int u3 = 0;
		int l3 = 0;

		u3 = u1*l2 + u2*l1;
		l3 = l1*l2;

		int u33 = u3;
		int l33 = l3;

		while (gcd(u3, l3) > 1)
		{
			u3 /= gcd(u33, l33);
			l3 /= gcd(u33, l33);
		}


		stringstream ss1;
		ss1 << l3;
		ss1 >> temp.lower;

		ss1.clear();

		ss1 << u3;
		ss1 >> temp.upper;
		return temp;

	}


};

int main()
{

	my_rationalnum m1, m2;

	m1.upper = "-1";
	m1.lower = "12";
	m1.show();

	m2.upper = "1";
	m2.lower = "3";
	m2.show();
	my_rationalnum m3;
	m3 = m1 + m2;
	m3.show();


}