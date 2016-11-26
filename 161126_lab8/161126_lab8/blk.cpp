#include <iostream>
#include <vector>
#include "cancel.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream infile("situation");
	char a[4][7];
	for(int i =0 ;i<4;i++)
	{
		for(int j =0;j<7;j++)
		{
			infile>>a[i][j];
		}

	}
	vector< vector<block*> > cancel(4);
	for(int i =0 ;i<4;i++)
	{
		for(int j =0;j<7;j++)
		{
			block *blk = new block;
			blk->setblocktype(a[i][j]);
			blk->setmoved(false);
			cancel[i].push_back(blk);
		}
	}
	//start here
}
