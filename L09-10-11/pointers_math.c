#include <stdio.h>

/* accddere ad un valore tramite il suo indirizzo
 * di memoria è detto Deferenziazione */
void def_methods_incr(int *p)
{
    printf("Before incr: %d\n", *p);
    p[0] = p[0] + 1;
}

int main(void)
{

    int x = 5;
    int *y = &x;
    printf("x is stored in %p and is %d\n", y, x);

    int **z = &y;
    printf("x is stored in %p and y is stored in %p\n", y, z);
    printf("sizeof y %d, sizeof z %d\n", (int)sizeof(y), (int)sizeof(z)); // casting del sizeof a intero ad intero

    // -----------------
    char mystr[] = "Hello World";
    char *p = mystr;

    printf("At %p I can see: %s\n", mystr, mystr);

    printf("%c %c\n", p[2], *(p + 2)); // l l

    //------------------

    char *strPtr = mystr;

    printf("A the the beginning the string Pts is: %p\n", strPtr);
    while (*strPtr != 0)
    {
        putchar(*strPtr);
        strPtr++;
    }
    printf("\n");
    printf("A the the end the string Pts is: %p\n", strPtr);

    //-----------------
    /* Nel min 18 viene inserito un puntatore short su un "array" di tipo char.
     *  Mentre è stata allocata memoria per essere acceduta ad un byte verrà
     * acceduta a 2 byte con quel puntatore. Si legge in memoria 0x41 0x41 anzichè 0x41 e
     * stampa 16705 al posto di 65 - ...  01000001 01000001 .... -
     * di conseguenza incrementando di 1 il puntaotre avremo un
     * incremento reale di 16 bit e non 8 bit. Quindi il nostro nuovo
     * puntatore incrementato punterà a 0x42 0x42 - BB e non più AA
     * stampando quindi in decimale 16962, tra virgolette di seguito il
     * numero preso dalla memoria  ... 01000001 01000001 "01000010 01000010" ... */
    char str[] = "AABBCCDDEEFF";

    short *ptr = (short *)str;

    printf("First Ptr: %d\n", *ptr);

    ptr++;

    printf("After one add Ptr: %d\n", *ptr);

    //---------Prefix length string----------
    // p[0] è 15 in ottale
    char str1[] = "\017Hello00\0000000123";

    // facendo *p++ avrei dereferenziato il puntatore a aggiunto +1 a AA
    // ogni asterisco aggiunto è fondamentalmente un "go to pointed value"
    char *p1 = str1;
    printf("My string len is: %d\n", *p1);

    int len = *p1++;
    for (int j = 0; j < len; j++)
    {
        putchar(p1[j]);
    }
    printf("\n");

    return 0;
}