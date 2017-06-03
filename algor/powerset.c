#include <stdio.h>
void power_set(char *src, char *dst, int i)
{
    int len = strlen(src);
    if(i > len - 1)
    {
        char *str_out = (char *)malloc(sizeof(char) * len);
        printf("{%s}\n", dst);
    }
    else
    {
        //char* str_tmp=(char*)malloc(sizeof(char)*len);
        //strncpy(str_tmp,src,i+1);
        dst[i] = src[i];
        power_set(src, dst, i + 1);
        dst[i] = '*';
        //str_tmp[i]='\0';
        //strncpy(str_tmp,src,i);
        power_set(src, dst, i + 1);
    }
}
void main(void)
{
    char *str = "abcdefg";
    char *dst = (char *)malloc(sizeof(char) * strlen(str));
    power_set(str, dst, 0);
}
