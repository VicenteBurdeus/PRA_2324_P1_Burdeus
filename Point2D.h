#ifndef POINT2D_H
#define POINT2D_H
#include <cmath>
#include <ostream>

class Point2D {
public:
    double x;
    double y;

    public:
    Point2D(double x = 0, double y = 0) : x(x), y(y) {} 
    friend bool operator== (const Point2D &a, const Point2D &b);
    friend bool operator!= (const Point2D &a, const Point2D &b);
    static double distance(const Point2D &a, const Point2D &b){
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
    friend std::ostream& operator << (std::ostream &out, const Point2D &p){
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

#endif
