// introduced to make us realize that it is uncomfortable and to give as a first incipit of the struct
#include <stdio.h>

char *global_string;

/* +-+------------\\\
 * |LLLL|CCCC|My string here\0
 * +-+------------\\\
 * where L is one unsigned byte stating the string length and C the reference count */
int main(void)
{
    int len = 11;

    char *mystr = malloc(4+4+len+1);

    global_string = mystr;

    ps_free(mystr);

    return 0;
}