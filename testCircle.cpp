#include <iostream>
#include "Circle.h"
#include "Point2D.h"

int main(){

    Circle c1;
    Circle c2("green", Point2D(1,1), 2);
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl; 
    std::cout << std::endl;

    c1.setCenter(c2.getCenter());
    c1.setRadius(c2.getRadius());
    c2.setColor("blue");

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;

} 
