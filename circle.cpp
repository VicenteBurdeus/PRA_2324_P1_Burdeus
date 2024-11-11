#include "Circle.h"
#include <iostream>
#include <cmath>

Circle::Circle(){
    center = Point2D();
    radius = 0;
}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color){
    this->center = center;
    this->radius = radius;
}

Circle::~Circle(){
}

Point2D Circle::getCenter() const{
    return center;
}

void Circle::setCenter(Point2D c){
    center = c;
}

double Circle::getRadius() const{
    return radius;
}

void Circle::setRadius(double r){
    radius = r;
}

std::ostream& operator<<(std::ostream &out , const Circle& c){
    out << "Circle: " << c.getColor() << " " << c.center << " " << c.radius;
    return out;
}

void Circle::print() const{
    std::cout << *this << std::endl;
}

void Circle::translate(double x, double y){
    this->center.x = (this->center.x + x);
    this->center.y = (this->center.y + y);
}

double Circle::area() const{
    return M_PI * pow(radius, 2);
}

double Circle::perimeter() const{
    return 2 * M_PI * radius;
}






