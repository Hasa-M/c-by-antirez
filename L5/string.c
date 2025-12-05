#include <stdio.h>

int main(void)
{
    char c = 'A'; // intero di tipo carattere, può contenere solo un carattere singolo, il numero è la posizione di quel carattere in ascii
    printf("Hello World %d \n", c);
    printf("[%s]\n", "Hello World");
    printf("[%c]\n", 65);

    // --- Array -----
    int a[5] = {10, 5, 50, 100, 7};
    char s[6] = {'H', 'e', 'l', 'l', 'o', 0};

    printf("%d\n", a[0]);
    printf("%s\n", s);

    int i = 0;
    while (s[i] != 0)
    {
        printf("%c", s[i]);
        i++;
    }
    printf("\n");

    char str[] = "hello";
    str[3] = 'X';
    str[1] = 65;
    printf("%s\n", str);
    printf("%lu\n", sizeof(str)); // sizeof non viene eseguito a runtime ma a compile time

    return 0;
}