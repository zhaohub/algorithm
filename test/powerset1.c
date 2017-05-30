#include <stdio.h>
#include <malloc.h>

void power_set(int i, char *src, char *item, int len)
{
    char *str_tmp = (char *)malloc(sizeof(char) * len);
    //char * str_tmp;
    if(i >= len)
    {
        printf("{%s}\n", item);
    }
    else
    {
        strncpy(str_tmp, src, i + 1);
        printf("-----1--%s", str_tmp);
        power_set(i + 1, src, str_tmp, len);
        memset(str_tmp, 0, sizeof(str_tmp));
        strncpy(str_tmp, src, i);
        printf("-----2--%s", str_tmp);
        power_set(i + 1, src, str_tmp, len);
    }
}

void main(void)
{
    char *str = "abcd";
    power_set(0, str, "", 4);
}
