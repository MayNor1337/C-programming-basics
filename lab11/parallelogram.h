//
// Created by Egor on 24.10.2022.
//
#ifndef LAB11_PARALLELOGRAM_H
#define LAB11_PARALLELOGRAM_H

struct Parallelogram
{
    double x0;
    double y0;
    double x1;
    double y1;
    double x2;
    double y2;
    double length1;
    double length2;
    double length3;
    double sin;
    double perimeter;
    double square;
};

void CalculatePerimeter(struct Parallelogram * this);

void CalculateSquare(struct Parallelogram * this);

#endif LAB11_PARALLELOGRAM_H
