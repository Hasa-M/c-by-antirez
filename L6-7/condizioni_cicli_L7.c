#include <stdio.h>

void tailCallConta(int start, int end)
{
    if (start > end)
        return;
    printf("Tail Call Counter: %d, with pointer %p\n", start, &start);
    tailCallConta(start + 1, end);
}

void tailCallOptimizationConta(int start, int end)
{
    // modificare una ricorsione per farla diventare iterazione
    // utilizzabile solo se Conta è una funzione di coda
    // non: f(conta(start, end), ...)
iterate:
    if (start > end)
        return;
    printf("TCO Counter: %d, with pointer %p\n", start, &start);
    start = start + 1;
    goto iterate;
}

void whileFn(void)
{
    int i = 0;
    while (i < 10)
    {
        printf("While: %d\n", i);
        i++;
    }

    // while(1) - aka while true - è un ciclo infinito
}

void forFn(void)
{
    int i = 0;
    for (; i < 10; i++)
    {
        printf("For 1: %d\n", i);
    }
    printf(">> %d", i);

    for (int i = 0; i < 10; i++)
    {
        printf("For 2: %d\n", i);
    }

    for (int i = 0;; i++)
    {
        if (i >= 10)
            break; // il break rompe il ciclo - esce dal ciclo
        printf("For 3: %d\n", i);
    }

    for (int i = 0;;)
    {
        if (i >= 10)
            break;
        printf("For 4: %d\n", i);
        i++;
    }

    //---------------
    int a[] = {1, 5, 8, 4, 9, 0};
    int j;
    for (j = 0; a[j] != 0; j++)
    {
        if (a[j] == 8)
            break;
    }
    if (a[j] == 0)
    {
        printf("Non trovato\n");
    }
    else
    {
        printf("Trovato, in posizione %d\n", j);
    }
}

void doWhileFn(void)
{
    int i = 0;
    do
    {
        printf("Do While: %d\n", i);
        i++;
    } while (i < 10);
}

void switchFn(int i)
{
    // senza il break si passa anche alle istruzioni del case successivo
    switch (i)
    {
    case 5:
    {
        char* s = "sei";
        printf("Cinque e poi %s\n", s);
        break;
    }
    case 7:
        printf("Sette\n");
        break;
    default:
        printf("Not 5 or 7\n");
        break;
    }
}

int main(void)
{

    tailCallConta(0, 9);
    tailCallOptimizationConta(0, 9);

    whileFn();

    forFn();

    doWhileFn();

    switchFn(5);

    return 0;
}