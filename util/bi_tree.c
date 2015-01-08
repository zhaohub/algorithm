/**
 *create binary and preorder traverse binary 
 *author:zhaogang
 *email:zg3407@gmail.com
 *date:2015-1-5
 */
#include <stdio.h>
#include <stdlib.h>

typedef int tree_elem_type;

//tree node definition 
typedef struct bi_t_node_tag
{
	tree_elem_type data;
	struct bi_t_node_tag *lchild,*rchild;

}bi_t_node,*bi_tree;

//recursive method for create binary tree 
int create_bi_tree(bi_tree *t)
{	
	int ch;
	printf("intput a digit:\n");
	scanf("%d",&ch);
	if(ch==0) *t=NULL;
	else
	{
		if(!(*t=(bi_t_node*)malloc(sizeof(bi_t_node))))
			return 0;
		(*t)->data=ch;
		if(create_bi_tree(&(*t)->lchild))
			if(create_bi_tree(&(*t)->rchild))
		return 1;
	}
	return 1;
}

//recursive method for traverse binary tree
int pre_order_traverse(bi_tree t,int (*visit)(tree_elem_type e))
{
	if(t)
	{
		visit(t->data);
		if(pre_order_traverse(t->lchild,visit))
			if(pre_order_traverse(t->rchild,visit))
				return 1;
		return 0;
	}else
	{
		printf("empty node\n");
	}
	return 1;
}
//method for every tree node
int visit(tree_elem_type e)
{
	printf("%d\n",e);
	return 1;
}

void sta_leaf_node(bi_tree t,int* num)
{
	if(t)
	{
		if(!t->lchild&&!t->rchild)
		{
			(*num)++;
			return;
		}		
		sta_leaf_node(t->lchild,num);
		sta_leaf_node(t->rchild,num);
	}
}
