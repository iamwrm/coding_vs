#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


class database
{
public:
	vector<vector<string>> mlist;
	void add_one_person(vector<string> & input_person);
	void print_database(ostream &f_cout);
};

void close_sentence();
void process_com(string command, int &flag);

int main()
{
	database b1;
	vector<string> testv1;
	string s1 = "Wang", s2 = "Ren 1", s3 = "Dong",s4="Shang hai";
	testv1.push_back(s1);
	testv1.push_back(s2);
	testv1.push_back(s3);
	testv1.push_back(s4);


	b1.add_one_person(testv1);


	int call_exit = 0;
	while (call_exit == 0)
	{
		cout << "  >";

		string input;
		cin >> input;

		process_com(input, call_exit);
	}



	//close sentence
	close_sentence();

	


	//saving into file
	fstream database_file_out;
	database_file_out.open("testout.txt", std::ostream::out);
	b1.print_database( database_file_out);
	database_file_out.close();

	cin.get();
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
void process_com(string command,int &flag)
{
	if (command == "exit")
	{
		flag = 1;
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
