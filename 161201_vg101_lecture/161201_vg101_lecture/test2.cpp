#include<iostream>



using namespace std;

class stu
{
public:
	int age;
	int sex;
	stu(void)
	{
		age = 0;
		sex = 0;
	}
	stu(int age_i, int sex_i)
	{
		age = age_i;
		sex = sex_i;
	}
};


int main()
{
	stu p1;
	stu p2(3, 4);


	cout << p1.age << p1.sex << endl;
	cout << p2.age << p2.sex << endl;
	cin.get();
}