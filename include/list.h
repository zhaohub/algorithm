#ifndef _LIST_H
#define _LIST_H

typedef struct node_s
{
    int item;
    struct node_s *next;
} node_t;


node_t *reverse_list(node_t *head);


#endif