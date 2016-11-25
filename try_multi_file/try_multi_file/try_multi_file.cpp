// try multi file.cpp : 定义控制台应用程序的入口点。
//
#include<cstdlib>
#include<iostream>
#include "linked_list.h"


node* create_list(double value);

int main()
{
	node *a;
	a = create_list(3.0);

	std::cout << a->data; int aaa;



	return 0;
}

