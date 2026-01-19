#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PLS_DEBUG = 1;

struct pls {
    uint32_t len;
    uint32_t refcount;
#ifdef PLS_DEBUG
    uint32_t magic; // se setto la macro PLS_DEBUG a 1 magic viene inserita nella pls
#endif
    char str[]; // C99 - puntatore ad offset 6 di tipo char con byte dinamici
};

char *ps_create(char *init, int len) {
    struct pls *p = malloc(sizeof(struct pls)+len+1);
    p->len = len;
    p->refcount = 1;
#ifdef PLS_DEBUG
    p->magic = 0xDEADBEEF;
#endif
    for (int j = 0; j < len; j++) {
        p->str[j] = init[j];
    }
    p->str[len] = 0;
    return p->str;
}

/* Display the string "s" on the screen */
void ps_print(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    for (int j = 0; j < (int)p->len; j++) {
        putchar(p->str[j]);
    }
    printf("\n");
}

/* Free previously created PS string */
void ps_free(char *s) {
    free(s-sizeof(struct pls));
}


void ps_validate(struct pls *p) {
#ifdef PLS_DEBUG
    if(p->magic != 0xDEADBEEF) {
        printf("INVALID STRING: Aborting\n");
        exit(1);
    }
#endif
}

/* Drop the reference count of the string object by one
 * and frees the object if the refcount reached 0 */
void ps_release(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    ps_validate(p);
    
    p->refcount--;
    if (p->refcount == 0) {
#ifdef PLS_DEBUG
        p->magic = 0;
#endif
        ps_free(s);
    }
}

/* Increase the reference count of the string object */
void ps_retain(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    if (p->refcount == 0) {
        printf("ABORTED ON RETAIN OF ILLEGAL STRING\n");
        exit(1);
    }
    p->refcount++;
}

/* Return the length of the string in 0(1) time */
uint32_t ps_len(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    return p->len;
}

char *global_string;

int main(void)
{
    char *mystr = ps_create("Hello World", 11);
    global_string = mystr;
    ps_retain(mystr);

    ps_print(mystr);
    printf("%s %d\n", mystr, (int)ps_len(mystr));

    ps_release(mystr);
    printf("%s\n", global_string);
    ps_release(global_string);
    ps_release(global_string);

    return 0;
}