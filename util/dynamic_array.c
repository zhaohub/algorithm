#include <stdio.h>
#include <stdlib.h>

#include "../include/dynamic_array.h"

dynamic_array *create(unsigned int size)
{
    if(!size) size = 1;
    unsigned int no_of_bytes = sizeof(dynamic_array) + sizeof(element_type) * (size - 1);
    dynamic_array *array = (dynamic_array *)malloc(no_of_bytes);
    if(array)
    {
        array->size = 0;
        array->capacity = size;
    }
    return array;
}

void push_back(dynamic_array **pp, element_type item)
{
    if(pp && *pp)
    {
        if((*pp)->size == (*pp)->capacity)
        {
            unsigned int no_of_bytes = sizeof(dynamic_array) + sizeof(element_type) * ((*pp)->size * 2 - 1);
            *pp = (dynamic_array *)realloc(*pp, no_of_bytes);
            if(*pp)
            {
                (*pp)->capacity *= 2;
            }
        }
        if(*pp)
        {
            (*pp)->data[(*pp)->size] = item;
            ++(*pp)->size;
        }
    }
}

