#include <iostream>
#include "point.h"

int main()
{
    Point * pt1 = new Point2D( 1, 2 );
    Point * pt2 = new Point3D( 1, 2, 3 );
    pt1->Print();
    pt2->Print();
    return 0;
}