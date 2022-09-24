#include <stdio.h>

int main() {
    int a[9] = {12, 13, 14, 15, 16, 17, 18, 19, 20};

    for(int i = 0; i < 9; i++)
    {
        printf("%d : %d\n", i, a[i]);
    }
    printf("\n");

    int m1[2][2] = {1, 1, 0,1}, m2[2][2] = {2, 0, 3, 0};
    int c[2][2];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int temp = 0;
            for(int x = 0; x < 2; x++)
            {
                    temp += m1[i][x] * m2[x][j];
            }
            c[i][j] = temp;
        }
    }

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}