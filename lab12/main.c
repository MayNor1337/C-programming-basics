#include <stdio.h>
#include <string.h>

int InNumber(char *string)
{
    int sum = 0;
    int size = strlen(string);

    for(int i = 0; i < size; i++)
    {
        sum = sum * 10 + (string[i] - '0');
    }

    return sum;
}

int RowValidity(char *string)
{
    int size = strlen(string);

    for(int i = 0; i < size; i++)
    {
        if(string[i] > '9' || string[i] < '0')
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char * argv[])
{
    freopen("input.txt", "w", stdout);
    if(RowValidity(argv[1]) || RowValidity(argv[2]))
    {
        printf("incorrect input");
        return 0;
    }

    printf("%d", (InNumber(argv[1]) + InNumber(argv[2])));

    return 0;
}
