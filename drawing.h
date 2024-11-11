#ifndef drawing_h
#define drawing_h
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Point2D.h"
#include "ListArray.h"


class drawing{
    private:
        ListArray<Shape*> *shapes;
    public:
        drawing();
        ~drawing();
        void add_front(Shape* s);
        void add_back(Shape* s);
        void print_all() const;
        double get_area_all_cirlces() const;
        void move_all_square(double x, double y);

};


#endif
