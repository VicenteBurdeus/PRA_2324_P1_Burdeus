#include "Shape.h"

Shape::Shape(){
    color = "white";
}

Shape::Shape(std::string color){
    this->color = color;
}

Shape::~Shape(){
}

std::string Shape::getColor() const {
    return color;
}

void Shape::setColor(std::string c){
    color = c;
}

