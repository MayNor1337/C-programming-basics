#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double** GetDistance(int **a, int n)
{
    double **b;
    int size = n - 1;
    b = (double **) malloc(n * sizeof (double *));
    for(int i = 0; i < n; i++)
    {
        int index = 0;
        int deltaIndex = 0;
        b[i] = (double *) malloc(size * sizeof (double));
        while(index + deltaIndex < size)
        {
            if(index == i)
            {
                deltaIndex = -1;
            }
            else
            {
                b[i][index + deltaIndex] = sqrt((a[i][0] - a[index][0]) * (a[i][0] - a[index][0]) + (a[i][1] - a[index][1]) * (a[i][1] - a[index][1]));
            }
            index++;
        }
    }
    return b;
}

int rec(int k)
{
    if(k == 0)
    {
        return 0;
    }
    return (k % 10) + rec(k / 10);
}


int main() {
//#2
    int n;
    scanf("%d", &n);
    int **a;
    a = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
    {
        a[i] = (int*) malloc(2 * sizeof (int));
        scanf("%d", &a[i][0]);
        scanf("%d", &a[i][1]);
    }
    double **distance = GetDistance(a, n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            printf("%f ", distance[i][j]);
        }
        printf("\n");
    }
    //#4
    int k;
    scanf("%d", &k);
    int sum = rec(k);
    printf("%d", sum);
    return 0;
}