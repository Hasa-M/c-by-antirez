#include <stdio.h>

// definizione di un tipo
typedef int myerrorcode;

typedef struct {
    int n;
    int d;
} fract;

typedef fract *fractptr;

int main(void) {
    fract f;
    fractptr fp = &f;
    f.n = 10;
    fp->d = 20;
    printf("%d/%d\n", fp->n, f.d);
}