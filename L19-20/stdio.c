#include <stdio.h>
#include <unistd.h>

int main(void) {
    
    char *mystr = "Hello World";
    size_t len = strlen(mystr);
    for (size_t j = 0; j< len; j++){
        // STDOUT_FILENO is a macro (describe "macro" concept inside the readme)
        // write(STDOUT_FILENO, mystr+j, 1);

        putchar(mystr[j]);
        // putchar("\n");
        fflush(stdout);
        usleep(100000);
    }
    sleep(5);
    return 0;
} 