#include <stdio.h>
#include <stdlib.h>

//#include <include/queue.h>
#include "include/tree.h"

//main method
int main()
{
    bi_tree t;
    if(!create_bi_tree(&t))
        printf("create binary tree failed!");
    if(!pre_order_traverse(t, visit))
        printf("traverse binary tree failed!");
    int num = 0;
    sta_leaf_node(t, &num);
    printf("leaf node is %d\n", num);

    return 0;
}
