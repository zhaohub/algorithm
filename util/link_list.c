#include <stdio.h>
#include <stdlib.h>

#include "../include/list.h"

node_t *reverse_list(node_t *head)
{
    node_t *n = head;
    head = NULL;
    while(n)
    {
        node_t *m = n;
        n = n->next;
        m->next = head;
        head = m;
    }
    return head;
}
