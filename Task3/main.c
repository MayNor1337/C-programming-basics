#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int **visit;
int **adjacencyMatrix;
char a[10000][10000];

void bin_print(unsigned n) {
    if ( n ) {
        bin_print(n >> 1);
        printf("%u", n & 1);
    }
}

void preset(int n);
bool graphTraversal(int startX, int startY, int finishX, int finishY);

int main()
{
    int n;
    char temp;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%c", &a[i][j]);
            scanf("%c", &temp);
        }
    }

    preset(n);

    int startX, startY, finishX, finishY;
    scanf("%d", &startX);
    scanf("%d", &startY);
    scanf("%d", &finishX);
    scanf("%d", &finishY);

    graphTraversal(startX, startY, finishX, finishY);
    for(int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}

void preset(int n)
{
    visit = (int**) malloc((n + 2) * sizeof(int*));
    adjacencyMatrix = (int**) malloc((n + 2) * sizeof(int*));
    for(int i = 1; i <= n; i++)
    {
        visit[i] = (int *) malloc((n + 2) * sizeof(int));
        adjacencyMatrix[i] = (int *) malloc((n + 2) * sizeof(int));
        for(int j = 1; j <= n; j++)
        {
            visit[i][j] = 0;
            adjacencyMatrix[i][j] = 0;
        }
    }
    for(int i = 0; i <= n + 1; i++)
    {
        a[0][i] = '#';
        a[i][0] = '#';
        a[n + 1][i] = '#';
        a[i][n + 1] = '#';
    }
}

bool graphTraversal(int nowX, int nowY, int finishX, int finishY)
{
    if(nowX == finishX && nowY == finishY)
    {
        printf("%d %d\n", nowX, nowY);
        return true;
    }
    //printf("now is (%d, %d)\n", nowX, nowY);
    visit[nowX][nowY] = 1;
    if(a[nowX - 1][nowY] == '*' && visit[nowX - 1][nowY] != 1)
    {
        if (graphTraversal(nowX - 1, nowY, finishX, finishY))
        {
            printf("%d %d\n", nowX, nowY);
            return true;
        }
    }
    if(a[nowX + 1][nowY] == '*' && visit[nowX + 1][nowY] != 1)
    {
        if(graphTraversal(nowX + 1, nowY, finishX, finishY))
        {
            printf("%d %d\n", nowX, nowY);
            return true;
        }

    }
    if(a[nowX][nowY - 1] == '*' && visit[nowX][nowY - 1] != 1)
    {
        if(graphTraversal(nowX, nowY - 1, finishX, finishY))
        {
            printf("%d %d\n", nowX, nowY);
            return true;
        }
    }
    if(a[nowX][nowY + 1] == '*' && visit[nowX][nowY + 1] != 1)
    {
        if(graphTraversal(nowX, nowY + 1, finishX, finishY))
        {
            printf("%d %d\n", nowX, nowY);
            return true;
        }
    }
    return false;
}
