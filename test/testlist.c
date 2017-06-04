#include <stdio.h>
#include <stdlib.h>

#include "../include/list.h"


int main(int argc,char* argv[])
{
    int i;
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->item = -10;
    //head->next=NULL;
    node_t *tmp = head;
    for(i = 0; i < 100; i++)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->item = i;
        node->next = NULL;
        head->next = node;
        head = node;
    }
    head = tmp;
    node_t *h = reverse_list(head);
    for(; h; h = h->next)
    {
        printf("%d\n", h->item);
    }

}