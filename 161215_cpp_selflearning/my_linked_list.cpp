#include <iostream>
#include <cstdlib>

class lklst_node
{
	lklst_node * prev;
	lklst_node * next;
	double data;

public:
	lklst_node * set(lklst_node * header, double input)
	{
		data=input;
		prev =header;
		return next;
	}

};


class lklst
{
lklst_node * ini;
lklst_node * header;

public:
	lklst()
	{
		ini=new lklst_node;
		header=new lklst_node;
		ini=header=NULL;
	}
	
	void push_back(double input)
	{
		lklst_node * nextnode=new lklst_node;
		header=nextnode;
		header=nextnode->set(header,input);
	}

	void show()
	{

	}
	
};





int main()
{
	std::cout<<"================\n";

	lklst l1;
	l1.push_back(4.0);




	return 0;
}