#include <stdio.h>

void incr(int *p) {
    *p = *p + 1; // il contenuto dell'inrizzo p = contenuto indirizzo p +1
}

int main(void) {
    int x = 5;
    int *n = 0; // indirizzo nullo
    printf("X: %d\n", x);
    printf("%p\n", n);

    int *y = NULL;
    y = &x; /* &var prende il puntatore alla variabile
    * in questo caso è necessariamente in un indirizzo della mamoria
    * non in un registro */
    printf("x is stored at the address: %p\n", y);

    // y = 10; // y punta all'indirizzo di memoria .N.
    *y = 10; // scrivo 10 dentro l'indirizzo di memoria a cui punta y
    printf("X changed by pointer: %d\n", x);
    
    y[0] = 11; // equivalente a *y = 10,
    printf("X changed by pointer[array style]: %d\n", x);


    //-----esempio utilizzo puntatori-----
    int z = 5;
    printf("Z: %d\n", z);

    int *w = &z;
    incr(w);
    printf("Z post incr: %d\n", z);

    return 0;
}