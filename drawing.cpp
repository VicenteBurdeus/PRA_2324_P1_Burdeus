#include "drawing.h"
#include "Shape.h"
#include "ListArray.h"
//reserva memoria dinamica para el el atributo shapes

drawing::drawing(){
    ListArray<Shape*> *shapes;
}

drawing::~drawing(){
    delete shapes;
}
//asumo que el elemento 0 es el de mas atras y el n-1 el de mas adelante
void drawing::add_front(Shape* s){
    //añade otro elemento al principio de la lista
    shapes->append(s);
}

void drawing::add_back(Shape* s){
    //añade otro elemento al final de la lista
    shapes->prepend(s);
}

void drawing::print_all() const{
    //imprime todos los elementos de la lista
    std::cout << *shapes;
}

double drawing::get_area_all_cirlces() const{
    //suma todas las areas de los circulos
    double area = 0;
    for (int i = 0; i < shapes->size(); i++){
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c != nullptr){
            area += c->area();
        }
    }
    return area;
}

void drawing::move_all_square(double x, double y){
    for (int i = 0; i < shapes->size(); i++){
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s != nullptr){
            s->translate(x, y);
        }
    }
}