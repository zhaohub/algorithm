#include <stdio.h>
#include <stdlib.h>

typedef int element_type;

typedef struct dynamic_array_tag
{

    unsigned int size;
    unsigned int capacity;
    element_type data[1];
} dynamic_array;

dynamic_array *create(unsigned int sz)
{
    if(!sz) sz = 1;
    unsigned int no_of_bytes = sizeof(dynamic_array) + sizeof(element_type) * (sz - 1);
    dynamic_array *array = (dynamic_array *)malloc(no_of_bytes);

    if(array)
    {
        array->size = 0;
        array->capacity = sz;
    }
    return array;
}

void push_back(dynamic_array **pp, element_type e)
{
    if(pp && *pp)
    {
        if((*pp)->size == (*pp)->capacity)
        {
            unsigned int no_of_bytes = sizeof(dynamic_array) + sizeof(element_type) * ((*pp)->capacity * 2 - 1);
            *pp = (dynamic_array *)realloc(*pp, no_of_bytes);
            if(*pp)
            {
                (*pp)->capacity *= 2;
            }
        }
        if(*pp)
        {
            (*pp)->data[(*pp)->size] = e;
            ++(*pp)->size;
        }
    }

}

void main(void)
{
    dynamic_array *p = create(4);
    int i = 0;
    if(p)
    {
        for(i = 0; i < 3200; ++i)
        {
            push_back(&p, i);
        }
    }
    //printf("-------%d------",p->size);
    if(p)
    {
        for(i = 0; i < p->size; ++i)
        {
            printf("%d\n", p->data[i]);
        }
    }

    free(p);
}

