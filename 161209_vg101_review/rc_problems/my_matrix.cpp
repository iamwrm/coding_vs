#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class myMatrix
{
public:
	std::vector<double> v1;
	int row;
	int col;

public:
	myMatrix()
	{
		row = 0;
		col = 0;
	}

	myMatrix(int row_i, int col_i)
	{
		row = row_i;
		col = col_i;
	}

	int assign(string input)
	{
		double word;
		stringstream stream1(input);
		vector<double> vline;
		while (stream1 >> word)
		{
			vline.push_back(word);
		}

		if (vline.size() == row*col)
		{
			v1 = vline;
			return 1;
		}
		else
		{
			cout << "dimension doesn't match\n";
			return 0;
		}
	}

	void print()
	{
		for (int i = 0; i < v1.size(); ++i)
		{
			cout << setw(5) << v1[i];
			if ((i + 1) % col == 0)
			{
				cout << endl;
			}
		}
		cout << endl;
	}

	myMatrix operator+(myMatrix b) const
	{
		myMatrix temp;
		if (!((this->col == b.col) && (this->row == b.row)))
		{
			cout << "dimension doesn't match, cannot add\n";
			return temp;
		}
		temp.row = this->row;
		temp.col = this->col;

		for (int i = 0; i < this->v1.size(); i++)
		{
			temp.v1.push_back(this->v1[i] + b.v1[i]);
		}
		return temp;


	}

};

int main(int argc, char const *argv[])
{

	myMatrix m11(3, 2);
	m11.assign("1 2 3 4 5 6");

	m11.print();

	myMatrix m12;
	m12 = m11;
	m12.assign("7 8 9 10 11 12");
	m12.print();

	myMatrix m13;
	m13 = m11 + m12;
	m13.print();



	return 0;
}