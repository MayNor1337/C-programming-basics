#include <stdio.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int (*a)[2], int l, int r)
{
    int v = a[(l + r) / 2][0];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (a[i][0] < v)
            i++;
        while (a[j][0] > v)
            j--;
        if (i >= j)
            break;
        swap(&a[i++][0], &a[j--][0]);
        swap(&a[i][1], &a[j][1]);
    }

    return j;
}

void Quicksort(int (*a)[2], int l, int r)
{
    if (l < r)
    {
        int q = Partition(a, l, r);
        Quicksort(a, l, q);
        Quicksort(a, q + 1, r);
    }
}

void Input(int (*a)[2], int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i][0]);
        scanf("%d", &a[i][1]);
    }
}

void Task(int (*a)[2], int n)
{

    int index = a[0][0];
    printf("%d ", index);
    for(int i = 0; i < n; i++)
    {
        if(index < a[i][0])
        {
            printf("%d\n", index);
            index = a[i][0];
            printf("%d ", index);
        }
        if(index < a[i][1])
            index = a[i][1];
    }
    printf("%d\n", index);
}

int main()
{
    int n, mix = 0;
    scanf("%d", &n);
    int a[n][2];

    Input(a, n);

    Quicksort(a, 0, n - 1);

    Task(a, n);
}