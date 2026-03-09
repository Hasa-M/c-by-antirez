#include <stdio.h>
#include <string.h>
#include <limits.h>

struct foo {
    // uso base: campi che non mi servono mai simultaneamente
    union {
        int i;
        unsigned char a[4];
    } u;
};

int main(void) {
    struct foo f ;

    f.u.i = INT_MAX;

    printf("%d [%d %d %d %d]\n", f.u.i, f.u.a[0], f.u.a[1], f.u.a[2], f.u.a[3]);

    return 0;    
}