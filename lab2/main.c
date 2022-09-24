#include <stdio.h>
#include <math.h>

double z1(double a)
{
    return cos(a) + sin(a) + cos(3.0 * a) + sin(3.0 * a);
}

double z2(double a)
{
    return 2.0 * sqrt(2.0) * sin(M_PI  + 2.0 * a);
}

int main() {
    double a;
    scanf("%lf", &a);

    printf("%f\n", z1(a));
    printf("%f", z2(a));

    return 0;
}
