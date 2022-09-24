#include <stdio.h>

int main() {
    int a;
    //#1
    scanf("%u", &a);

    //#2
    printf("%o\n", a);

    //#3
    printf("%x %x\n", a, a >> 2);

    //#4
    printf("%x %x\n", a, ~a);

    int b;
    //#5
    scanf("%x", &b);
    char c = b & a;
    printf("%x", c);
}
