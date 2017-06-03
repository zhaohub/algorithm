#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H

typedef int  element_type;

typedef struct dynamic_array_tag
{
    unsigned int size;
    unsigned int capacity;
    element_type data[1];
} dynamic_array;


dynamic_array *create(unsigned int size);
void push_back(dynamic_array **pp, element_type item);

#endif