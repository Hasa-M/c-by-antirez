#include <stdio.h>

// int x = 0;

void incrVoid(void) {
    // int x = 1;
    static int x = 0;
    x = x + 1;
    printf("X: %d\n", x);
}

int incrInt(int x) {
    x = x + 1;
    return x;
}

int main(void) {
    incrVoid(); // First call, x should be 1
    incrVoid(); // Second call, x should be 2
    incrVoid(); // Third call, x should be 3

    int a = 10;
    incrInt(a);
    printf("A: %d\n", a); // a should still be 10

    a = incrInt(a); // a = 11
    a = incrInt(a); // a = 12
    printf("A: %d\n", a);


    //-----types------
    float y = 1.234;
    char c = 128;
    printf("Y: %.3f - C: %c\n", y, c); // C -> -128

    char d = 127;
    int i = c+1;
    printf("I: %d\n", i); // I -> 128

    c++; // c = 128

    return 0;
}