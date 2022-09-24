#include <stdio.h>
#include <stdlib.h>

int main() {
    //#1
    char a[5];
    a[0] = 'H';
    a[1] = 'e';
    a[2] = 'l';
    a[3] = 'l';
    a[4] = 'o';

    for(char *ptr = a; ptr <= &a[4]; ptr++)
    {
        printf("%p : %c\n", ptr, *ptr);
    }

    //#2
    char *block;
    block = malloc(5 * sizeof(char));

    block[0] = 'H';
    block[1] = 'e';
    block[2] = 'l';
    block[3] = 'l';
    block[4] = 'o';

    for(int  i = 0; i < 5; i++)
    {
        printf("%d : %c\n", i, block[i]);
    }

    free(block);
}
