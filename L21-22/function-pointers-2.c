#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare_integers(const void *a, const void *b) {
    const int *ap = a;
    const int *bp = b;
    if (ap[0] > bp[0]) return 1;
    else if (ap[0] < bp[0]) return -1;
    else return 0; 
}

int main(void) {
    int a[10];
    for (int j = 0; j <10; j++)
        a[j] = rand() & 15;
    
    a[2] = INT_MAX;
    a[5] = INT_MIN;
    qsort(a,10,sizeof(int), compare_integers);

    for (int j = 0; j < 10; j++)
        printf("%d ", a[j]);
    
    printf("\n");
    

    return 0;
}