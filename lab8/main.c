#include <stdio.h>
#include <io.h>
#include <math.h>

void sum(char *c, char *a, char *b)
{
    int size = strlen(a);

    for(int i = 0; i < strlen(a); i++)
    {
        c[i] = a[i];
    }

    for(int i = 0; i <= strlen(b); i++)
    {
        c[size + i] = b[i];
    }
}

int sravn(char *a, char *b, int n)
{
    int flag = 1;

    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main() {
    char a[1000], b[1000];
    char ans[2][15] = {"Various", "Are the same"};
    scanf("%s", &a);
    scanf("%s", &b);

    //#1
    int len = strlen(a) + strlen(b) + 1;
    char sumStr[len];
    sum(&sumStr, &a, &b);
    printf("%s\n", sumStr);

    //#4
    int n;
    scanf("%d", &n);
    n = fmin(n, fmin(strlen(a), strlen(b)));
    printf("%s", ans[sravn(&a, &b, n)]);

    //#7
    scanf("%s", &a);
    printf("%d", strlen(a));

    //#10
    //--

    //#12
    int ch = 0;
    scanf("%s", &a);
    scanf("%s", &b);
    for(int i = 0; i < strlen(a); i++)
    {
        int temp = 1;
        for(int j = 0; j < strlen(b); j++)
        {
            if(a[i] == b[j])
            {
                temp = 0;
                break;
            }
        }
        if(temp)
        {
            ch++;
        }
        else
        {
            printf("%d\n", ch);
            ch = 0;
        }
    }

    return 0;
}
