#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


typedef struct node_type
{
	double data;
	struct node_type *prev;
	struct node_type *next;
}node;

node* initial_list(double value)
{
	node* head;
	head = (node*)malloc(sizeof(node*));
	head->data = value;
	head->prev = NULL;
	head->next = NULL;
	
	return head;
}




int main()
{
	node* a;
	a = initial_list(5.0);
	getchar();

	//	system("pause");
	return 0;




}