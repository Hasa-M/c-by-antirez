#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inversion of the file rows

// linked list
struct line {
    char *s;
    struct line *next;
};


// ./.a.out [filename]
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Missing file name\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    char buf[1024];
    struct line *head =NULL;
    while (fgets(buf,sizeof(buf),fp) != NULL) {
        struct line *l = malloc(sizeof(*l));
        size_t linelen = strlen(buf);
        l->s = malloc(linelen+1);
        for (int j = 0; j <= (int)linelen; j++) {
            l->s[j] = buf[j];
        }
        l->next = head;
        head = l;
    }

    fclose(fp);

    while (head != NULL)
    {
        printf("%s", head->s);
        head = head->next;
    }
    

    return 0;
}