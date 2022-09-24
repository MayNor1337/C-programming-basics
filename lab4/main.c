#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, g;
    char s[2][100] = {"Popalo", "Not Popalo"};
    scanf("%d", &a);
    bool b = true;

    for(int i = 33; i <= 55; i++)
    {
        b = b * (a - i);
    }

    printf("%s\n", s[b]);

    scanf("%d", &g);
    bool c = g & (1 << 14);
    printf("%d", c);
}
