//
// Created by Egor on 24.10.2022.
//
#ifndef LAB11_PARALLELOGRAM_H
#define LAB11_PARALLELOGRAM_H
struct Point
{
    double x;
    double y;
};

struct Parallelogram
{
    struct Point firstPoint;
    struct Point secondPoint;
    struct Point thirdPoint;
    double firstLength;
    double secondLength;
    double diagonal;
    double perimeter;
    double square;
};

struct Point NewPoint(double x, double y);

struct Parallelogram NewParallelogram(double x0, double y0, double x1, double y1, double x2, double y2);

double CalcelateCosSqure(struct Parallelogram * this);

void CalculatePerimeter(struct Parallelogram * this);

void CalculateSquare(struct Parallelogram * this);

#endif LAB11_PARALLELOGRAM_H
