#ifndef _STRING_H
#define _STRING_H

static inline reverse(char str[])
{
    char temp;
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}


#endif