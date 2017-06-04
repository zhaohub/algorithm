#include "../include/coroutine.h"

#include <stdio.h>
#include <stdlib.h>

int cofunc1(void)
{
    static int i = 0;
    crBegin;
    for(; ; i++)
    {
        if(i % 3 == 0)
        {
            printf("cofunc1---- %d\n", i);
            crReturn(i);
        }
    }
    crFinish;
    return 0;
}


int cofunc2(void)
{
    static int i = 0;
    crBegin;
    for(; ; i++)
    {
        if(i % 7 == 0)
        {
            printf("cofunc2~~~~ %d\n", i);
            crReturn(i);
        }
    }

    crFinish;
    return 0;
}


int main(int argc, char *argv[])
{
    int i = 0;
    while(i++ < 100000)
    {
        time_t *t = (time_t *)malloc(sizeof(time_t));
        cofunc1();
        cofunc2();
        free(t);
    }
    return 0;
}