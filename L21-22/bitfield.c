#include <stdio.h>
#include <string.h>
#include <limits.h>
struct foo {
    // specifica di quanti bit devono essere le variabili
    unsigned char a:4;
    unsigned char b:4;
    unsigned char c:8;
};

int main(void) {
    struct foo f;

    printf("%d %d %d\n", f.a, f.b, f.c);
    
    return 0;
}