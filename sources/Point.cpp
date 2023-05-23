#include "Point.hpp"
namespace ariel
{
    Point::Point(double x, double y) : _x(x), _y(y) {}
    Point::Point(const Point &p) : _x(p._x), _y(p._y) {}
    Point::~Point() {}
    double Point::getX() { return this->_x; }
    double Point::getY() { return this->_y; }
    void Point::setX(double _x) { this->_x = _x; }
    void Point::setY(double _y) { this->_y = _y; }
    string Point::print()
    {
        string s = "(" + to_string(this->_x) + ", " + to_string(this->_y) + ")";
        return s;
        
    }
    double Point::distance(Point other_point)
    {
        return sqrt(pow(this->_x - other_point.getX(), 2) + pow(this->_y - other_point.getY(), 2));
    }
    Point Point::moveTowards(Point source, Point target, double distance)
    {
        if (distance < 0)
        {
            throw std::invalid_argument("distance must be positive");
        }
        if (source.distance(target) < distance)
        {
            return target;
        }
        double x = source.getX() + (distance * (target.getX() - source.getX()) / source.distance(target)); // x = x0 + (v * (x1 - x0) / d)
        double y = source.getY() + (distance * (target.getY() - source.getY()) / source.distance(target)); // y = y0 + (v * (y1 - y0) / d)
        return Point(x, y);
    }

}