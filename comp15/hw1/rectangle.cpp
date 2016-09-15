// FILE: rectangle.cpp
// CLASS: rectangle
//
// Name: James McCants
// Date: 1/20/14

#include <iostream>
#include "rectangle.h"

using namespace std;

rectangle::rectangle()
{
        width = 1;
        height = 1;
}

rectangle::rectangle(float side)
{
        width = side;
        height = side;
}

rectangle::rectangle(float w, float h)
{
        width = w;
        height = h;
}

float rectangle::getWidth()
{
        return width;
}

float rectangle::getHeight()
{
        return height;
}

void rectangle::setWidth(float w)
{
        width = w;
}

void rectangle::setHeight(float h)
{
        height = h;
}

float rectangle::perimeter()
{
        return (2 * width) + (2 * height);
}

float rectangle::area()
{
        return (width * height);
}

bool rectangle::isSquare()
{
        return (width == height);
}

