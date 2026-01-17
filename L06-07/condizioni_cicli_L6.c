#include <stdio.h>

void condizioniFn(void)
{
    int i = 5;

    if (i > 3)
    {
        printf("i > 3\n");
    }
    else
    {
        printf("i <= 3\n");
    }

    // se solo una istruzione non servono blocchi
    if (i > 3)
        printf("i > 3\n");
    else
        printf("i <= 3\n");

    // possibile mettere ovunque blocchi in c e il blocco ha una propria memoria locale
    int j = 8;
    {
        int j = 5;
        printf("j (%zu bytes) is %d, and stored at %p\n", sizeof(j), j, &j); // print 5
    }
    printf("j (%zu bytes) is %d, and stored at %p\n", sizeof(j), j, &j); // print 8
}

void gotoFn()
{
    int i = 0;

again:
    printf("Again Count i: %d\n", i);
    i++;
    if (i < 10)
        goto again;

    // con le etichette, esempio ciclo infinito;
    //  l10: printf("Ciao"");
    //  l20: goto l10;
}

void whileFn(void)
{
    // equivalente al gotoFn
    int i = 0;

    while (i < 10)
    {
        printf("While Count i: %d\n", i);
        i++;
    }

    // compilazione del while
    int j = 0;

loop:
    if (j < 10)
        goto enter_loop;
    goto next;
enter_loop:
    printf("Loop Count j: %d\n", j);
    j++;
    goto loop;
next:
    return;
}

void recursiveFnConta(int start, int end)
{
    // programmazione funzionale -> utilizza molta memoria di stack
    if (start > end)
        return;
    printf("Recursive Count: %d\n", start);
    recursiveFnConta(start + 1, end);
}

int main(void)
{
    condizioniFn();

    gotoFn();

    whileFn();

    recursiveFnConta(0, 9);

    return 0;
}