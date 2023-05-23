#pragma once
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;
namespace ariel
{
    class Point
    {
    private:
        double _x; // coordinate x of the point
        double _y; // coordinate y of the point
    public:
        Point(double x, double y); // Constructor that initializes the Location object with the given x and y coordinates
        // copy constructor
        Point(const Point &p);
        ~Point();
        double distance(Point p);                   // calculate the distance between two points
        // getters and setters
        double getX();
        double getY();
        void setX(double x);
        void setY(double y);
        // Method that prints the current location in the format (x, y)
        string print();
        // Method that takes a source Location, a target Location, and a distance value as inputs.
        // It computes the distance between source and target and returns the closest location to target that is within distance of source.
        static Point moveTowards(Point p, Point t, double distance);
    };
}