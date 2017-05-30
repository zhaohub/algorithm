#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *re_str(const char *str)
{
    int i;
    int len = strlen(str);
    char *des = (char *)malloc(sizeof(char) * (len + 1));
    for(i = 0; i < len / 2 + 1; i++)
    {
        des[i] = str[len - 1 - i];
        des[len - 1 - i] = str[i];
    }
    return des;
}
int main(void)
{
    char *str = "abcdefghigklmnopqrst";
    printf("origin string is---%s\n", str);
    printf("reverse string is---%s\n", re_str(str));
    return 0;
}

