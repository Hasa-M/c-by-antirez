#include <stdio.h>
#include <stdlib.h>


/* +-+------------\\\
 * |L|My string here
 * +-+------------\\\
 * where L is one unsigned byte stating the string lenght.
 * Thus this string are binary safe: zero bytes are permitted in the middle */
char *ps_create(char *init, int len) {
    char *s = malloc(1+len+1); // string  1+ len + 1, first byte for the len byte (the first one) and last one for the 0
    unsigned char *lenptr = (unsigned char*)s; // len pointer
    *lenptr = len;
    for (int j = 0; j < len; j++) {
        s[j+1] = init[j];
    }
    s[len+1] = 0;
    return s;
}

/* Return the pointer to the null terminated C
 * string embedded inside our PS string 's' */
char *ps_get_c(char *s){
    return s+1;
}


int main(void)
{
    char *mystr = ps_create("Hello World", 11);

    printf("%s\n", ps_get_c(mystr));
    
    free(mystr);

    return 0;
}