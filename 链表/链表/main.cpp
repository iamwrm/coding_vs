#include <iostream>
#include <cstdlib>
#include<ctime>


using namespace std;

typedef struct node_struct
{
	double value;
	struct node_struct *prev;
	struct node_struct *next;
} node;

node *create(double kk)
{
	node *head;
	head = (node *)malloc(sizeof(node));
	head->value = kk;
	head->prev = NULL;
	head->next = NULL;
	return head;
}

void insert(double kk, node *head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	node *nextele;
	nextele = (node *)malloc(sizeof(node));
	nextele->value = kk;
	nextele->next = NULL;
	nextele->prev = head;
	head->next = nextele;
}

void print_all(node *head)
{
	while (head->next != NULL)
	{
		cout << head->value << endl;
		head = head->next;
	}
	cout << head->value << endl;
}

int search(node *head,double goal)
{
	int count = 0;
	while (head->next != NULL)
	{
		if (head->value == goal)
		{
			count++;
		}
		head = head->next;
	}
	return count;
}

int main()
{
	srand(time(NULL));
	node *a;
	a = create(20.0);


	for (int i = 0; i < 10; i++)
	{
		int temp = (double)rand() / RAND_MAX * 10;

		insert(temp, a);
	}

	insert(6, a);
	insert(6, a);
	

	
	print_all(a);

	cout <<"hehehe:"<< search(a, 6);
	system("pause");
}