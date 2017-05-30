#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //char name[8];
    //printf("Please input your name:");
    //gets(name);
    //printf("Hello %s !\n",name);

    char *s1 = "abcdefg";
    char *s2 = (char *)malloc(sizeof(char) * strlen(s1));
    memcpy(s2, s1, 9);
    printf("%s\n%s\n", s1, s2);
    printf("%x\n%x\n", (unsigned int)s1, (unsigned int)s2);
    return 0;
}
