#include <iostream>
#include <cmath>

#include "include/point2d.hpp"

namespace geo {

Point2D::Point2D() : _x(0), _y(0), _z(0) { }

Point2D::Point2D(float x, float y, float z) : _x(x), _y(y), _z(z) { }

float Point2D::distanceTo(const Point2D& other) const {
    float dx = _x - other._x;
    float dy = _y - other._y;
    float dz = _z - other._z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

Point2D Point2D::operator+(const Point2D inp)
{
    Point2D out;
    out.SetX( this->_x + inp.GetX() );
    out.SetY( this->_y + inp.GetY() );
    out.SetZ( this->_z + inp.GetZ() );
    return out;
}

Point2D Point2D::operator-(const Point2D inp)
{
    Point2D out;
    out.SetX( this->_x - inp.GetX() );
    out.SetY( this->_y - inp.GetY() );
    out.SetZ( this->_z - inp.GetZ() );
    return out;
}

Point2D Point2D::operator*(const Point2D inp)
{
    Point2D out;
    out.SetX( this->_x * inp.GetX() );
    out.SetY( this->_y * inp.GetY() );
    out.SetZ( this->_z * inp.GetZ() );
    return out;
}

} // namespace geo
