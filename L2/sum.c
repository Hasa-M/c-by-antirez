#include <stdio.h>

int sum(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main(void)
{
    int a = 10;
    int b = 20;
    int c = a + b;

    printf("The sum is: %d %d\n", sum(10, 20), c);
    return 0;
}