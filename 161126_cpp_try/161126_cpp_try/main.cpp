#include<iostream>
#include<cstdlib>

class student
{
private:
	int sex;

public:void show_sex();  // declaration, definition is afterwards
	   void change_sex(int sex_input);
};

void student::show_sex()
{
	std::cout << sex<< std::endl;
}

void student::change_sex(int sex_input)
{
	sex = sex_input;
	//student::sex = sex_input;      there is no difference
}

int main()
{
	student yc;

	int xx;
	std::cin >> xx;

	yc.change_sex(xx);
	yc.show_sex();

	
	std::cin.get();
	return 0;
}