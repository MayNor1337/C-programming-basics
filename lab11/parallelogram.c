//
// Created by Egor on 24.10.2022.
//
#include "parallelogram.h"
#include <stdio.h>
#include <math.h>

struct Point NewPoint(double x, double y)
{
    struct Point p = {x, y};
    return p;
}

struct Parallelogram NewParallelogram(double x0, double y0, double x1, double y1, double x2, double y2){
    struct Parallelogram p = {NewPoint(x0, y0), NewPoint(x1, y1), NewPoint(x2, y2), 0, 0, 0, 0, 0};
    return p;
}

double Pifagor(struct Point first, struct Point second)
{
    return sqrt((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}

void CalculatePerimeter(struct Parallelogram * this)
{
    this->firstLength = this->firstLength ?: Pifagor(this->firstPoint, this->secondPoint);
    this->secondLength = this->firstLength ?: Pifagor(this->firstPoint, this->thirdPoint);
    this->perimeter = this->perimeter ?: this->firstLength * 2 + this->secondLength * 2;
}

double CalcelateCosSqure(struct Parallelogram * this)
{
    return (this->firstLength * this-> firstLength + this->secondLength * this->secondLength - this->diagonal * this->diagonal)
           / (2 * this->firstLength * this-> firstLength * this->secondLength * this->secondLength);
}

void CalculateSquare(struct Parallelogram * this)
{
    this->firstLength = this->firstLength ?: Pifagor(this->firstPoint, this->secondPoint);
    this->secondLength = this->firstLength ?: Pifagor(this->firstPoint, this->thirdPoint);
    this->diagonal = this->diagonal ?: Pifagor(this->secondPoint, this->thirdPoint);
    double cosSquare = CalcelateCosSqure(this);
    double sin = sqrt(1 - cosSquare);
    this->square = this->square ?: this->firstLength * this->secondLength * sin;
}


