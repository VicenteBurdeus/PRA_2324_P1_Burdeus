#include "Shape.h"

Shape::Shape(){
    color = "white";
}

Shape::Shape(std::string color){
    this->color = color;
}

Shape::~Shape(){
}

std::string Shape::getColor(){
    return color;
}

void Shape::setColor(std::string c){
    color = c;
}

