#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"
#include <string>

class Shape{
    protected:
        std::string color;
    
    public:
        Shape();
        Shape(std::string color);
        virtual ~Shape();
        std::string getColor();
        void setColor(std::string c);
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual void translate(double x, double y) = 0;
        virtual void print() const = 0;
};

#endif