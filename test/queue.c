#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

bool init_queue(link_queue *q)
{
	q->front=q->rear=(queue_node_ptr)malloc(sizeof(queue_node));
	if(!q->front) return false;
	q->front->next=NULL;
	return true;
}

bool destory_queue(link_queue *q)
{
	while(q->front)
	{
		q->rear=q->front->next;
		free(q->front);
		q->front=q->rear;
	}
	return true;
}

bool queue_empty(link_queue q)
{
	if(q.front==q.rear&&q.front->next==NULL) return true;
	return false;
}

//insert an element to the queue's rear
bool en_queue(link_queue *q,queue_elem_type e)
{
	queue_node *node=(queue_node*)malloc(sizeof(queue_node));
	if(!node) return false;
	node->data=e;
	node->next=NULL;
	q->rear->next=node;
	q->rear=node;
	return true;
}

//delete and elememnt from the front of the queue
bool de_queue(link_queue *q,queue_elem_type *e)
{
	if(queue_empty(*q)) return false;
	queue_node *node=q->front;
	q->front=q->front->next;	
	if(q->rear==node) q->rear=q->front;
	free(node);
	return true;
}
