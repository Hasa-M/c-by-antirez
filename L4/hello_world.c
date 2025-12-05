#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void clear(void)
{
    printf("\x1b[H");
}

int main()
{
    char c = 1;      // 8 bit, 1 byte - carattere, rappresenta le stringhe
    short s = 2000;  // 16 bit, 2 byte - intero corto
    int x = 5;       // 32bit, 4 byte - intero
    long l = 300000; // grandezza della parola del microprocessore, quindi 64 o 32 bit, 8 o 4 byte - intero lungo

    uint64_t big = 1234567890123456789ULL; // intero senza segno a 64 bit - matematica modulare
    int64_t sbig = -1234567890123456789LL; // intero con segno a 64 bit
    size_t size = sizeof(big);             // tipo intero senza segno per rappresentare la dimensione in byte di un oggetto

    intptr_t ptr_value = (intptr_t)&x;    // tipo intero capace di contenere un puntatore
    uintptr_t uptr_value = (uintptr_t)&x; // tipo intero senza segno capace di contenere un puntatore

    clear();
    printf("Hello World: int is %lu bytes\n", sizeof(x));
    printf("Hello World: int min %d int max %d\n", INT_MIN, INT_MAX);
    printf("Hello World: long is %lu bytes\n", sizeof(l));

    return 0;
}