#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class database
{
	string name[100];
	string address[100];
	int lastguy;
public:
	database(void)
	{
		lastguy = 0;
	}
	void add_name(string input)
	{
		name[lastguy] = input;
	}
	void add_address(string input)
	{
		address[lastguy] = input;
	}
	void lastguypp()
	{
		lastguy++;
	}
	int show_lastguy()
	{
		return lastguy;
	}
	void show_all_name(ostream &cout)
	{
		for (int i = 0; i < lastguy + 1; i++)
		{
			cout << name[i] << endl;
		}
	}
	void show_all_address(ostream & cout)
	{
		for (int i = 0; i < lastguy + 1; i++)
		{
			cout << address[i] << endl;
		}
	}

};


int main()
{
	/*ofstream my_database_out;
	my_database_out.open("data.txt");*/	// | std::ofstream::app
	ifstream my_database_in;
	my_database_in.open("data.txt");

	database da1;




	string f_in;


	
	while(getline(my_database_in, f_in, '|'))
	{
		da1.add_name(f_in);
		getline(my_database_in, f_in, '\n');
		da1.add_address(f_in);
		da1.lastguypp();
	}



	cout << da1.show_lastguy() << endl;

	my_database_in.close();

	da1.show_all_name(cout);
	da1.show_all_address(cout);

	ofstream my_database_out;
	my_database_out.open("data.txt", std::ofstream::app);

	da1.show_all_name(my_database_out);
	da1.show_all_address(my_database_out);

	//my_database_out.close();
	cin.get();
	return 0;
}
