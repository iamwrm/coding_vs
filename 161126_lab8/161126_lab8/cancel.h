#include <iostream>


class block
{
    char blocktype;
    bool moved;
public:
	char getblocktype();
	void cancel();
	void setblocktype(char c);
	void setmoved(bool b);
	bool getmoved();
};

void block::setblocktype(char c)
{
	blocktype = c;
}

void block::setmoved(bool b)
{
	moved = b;
}

