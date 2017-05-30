#include <stdio.h>

#include "../include/queue.h"

extern link_queue;
extern int int_queue(link_queue *q);
int main()
{
	link_queue q;
	init_queue(&q);
	int i=0;
	for(;i<100;i++)
	{
		en_queue(&q,i);
	}
	for(;q.front;q.front=q.front->next)
	{
		printf("queue's node %d\n",q.front->data);
	}
}

