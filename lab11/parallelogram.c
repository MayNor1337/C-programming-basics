//
// Created by Egor on 24.10.2022.
//
#include "parallelogram.h"
#include <stdio.h>
#include <math.h>

void CalculatePerimeter(struct Parallelogram * this)
{
    this->length1 = sqrt((this->x0 - this->x1) * (this->x0 - this->x1) + (this->y0 - this->y1) * (this->y0 - this->y1));
    this->length2 = sqrt((this->x0 - this->x2) * (this->x0 - this->x2) + (this->y0 - this->y2) * (this->y0 - this->y2));
    this->perimeter = this->length1 * 2 + this->length2 * 2;
}

void CalculateSquare(struct Parallelogram * this)
{
    this->length1 = sqrt((this->x0 - this->x1) * (this->x0 - this->x1) + (this->y0 - this->y1) * (this->y0 - this->y1));
    this->length2 = sqrt((this->x0 - this->x2) * (this->x0 - this->x2) + (this->y0 - this->y2) * (this->y0 - this->y2));
    this->length3 = sqrt((this->x1 - this->x2) * (this->x1 - this->x2) + (this->y1 - this->y2) * (this->y1 - this->y2));
    double cos = (this->length1 * this-> length1 + this->length2 * this->length2 - this->length3 * this->length3)
                    / (2 * this->length1 * this-> length1 * this->length2 * this->length2);
    this->sin = 1 - cos * cos;
    this->square = this->length1 * this->length2 * this->sin;
}