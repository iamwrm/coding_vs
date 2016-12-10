#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
    string line, word;
    vector<string> mylist;
    getline(cin, line);
    stringstream buffer(line);
    while (buffer >> word)
    {
        mylist.push_back(word);
    }
    sort(mylist.begin(), mylist.end());

    for (auto it = mylist.begin(); it != mylist.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}