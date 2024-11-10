#ifndef Point2D_H
#define Point2D_H

#include <ostream>
#include <cmath>

class Point2D{
    public:
        double x;
        double y;

        Point2D(double x=0, double y=0){
            this->x = x;
            this->y = y;
        }

        friend bool operator == (const Point2D &a, const Point2D &b)
        {
            return a.x == b.x && a.y == b.y;
        }

        friend bool operator != (const Point2D &a, const Point2D &b)
        {
            return !(a == b);
        }

        static double distance(Point2D &a, Point2D &b)
        {
            return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
        }

        friend std::ostream& operator << (std::ostream &out, const Point2D &p)
        {
            out << "(" << p.x << ", " << p.y << ")";
            return out;
        }

        
};


#endif