#include<iostream>
#include<string>

using namespace std;

class stu
{
public:
	int age;


	class name
	{
	public:
		char name1='a';
		char name2='b';
	};

	stu(void)
	{
		age = 10;
		
	}



};


int main()
{

	stu s1;
	stu::name n1;
	cout << s1.age;

	auto n2 = n1;
	cout << endl << n1.name1;
	cout << endl << n2.name1;

	string sss1("123456");

	cout << endl << sss1 << endl << sss1.length();




	cin.get();
	return 0;
}