#define N 10
#include <iostream>
#include "player.h"
using namespace std;

int main()
{
	player p1, p2;
	srand(time(NULL));

	p1.ini();
	p2.ini();


	while (1)
	{
		p2.show(1);
		p1.show(1);

		char p2_input;
		cin >> p2_input;
		p2.paly_card(p2_input);

		p2.show(1);
		p1.show(1);

		char p1_input;
		cin >> p1_input;
		p1.paly_card(p1_input);
	}

	cin.get();

}