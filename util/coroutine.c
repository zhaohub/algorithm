#include <stdio.h>

int test(void);

int main(int argc, char *argv[])
{
    for(int j = 0; j < 10; j++)
    {
        printf("main %d\n", test());

    }

    return 0;
}


int test(void)
{
    static int state = 0;
    switch(state)
    {
    case 0:
        goto LABEL0;
    case 1:
        goto LABEL1;
    }

LABEL0:

    for(int i = 0; i < 10; i++)
    {
        state = 1;

        return i;
LABEL1:
        ;
    }

}