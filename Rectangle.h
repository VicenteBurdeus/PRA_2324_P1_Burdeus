#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"


class Rectangle : public Shape{
    protected:
        Point2D* vs;
    private:
        static bool check(Point2D* vs);
    public:
        static int const N_VERTIZES = 4;
        Rectangle();
        Rectangle(std::string color, Point2D* vs);
        Rectangle(const Rectangle& r);
        ~Rectangle();
        Point2D* get_vertex(int ind) const;
        Point2D* operator[](int ind) const;
        virtual void set_vertices(Point2D* vs);
        Rectangle& operator=(const Rectangle& r);
        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
        double area() const override;
        double perimeter() const override;
        void translate(double x, double y) override;
        void print() const override;
};  


#endif