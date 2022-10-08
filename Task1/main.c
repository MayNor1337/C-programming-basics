#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int _sum[1000];
int _range = 0;

char* ReadString(char *string);
int CmpVer(char *v1, char *v2);
int InNumber(char *string);
int CountSymbol(char *string, char symbol);
void VersionArray(char *string);

int main() {
    char *a = NULL, *b = NULL;

    a = ReadString(a);
    b = ReadString(b);

    printf("%d", CmpVer(a, b));

    return 0;
}

char* ReadString(char *string)
{
    char symbol;
    int len = 2;
    int filledLen = 0;

    string = (char*) malloc(len);

    while((symbol = getchar()) != '\n')
    {
        if(len <= filledLen + 1)
        {
            len *= 2;
            string = (char*) realloc(string, len);
        }
        string[filledLen] = symbol;
        filledLen++;
    }

    string[filledLen] = '\0';
    return string;
}

int CmpVer(char *v1, char *v2)
{
    VersionArray(v1);
    int array1[_range];
    int range1 = _range;

    for(int i = 0; i < _range; i++)
    {
        array1[i] = _sum[i];
    }

    VersionArray(v2);
    int array2[_range];
    int range2 = _range;

    for(int i = 0; i < _range; i++)
    {
        array2[i] = _sum[i];
    }

    int i = 0;
    while(i < range1 && i < range2)
    {
        if(array1[i] > array2[i])
            return 1;
        if(array1[i] < array2[i])
            return -1;
        i++;
    }
    if(i == range1 && i != range2)
    {
        return -1;
    }
    if(i != range1 && i == range2)
    {
        return 1;
    }

    return 0;
}

int CountSymbol(char *string, char symbol)
{
    int count = 0;

    for(int i = 0; i < strlen(string); i++)
        if(string[i] == symbol)
            count++;

    return count;
}

int InNumber(char *string)
{
    int sum = 0;

    for(int i = 0; i < strlen(string); i++)
    {
        sum = sum * 10 + (string[i] - '0');
    }

    return sum;
}

void VersionArray(char *string)
{
    int len = CountSymbol(string, '.');
    int j = 0;

    for(int i = 0; i <= len; i++)
    {
        char temp[100];

        int dj = 0;
        while(string[j] != '.' && j < strlen(string))
        {
            temp[dj] = string[j];
            j++;
            dj++;
        }
        temp[dj] = '\0';
        j++;

        _sum[i] = InNumber(temp);
    }
    _range = len + 1;
}