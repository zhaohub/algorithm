/**
 *create binary and preorder traverse binary
 *author:zhaogang
 *email:zg3407@gmail.com
 *date:2015-1-5
 */
#include <stdio.h>
#include <stdlib.h>

typedef int t_elem_type;

#define bool _Bool
#define true 1
#define false 0

//tree node definition
typedef struct bi_t_node_tag
{
    t_elem_type data;
    struct bi_t_node_tag *lchild, *rchild;

} bi_t_node, *bi_tree;

//recursive method for create binary tree
bool create_bi_tree(bi_tree *t)
{
    int ch;
    printf("intput a digit:\n");
    scanf("%d", &ch);
    if(ch == 0) *t = NULL;
    else
    {
        if(!(*t = (bi_t_node *)malloc(sizeof(bi_t_node))))
            exit(0);
        (*t)->data = ch;
        if(create_bi_tree(&(*t)->lchild))
            if(create_bi_tree(&(*t)->rchild))
                return true;
    }
    return true;
}

//recursive method for traverse binary tree
bool pre_order_traverse(bi_tree t, bool (*visit)(t_elem_type e))
{
    if(t)
    {
        visit(t->data);
        if(pre_order_traverse(t->lchild, visit))
            if(pre_order_traverse(t->rchild, visit))
                return true;
        return false;
    }
    else
    {
        printf("empty node\n");
    }
    return true;
}
//method for every tree node
bool visit(t_elem_type e)
{
    printf("%d\n", e);
    return true;
}
void print_node_way(int nodes[])
{
    for()
    {
    }
}

//main method
int main()
{
    bi_tree t;
    if(!create_bi_tree(&t))
        printf("create binary tree failed!");
    if(!pre_order_traverse(t, visit))
        printf("traverse binary tree failed!");
    return 0;
}
