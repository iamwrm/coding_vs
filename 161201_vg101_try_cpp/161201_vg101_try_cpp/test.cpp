#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

#define INITIAL (0)
#define EXIT (1)
#define VALID (2)


class database
{
public:
	vector<string> heading;
	vector<vector<string>> mlist;
	void add_one_person(vector<string> & input_person);
	void print_database(ostream &f_cout);
	void scan_database(fstream& database_file_in);
	database();
};

void close_sentence();
void process_com(string command, int &flag);
void print_help();
void show_error(int flag);

int main()
{
	database b1;

	fstream database_file_in;
	database_file_in.open("testin.txt", std::ostream::in);

	// import from file
	b1.scan_database(database_file_in);



	/*vector<string> testv1;
	string s1 = "wrewrwerewr", s2 = "Ren 1", s3 = "Dong", s4 = "Shanghai";
	testv1.push_back(s1);
	testv1.push_back(s2);
	testv1.push_back(s3);
	testv1.push_back(s4);
	b1.add_one_person(testv1);*/

	cout << "Welcome to my sql database\n"
		<<"You can enter -h to get help\n";
	int flag = INITIAL;
	while (flag != EXIT )
	{
		flag = INITIAL;

		cout << "  >";

		string input;
		cin >> input;

		process_com(input, flag);

		show_error(flag);
	}

	//close sentence
	close_sentence();

	//saving into file
	fstream database_file_out;
	database_file_out.open("testout.txt", std::ostream::out);
	b1.print_database(database_file_out);
	database_file_out.close();

	return 0;
}

void close_sentence()
{
	cout << "\nThe shell is closing\nSaving your data";
	for (int i = 0; i < 10; i++)
	{
		cout << ".";
		_sleep(200);
	}
	_sleep(1000);
}

//flag 1:exit
void process_com(string command, int &flag)
{
	if (command == "exit")
	{
		flag = EXIT;
		return;
	}
	if (command == "-h")
	{
		print_help();
		flag = VALID;
		return;
	}


}

void print_help()
{
	cout <<"You can use the following commands\n"
		<< "Enter exit to exit\n";
}

void show_error(int flag)
{	
	if (flag == INITIAL)
	{
		std::cout << "Invalid input. Try again\n";
	}
}


void database::add_one_person(vector<string> & input_person)
{
	mlist.push_back(input_person);
}

void database::print_database(ostream &f_cout)
{
	for (int i = 0; i < mlist.size(); i++)
	{
		for (int j = 0; j < mlist[i].size(); j++)
		{
			f_cout << mlist[i][j];
			f_cout << "|";
		}
		f_cout << endl;
	}
}

void database::scan_database(fstream & database_file_in)
{
	string buffer_line;
	while (getline(database_file_in, buffer_line, '\n'))
	{

		// avoid adding an unneeded \n
		if (buffer_line.size() == 0)
		{
			break;
		}

		vector<string> one_line_from_file;
		for (int i = 0, j = 0; i < buffer_line.size(); i++)
		{
			if (buffer_line[i] == '|')
			{
				one_line_from_file.push_back(buffer_line.substr(j, i - j));
				j = i + 1;
			}
		}
		mlist.push_back(one_line_from_file);
	}

}

database::database()
{
	std::string a1, a2, a3, a4;
	a1 = "LastName";
	a2 = "FirstName";
	a3 = "Address";
	a4 = "City";

	heading.push_back(a1);
	heading.push_back(a2);
	heading.push_back(a3);
	heading.push_back(a4);
}
