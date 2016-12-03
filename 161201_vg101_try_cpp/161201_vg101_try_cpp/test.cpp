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


	cout << "--\n";
	/*cout << b1.mlist[0][0] << endl;
	cout << b1.mlist[0][1] << endl;
	cout << b1.mlist[0][2] << endl;*/

	



	fstream database_file_out;
	database_file_out.open("testout.txt", std::ostream::out);

	b1.print_database( database_file_out);

	database_file_out.close();
	cin.get();
	return 0;
}

