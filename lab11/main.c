#include <stdio.h>
#include "parallelogram.h"


int main() {
    printf("Enter the coordinates of the starting point, and then 2 coordinates of the points adjacent to this side\n");
    double x0, x1, x2;
    double y0, y1, y2;
    scanf("%lf", &x0);
    scanf("%lf", &y0);
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    scanf("%lf", &x2);
    scanf("%lf", &y2);

    struct Parallelogram s = {x0, y0, x1, y1, x2, y2};

    CalculatePerimeter(&s);
    CalculateSquare(&s);

    printf("Perimeter = %lf\n", s.perimeter);
    printf("Square = %lf", s.square);

    return 0;

}
