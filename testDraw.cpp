#include <iostream>
#include "drawing.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

int main(){
    drawing d;
    d.add_front(new Circle());
    d.add_front(new Square());
    d.add_back(new Rectangle());
    d.print_all();
    std::cout << std::endl;
    
    std::cout << "Area (all circles) = " << d.get_area_all_cirlces() << std::endl;
    std::cout << std::endl;

    std::cout << "Calling move_squares(10, 10)..." << std::endl;
    d.move_all_square(10, 10);

    d.print_all();
}