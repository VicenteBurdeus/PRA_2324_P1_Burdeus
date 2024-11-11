#include "Shape.h"

Shape::Shape(){
    color = "white";
}

Shape::Shape(std::string color){

    if (color != "red" && color != "green" && color != "blue"){//aplicar Morgan ha servido de algo
        throw std::invalid_argument("El color no es valido");
    }else{
    this->color = color;
    }
}

Shape::~Shape(){
}

std::string Shape::getColor() const {
    return color;
}

void Shape::setColor(std::string c){
    if (c != "red" && c != "green" && c != "blue"){//aplicar Morgan ha servido de algo
        throw std::invalid_argument("El color no es valido");
    }else{
    color = c;
    }
}

