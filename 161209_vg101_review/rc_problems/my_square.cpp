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

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int i, j, k;
	for (i = 0; i <= N; ++i)
	{
		for (j = 0; j <= N; ++j)
		{
			for (k = 0; k < N + 1; ++k)
			{
				if ((N*N == i*i + k*k + j*j) && (i >= j) && (j >= k))
				{
					cout << N << "^2 =" << setw(10) << i << "^2 + " << j << "^2 + " << k << "^2" << endl;
				}
			}
		}
	}





	return 0;
}