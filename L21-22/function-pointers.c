#include <stdio.h>

void hello(void)
{
    printf("Hello!\n");
}

void baubau(void)
{
    printf("Bau Bau\n");
}

void call_n_times(int n, void (*x)(void))
{
    // ++n pre operation, n++ post operation
    while (n--)
    {
        x();
    }
}

int main(void)
{
    // function pointer
    int (*myf)(void);

    myf = main;

    // function name is a pointer in c
    printf("%p\n", main);
    printf("%p\n", myf);

    // loop infinito - main into main
    // myf();

    // -----------------------

    void (*x)(void);

    call_n_times(10, hello);
    call_n_times(10, baubau);

    return 0;
}