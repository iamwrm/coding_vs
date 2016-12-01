#include<iostream>
using namespace std;
int count = 0;

class stu
{
public:
	int age;
	int sex;
	stu(void)
	{
		age = 0;
		sex = 0;
		::count++;
	} 
	stu(stu &input)
	{
		age = input.age;
		sex = input.sex;
		::count++;
	}
};


stu he(stu input)
{
	return input;
}


int main()
{
	stu p1,p2;
	
	p2 = he(p1);

	cout << ::count;
	cin.get();
}