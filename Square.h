#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"
#include "point2d.h"
#include <ostream>


class Square : public Rectangle {
    private:
        static bool check(Point2D* vertizes);
    public:
        Square();
        Square(std::string color, Point2D* vertizes);
        void set_vertices(Point2D* vertizes) override;
        friend std::ostream& operator<<(std::ostream &out , const Square &s);
        double area() const override;
        double perimeter() const override;
        void print() const override;
        
};
#endif