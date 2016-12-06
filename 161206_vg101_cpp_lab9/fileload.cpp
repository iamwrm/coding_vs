#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;


class point_m
{
public:
	char value;
	char m1;
	char m2;
	point_m()
	{
		value = ' ';
		m1 = ' ';
		m2 = ' ';
	}
};

class store_m
{
public:vector<point_m> points;
	   store_m()
	   {
		   for (int i = 0; i < 64; i++)
		   {
			   point_m temp1;
			   points.push_back(temp1);
		   }
	   }


	   void load_from_file(char* filename)
	   {
		   fstream f_cin;
		   f_cin.open(filename, iostream::in);
		   string buffer;
		   points.clear();

		   for (int i = 0; i < 8; i++)
		   {
			   getline(f_cin, buffer);
			   //cout << buffer << endl;
			   for (int j = 0; j < 8; j++)
			   {
				   point_m temp1;
				   temp1.value = buffer[3 * j];
				   temp1.m1 = buffer[3 * j + 1];
				   temp1.m2 = buffer[3 * j + 2];

				   points.push_back(temp1);
			   }
		   }
		   f_cin.close();
	   }



	   void save_to_file(char* filename)
	   {
		   fstream f_cout;
		   f_cout.open(filename, iostream::out);
		   
		   for (int i = 0; i < 8; i++)
		   {
			   for (int j = 0; j < 8; j++)
			   {
				   f_cout << points[8 * i + j].value;
				   f_cout << points[8 * i + j].m1;
				   f_cout << points[8 * i + j].m2;
			   }

			   if (i < 7)
			   {
				   f_cout << endl;
			   }
		   }



		   f_cout.close();
	   }
};

int main()
{

	store_m a1;

	a1.load_from_file("test.txt");





	a1.save_to_file("testout.txt");
	
	return 0;
}