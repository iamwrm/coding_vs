// try multi file.cpp : �������̨Ӧ�ó������ڵ㡣
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

