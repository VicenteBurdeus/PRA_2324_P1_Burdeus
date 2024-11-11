#ifndef Circle_H
#define Circle_H
#include <ostream>
#include <string>
#include "Shape.h"

class Circle : public Shape{
    private:
        Point2D center;
        double radius;
    public:
        Circle();
        Circle(std::string color, Point2D center, double radius);
        ~Circle();
        Point2D getCenter() const;
        void setCenter(Point2D c);
        double getRadius() const;
        void setRadius(double r);
        friend std::ostream& operator<<(std::ostream &out , const Circle& c);
        void print() const override;
        void translate(double x, double y) override;
        double area() const override;
        double perimeter() const override;
};

#endif