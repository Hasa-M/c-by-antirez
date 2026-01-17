// prefixed lenght strings, useful for malloc introduction
#include <stdio.h>

/* Initialize a prefixed length string with
 * the specified string in "init" of lenght "len" 
 * Warning: this function does not check for buffer overflows */
void ps_init(char *s, char *init, int len) {
    unsigned char *lenptr = (unsigned char*)s; // len pointer
    *lenptr = len;
    for (int j = 0; j < len; j++) {
        s[j+1] = init[j];
    }
}

/* Display the string "s" on the screen */
void ps_print(char *s) {
    unsigned char *lenptr = (unsigned char*)s;
    for (int j = 0; j < *lenptr; j++) {
        putchar(s[j+1]);
    }
    printf("\n");
}

int main(void)
{
    char buf[256];

    ps_init(buf, "Hello World", 11);

    ps_print(buf);
    ps_print(buf);

    return 0;
}