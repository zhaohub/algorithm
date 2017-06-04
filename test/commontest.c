#include <stdio.h>

typedef struct bi_tree_tag
{
    int data;
    struct bi_tree_tag *lchild, *rchild;
} bi_tree_node, *bi_tree;

void change_val(char **p)
{
    char new_val[3] = {2, 3, 4};
    *p = new_val;
    return;
}

int test(int a)
{
    static int test = 0;
    if(a == 0)
        test = 1;

    return test;
}

extern int testfun(int a, int b);

int main(void)
{
    /*char val[3] = {1, 2, 3};
    char *p = val;
    change_val(&p);
    printf("%d\n", sizeof(bi_tree_node));
    printf("%d\n", sizeof(bi_tree));
    printf("%d\n", sizeof(double));
    return;*/
    printf("%d\n", test(-1));
    printf("%d\n", test(0));
    printf("%d\n", test(-1));

    printf("%d\n", testfun(8, 9));
    return 0;

}
