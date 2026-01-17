#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* +-+------------\\\
 * |LLLL|My string here\0
 * +-+------------\\\
 * where L is one unsigned byte stating the string length.
 * Thus this string are binary safe: zero bytes are permitted in the middle */
char *ps_create(char *init, int len) {
    char *s = malloc(4+len+1); // string  1+ len + 1, first byte for the len byte (the first one) and last one for the 0
    uint32_t *lenptr = (uint32_t*)s; // len pointer
    *lenptr = len;

    s += 4;
    for (int j = 0; j < len; j++) {
        s[j] = init[j]; // We should use memcpy() here
    }
    s[len] = 0;
    return s;
}

/* Display the string "s" on the screen */
void ps_print(char *s) {
    uint32_t *lenptr = (uint32_t*)(s-4);
    for (uint16_t j = 0; j < *lenptr; j++) {
        putchar(s[j]);
    }
    printf("\n");
}

/* Free previously created PS string */
void ps_free(char *s) {
    free(s-4);
}

/* Return the length of the string in 0(1) time */
uint32_t ps_len(char *s) {
    uint32_t *lenptr = (uint32_t*)(s-4);
    return *lenptr;
}

int main(void)
{
    char *mystr = ps_create("Hello World", 11);

    ps_print(mystr);

    printf("%s %d\n", mystr, (int)ps_len(mystr));

    ps_free(mystr);

    return 0;
}