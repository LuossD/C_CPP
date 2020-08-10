#ifndef _POIINT_H
#define _POIINT_H

#include <iostream>
using namespace std;

class Point
{
public: 
    Point() { }
    virtual void Print() const = 0;
    // virtual ~Point();
};

class Point2D : virtual public Point
{
public: 
    Point2D( int x = 0, int y = 0 ) : _x(x), _y(y) { }
    Point2D( const Point2D& pt2d ) : _x(pt2d._x), _y(pt2d._y) { }
    int GetX() const { return _x; }
    void SetX( int x ) { _x = x; }
    int GetY() const { return _y; }
    void SetY( int y ) { _y = y; }
    virtual void Print() const;
protected:
    int _x, _y;
};

class Point3D: virtual public Point2D
{
public:
    Point3D( int x = 0, int y = 0, int z = 0 ) : Point2D(x,y), _z(z) { }
    Point3D( const Point3D& pt3d ) : Point2D(pt3d), _z(pt3d._z) { }
    int GetZ() const { return _z; }
    void SetZ( int z ) { _z = z; }
    virtual void Print() const;
protected:
    int _z;
};

#endif