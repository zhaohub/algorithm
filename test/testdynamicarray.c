#include <stdio.h>
#include <stdlib.h>

#include "../include/dynamic_array.h"

int main(int argc, char *argv[])
{
    dynamic_array *array = create(5);
    //printf("%s------",argv[1]);
    int num = atoi(argv[1]);
    int i = 0;
    for(; i < num; i++)
    {
        push_back(&array, i);
    }
    for(i = 0; i < array->size; i++)
    {
        printf("%d\t", array->data[i]);
    }
    free(array);
    return 0;
}