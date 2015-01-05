#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
	int item;
	struct node_s* next;
}node_t;

node_t* reverse_list(node_t* head)
{
	node_t* n=head;
	head=NULL;		
	while(n)
	{
		node_t* m=n;
		n=n->next;	
		m->next=head;
		head=m;
	}
 	return head;
}

int main(void)
{
	int i;
	node_t* head=(node_t*)malloc(sizeof(node_t));
	head->item=-10;
	//head->next=NULL;
	node_t* tmp=head;
	for(i=0;i<100;i++)
	{
		node_t* node=(node_t*)malloc(sizeof(node_t));
		node->item=i;
		node->next=NULL;
		head->next=node;
		head=node;
	}
	head=tmp;
	node_t* h=reverse_list(head);
	for(;h;h=h->next)
	{
		printf("%d\n",h->item);
	}
	
}
