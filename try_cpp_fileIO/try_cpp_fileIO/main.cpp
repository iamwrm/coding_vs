/*
Visual Studio 2017 RC

MIT License
Copyright (c) 2016 <iamwrm>
<author>           <version>           <date>                   <change>
iamwrm 				1.0              2016-11-20					��ϰclass private public ֮���



description: 
keywords:   �ļ�����

*/


#include <iostream>
#include <cstdlib>
#include <string>

class mystring
{
public: int length;
		char name[10] = "hehehe";
		int printsex()
		{
			return sex;
		}
		void changesex(int changeto)
		{
			sex = changeto;
		}
private: int sex=1;
};

int main()
{
	using namespace std;

	string name1;
	name1 = "123456";
	cout << name1<<endl;

	mystring h1;
	h1.length = 5;

	h1.changesex(3);
	cout << h1.printsex()<<endl;
	cout<<h1.name;




	return 0;
}