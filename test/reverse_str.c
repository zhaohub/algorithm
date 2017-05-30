#include <stdio.h>

void re_str(char str[])
{
    int i;
    char tmp;
    int len = strlen(str);
    for(i = 0; i < len / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }

}

void main(void)
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    printf("origin string is---%s\n", str);
    re_str(str);
    printf("reverse string is---%s\n", str);
}

