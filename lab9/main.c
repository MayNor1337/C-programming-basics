#include <stdio.h>

int main() {
    //#2
    printf("Input count calls\n");
    int n;
    int sumCalls = 0;
    scanf("%d", &n);
    int calls[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &calls[i]);
        sumCalls += calls[i];
    }

    printf("Input price for month\n");
    float priceMonth;
    scanf("%f", &priceMonth);

    printf("Input price for minut\n");
    float price;
    scanf("%f", &price);

    if (priceMonth / 499.0 - price > 0.00001) {
        printf("durak\n");
    } else if (sumCalls - 499.0 <= 0.00001) {
        printf("%f\n", priceMonth);
    } else printf("%f\n", priceMonth + (sumCalls - 499.0) * price);

    long double sum;
    long double present;
    int month;

    printf("Input sum\n");
    scanf("%Lf", &sum);
    printf("Input present\n");
    scanf("%Lf", &present);
    printf("Input month\n");
    scanf("%d", &month);

    for(int i = 0; i < month; i++)
    {
        sum *= 1.0 + present / 100;
        printf("%Lf\n", sum);
    }

    return 0;
}
