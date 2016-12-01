#include<iostream>
#include<time.h>

using namespace std;

class stu
{
public:
	char name[10000] = { 0 };
	int age;
	stu()
	{
		age = 10;
	}
};

stu change_c(stu stu_input)
{
	stu_input.age = 12;
	return stu_input;
}

stu & change_r(stu &stu_input)
{
	stu_input.age = 12;
	return stu_input;
}
template<typename T>

void counting(T input)
{
	int i = input % 20;
	for (int j = 0; j < i; j++)
	{
		cout << "=";
	}
	cout <<"\n";
}


int main()
{
	stu p1, p2;
	long int t1, t2, t3, t4;
	t1 = time(NULL);
	const long int MAX = 6000;
	for (long int i = 0; i < MAX; i++)
	{
		for (long int j = 0; j < MAX; j++)
		{
			p2 = change_c(p1);
			//counting(j);
			
		}
		//cout << i << endl;

	}
	t2 = time(NULL);

	for (long int i = 0; i < MAX; i++)
	{
		for (long int j = 0; j < MAX; j++)
		{
			p2 = change_r(p1);
			//counting(j);
			//cout << i << endl;
		}
		//cout << i << endl;
	}

	t3 = time(NULL);

	cout << (t2 - t1) << "----" << (t3 - t2);



	cin.get();
	return 0;


}