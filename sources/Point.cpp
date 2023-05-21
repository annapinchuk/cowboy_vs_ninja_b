#include "Point.hpp"
namespace ariel{
    Point::Point(double x, double y) : _x(x), _y(y){}
    double Point::getX(){return this->_x;}
    double Point::getY(){return this->_y;}
    void Point::setX(double _x){this->_x = _x;}
    void Point::setY(double _y){this->_y = _y;}
    void Point::print(){
         std::cout << "(" << this->_x << "," << this->_y << ")";
    }
    double Point::distance(Point other_point){
        return sqrt(pow(this->_x - other_point.getX(), 2) + pow(this->_y - other_point.getY(), 2));
    }

}