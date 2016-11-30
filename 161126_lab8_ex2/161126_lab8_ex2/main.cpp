#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#define N 10
using namespace std;


void my_bubblesort(char *arr, int len);


class player
{
private:
	char hand[N];
	char exist_card[N];
	char last_bolted = '0';
	int score;
	int change_card(int position, char card);
	string name;

public:
	player(string name_input)
	{
		name = name_input;
		for (int i = 0; i < N; i++)
		{
			hand[i] = '0';
		}
		for (int i = 0; i < N; i++)
		{
			exist_card[i] = '0';
		}

		for (int i = 0; i < N; i++)
		{
			hand[i] = rand() % 9 + '1';
		}
		my_bubblesort(hand, N);

		for (int i = 0; i < N; i++)
		{
			if (hand[i] == '8')
			{
				hand[i] = 'm';
			}
			else if (hand[i] == '9')
			{
				hand[i] = 'b';
			}
		}
	}
	void show(int arg);
	int paly_card(char card);
};



//arg=1 上帝视角   arg=2 对手视角
void player::show(int arg)
{
	cout << name<<": ";
	if (arg == 1)
	{
		for (int i = 0; i < N; i++)
		{
			if (hand[i] != '0')
			{
				cout << hand[i];
			}
		}
		cout << "/";
		for (int i = 0; i < N; i++)
		{
			if (exist_card[i] != '0')
			{
				cout << exist_card[i];
			}
		}
		cout << "/" << endl;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (hand[i] != '0')
			{
				cout << "X";
			}
		}
		cout << "/";
		for (int i = 0; i < N; i++)
		{
			if (exist_card[i] != '0')
			{
				cout << exist_card[i];
			}
		}
		cout << "/" << endl;
	}
}

int player::change_card(int position, char card)
{
	if (hand[position] == '0')
	{
		hand[position] = card;
		return 1;
	}
	else
	{
		cout << "error: there already exists a card";
		return 0;
	}
}

int player::paly_card(char card_input)
{
	int found = 0;
	int i_hand = 0;
	for (i_hand = 0; i_hand < N; i_hand++)
	{
		if (hand[i_hand] == card_input)
		{
			found = 1;
			break;
		}
	}

	if (found == 0)
	{
		cout << "error: no such card";
		return 0;// 0 means failed
	}

	int i_ec = 0;// index of existed card
	while (exist_card[i_ec] != '0')
	{
		i_ec++;
	}
	exist_card[i_ec] = card_input;
	hand[i_hand] = '0';

	return 1;// 1 means succeed
}

//自定义排序







int main()
{
	srand(time(NULL));
	string name1 = "John";
	string name2 = "Tom";

	player p1(name1), p2(name2);
	
	cout << "Welcome to BLADE!" << '\n';
	
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


	
void my_bubblesort(char *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				char temp;
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}


