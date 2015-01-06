

//main method
int main()
{
	bi_tree t;
	if(!create_bi_tree(&t))
		printf("create binary tree failed!");
	if(!pre_order_traverse(t,visit))
		printf("traverse binary tree failed!");	
	return 0;
}
