#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 10

void my_bubblesort(char *arr, int len);

class player
{
    char hand[N];
    char exist_card[N];
    char last_bolted = '0';
    int score;
	int change_card(int position, char card);

  public:
    void ini();
    void show(int arg);
	int paly_card(char card);
};

//初始化手牌和场上牌
void player::ini()
{

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
        hand[i] = rand()%9 + '1';
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

//arg=1 上帝视角   arg=2 对手视角
void player::show(int arg)
{
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
	for (i_hand=0; i_hand < N; i_hand++)
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
