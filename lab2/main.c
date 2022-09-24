#include <stdio.h>
#include <math.h>

int main() {
    float z1 = 0, z2 = 0;
    float a;

    scanf("%f", &a);

    z1 = cos(a) + sin(a) + cos(3.0 * a) + sin(3.0 * a);
    z2 = 2.0 * sqrt(2.0) * sin(M_PI  + 2.0 * a);

    printf("%f\n", z1);
    printf("%f", z2);

    return 0;
}
