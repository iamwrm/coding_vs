#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int & add_one(int &lastguy, const string input);

class database
{
public:
	string name[100];
	string address[100];
	int lastguy;

	database(void)
	{
		lastguy = 0;
		for (int i = 0; i < 100; i++)
		{
			name[i] = "-----------";
		}
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
		for (int i = 0; i < lastguy; i++)
		{
			cout << name[i] << endl;
		}
	}
	void show_all_address(ostream & cout)
	{
		for (int i = 0; i < lastguy; i++)
		{
			cout << address[i] << endl;
		}
	}
	void save_into_file(fstream & file_out)
	{
		for (int i = 0; i < lastguy; i++)
		{
			file_out << name[i] << '|' << address[i] << "|\n";
		}
	}

};


int main()
{
	fstream my_database_in;
	my_database_in.open("datao.txt", std::fstream::in);

	database da1;
	string f_in;

	while (getline(my_database_in, f_in, '|'))
	{
		da1.add_name(f_in);
		getline(my_database_in, f_in, '|');
		da1.add_address(f_in);

		getline(my_database_in, f_in, '\n');
		da1.lastguypp();
	}
	my_database_in.close();

	int call_exit = 0;
	while (call_exit == 0)
	{
		cout << "  >";

		string input;
		cin >> input;
		if (input == "exit")
		{
			call_exit = 1;
		}
	}



	//close sentence
	cout << "\nThe shell is closing\nSaving your data";
	for (int i = 0; i < 10; i++)
	{
		cout << ".";
		_sleep(200);
	}
	_sleep(1000);

	//save file
	fstream my_database_out;
	my_database_out.open("data.txt", std::fstream::out);
	da1.save_into_file(my_database_out);
	my_database_out.close();
	return 0;
}

int & add_one(int & lastguy, const string input, database& my_database)
{
	//my_database.add_name()


	return lastguy;
}
