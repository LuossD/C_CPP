#include <iostream>
#include "point.h"

using namespace std;

void Point2D::Print() const
{
    cout << "( " << _x << ", " << _y << " )";
}

void Point3D::Print() const
{
    cout << "( " << _x << ", " << _y << ", " << _z << " )";
}
