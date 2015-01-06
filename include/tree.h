/**
 *tree definitions
 *author:zhaogang
 *email:zg3407@gmail.com
 *date:2015-1-6
 */

#ifndef _TREE_H
#define _TREE_H

typedef int tree_elem_type;

typedef struct bi_tree_node_tag
{
	tree_elem_type data;
	struct bi_tree_node_tag *lchild,*rchild;
}bi_tree_node,*bi_tree;

int create_bi_tree(bi_tree *t);

int pre_order_traverse(bi_tree t,int (*visit)(tree_elem_type e));

int visit(tree_elem_type);


#endif
