/**
 *queue's some definition
 *author:zhaogang
 *email:zg3407@gmail.com
 *date:2015-1-6
 */

#ifndef _QUEUE_H
#define _QUEUE_H

typedef int queue_elem_type;
typedef struct queue_node_tag
{
	queue_elem_type data;
	struct queue_node_tag *next;
}queue_node,*queue_node_ptr;

typedef struct link_queue_tag
{
	queue_node_ptr front;
	queue_node_ptr rear;
}link_queue;

int init_queue(link_queue *q);
int destory_queue(link_queue *q);
int queue_empty(link_queue q);

int en_queue(link_queue *q,queue_elem_type e);

int de_queue(link_queue *q,queue_elem_type *e);

#endif 
