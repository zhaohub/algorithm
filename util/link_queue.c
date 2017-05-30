/**
 *implementation of single pointer queue
 *author:zhaogang
 *email:zg3407@email.com
 *date:2015-1-6
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int init_queue(link_queue *q)
{
    q->front = q->rear = (queue_node_ptr)malloc(sizeof(queue_node));
    if(!q->front) return 0;
    q->front->next = NULL;
    return 1;
}

int destory_queue(link_queue *q)
{
    while(q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return 1;
}

int queue_empty(link_queue q)
{
    if(q.front == q.rear && q.front->next == NULL) return 1;
    return 0;
}

//insert an element to the queue's rear
int en_queue(link_queue *q, queue_elem_type e)
{
    queue_node *node = (queue_node *)malloc(sizeof(queue_node));
    if(!node) return 0;
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
    return 1;
}

//delete and elememnt from the front of the queue
int de_queue(link_queue *q, queue_elem_type *e)
{
    if(queue_empty(*q)) return 0;
    queue_node *node = q->front;
    q->front = q->front->next;
    if(q->rear == node) q->rear = q->front;
    free(node);
    return 1;
}
