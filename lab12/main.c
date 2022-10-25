#include <stdio.h>
#include <string.h>

int InNumber(char *string)
{
    int sum = 0;

    for(int i = 0; i < strlen(string); i++)
    {
        sum = sum * 10 + (string[i] - '0');
    }

    return sum;
}

int main(int argc, char * argv[])
{
    freopen("input.txt", "w", stdout);
    printf("%d", (InNumber(argv[1]) + InNumber(argv[2])));

    return 0;
}
