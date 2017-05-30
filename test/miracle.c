#include <stdio.h>

int miracle(unsigned int n)
{
    int m = n == 0 ? 0 : 1;
    while(n = (n & (n - 1)))
    {
        m++;
    }
    return m;
}

int main(int argc, char *argv[])
{
    int a = miracle(atoi(argv[1]));
    printf("%d\n", a);
    return 0;
}
