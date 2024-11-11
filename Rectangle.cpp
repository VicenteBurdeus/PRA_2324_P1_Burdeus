#include "Rectangle.h"

bool Rectangle::check(Point2D* vs){
    int aux[4];
    bool auxb = false;
    aux[0] = Point2D::distance(vs[0], vs[1]);
    aux[1] = Point2D::distance(vs[2], vs[3]);
    aux[2] = Point2D::distance(vs[0], vs[2]);
    aux[3] = Point2D::distance(vs[1], vs[4]);
    
    //busca si es un rectangulo 
    if (aux[0]==aux[1] && aux[2]==aux[3]){
        auxb = true;
    }
    if (aux[0]==aux[2] && aux[1]==aux[3]){
        auxb = true;
    }

    return auxb;
}

Rectangle::Rectangle():Shape(){
    vs = new Point2D[N_VERTIZES];
    vs[0] = Point2D(-1,0.5);
    vs[1] = Point2D(1,0.5);
    vs[2] = Point2D(1,-0.5);
    vs[3] = Point2D(-1,-0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vs):Shape(color){
    if (check(vs)){
        this->vs = new Point2D[N_VERTIZES];
        for (int i = 0; i < N_VERTIZES; i++){
            this->vs[i] = vs[i];
        }
    }else{
        throw std::invalid_argument("No es un rectangulo2");
    }
}

Rectangle::Rectangle(const Rectangle& r):Shape(r.getColor()){
    vs = new Point2D[N_VERTIZES];
    for (int i = 0; i < N_VERTIZES; i++){
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle(){
    delete[] vs;
}

Point2D* Rectangle::get_vertex(int ind) const{
    if(ind < 0 || ind >= N_VERTIZES){
        throw std::out_of_range("Indice fuera de rango3");
    }else{
        return &vs[ind];
    }
}

Point2D* Rectangle::operator[](int ind) const{
    if (ind < 0 || ind >= N_VERTIZES){
        throw std::out_of_range("Indice fuera de rango4");
    }else{
        return &vs[ind];
    }
}

void Rectangle::set_vertices(Point2D* vs){
    if (check(vs)){
        for (int i = 0; i < N_VERTIZES; i++){
            this->vs[i] = vs[i];
        }
    }else{
        throw std::invalid_argument("No es un rectangulo");
    }
}
/*Sobrecarga del operador = (asignación de copia). Permitirá hacer una copia segura de rectángulos. */
Rectangle& Rectangle::operator=(const Rectangle& r){
    if (this != &r){
        delete[] vs;
        vs = new Point2D[N_VERTIZES];
        for (int i = 0; i < N_VERTIZES; i++){
            vs[i] = r.vs[i];
        }
        setColor(r.getColor());
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
    out << "Color: " << r.getColor() << std::endl;
    out << "Vertices: " << std::endl;
    for (int i = 0; i < r.N_VERTIZES; i++){
        out << r.vs[i] << std::endl;
    }
    return out;
}

double Rectangle::area() const{
    double aux = Point2D::distance(vs[0], vs[1]);
    double aux2 = Point2D::distance(vs[1], vs[2]);
    return aux*aux2;
}

double Rectangle::perimeter() const{
    double aux = Point2D::distance(vs[0], vs[1]);
    double aux2 = Point2D::distance(vs[1], vs[2]);
    return 2*(aux+aux2);
}

void Rectangle::translate(double x, double y){
    for (int i = 0; i < N_VERTIZES; i++){
        vs[i].x += x;
        vs[i].y += y;
    }
}

void Rectangle::print() const{
    std::cout << *this;
}