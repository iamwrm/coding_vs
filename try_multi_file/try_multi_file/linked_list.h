typedef struct node_struct
{
	double data;
	struct node_struct *prev;
	struct node_struct *next;
}node;

node* create_list(double value)
{
	node* head;
	head = (node*)malloc(sizeof(node));
	head->data = value;
	head->prev = NULL;
	head->next = NULL;
	return head;
}