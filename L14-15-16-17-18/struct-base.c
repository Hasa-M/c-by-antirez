#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Internal layout:
 * +----+----+----+
 * |num |den ||c   |
 * +----+----+----+ 
 * struct must be aligned to its type max size
 */
struct fract {
    int num;
    int den;
    unsigned char color;
};

/* creating a new fraction, setting num and den as the numerator
 * and denominator of the fraction.
 * The fraction return NULL on out of memory otherwise
 * the fraction object is returned 
 * Note: Returning the struct by value and not pointer cause memory copy in the assegnation
 * moment, so it is highly raccomended to use a pointer for returning stuct */
struct fract *create_fraction(int num, int den) {
    struct fract *f = malloc(sizeof(*f));
    if (f == NULL) return NULL; // malloc error checking
    f->num = num;
    f->den = den;
    return f;
}

/* Simplify the provided fraction */
void simplify_fraction(struct fract *f) {
    for (int d = 2; d <= f->num && d <= f->den; d++ ) {
        while (f->num % d == 0 && f->den % d == 0) {
            f->num /= d;
            f->den /= d;
        }
    }
}

void print_fraction(struct fract *f) {
    printf("%d/%d\n", f->num, f->den);
}

int main (void) {
    printf("%d\n", (int)sizeof(struct fract)); // 12

    struct fract a; // class concept
    struct fract *b = &a;
    b->num = 1;
    a.den = 2;
    printf("%d/%d\n", a.num, a.den);

    struct fract *f1 = create_fraction(10,20);
    struct fract *f2 = create_fraction(3,4);
    simplify_fraction(f1);
    simplify_fraction(f2);
    print_fraction(f1);
    print_fraction(f2);
    return 0;
}
