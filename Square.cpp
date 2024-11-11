#include <cmath>
#include "Square.h"

Square::Square() : Rectangle() {
    Point2D* vertizes = new Point2D[4];
    vertizes[0] = Point2D(-1, 1);
    vertizes[1] = Point2D(1, 1);
    vertizes[2] = Point2D(1, -1);
    vertizes[3] = Point2D(-1, 1);
    if (!check(vertizes)) {
        throw std::invalid_argument("No es un cuadrado");
    }
    set_vertices(vertizes);
}
Square::Square(std::string color, Point2D* vertizes) : Rectangle() {
    if (!check(vertizes)) {
        throw std::invalid_argument("No es un cuadrado");
    }
    set_vertices(vertizes);
    this->setColor(color);
}
void Square::set_vertices(Point2D* vertizes) {
    if (!check(vertizes)) {
        throw std::invalid_argument("No es un cuadrado");
    }
    for (int i = 0; i < N_VERTIZES; i++) {
        this->vs[i] = vertizes[i];
    }
}

bool Square::check(Point2D* vertizes) {
    float L1 = Point2D::distance(vertizes[0], vertizes[1]);
    float L2 = Point2D::distance(vertizes[1], vertizes[2]);
    float L3 = Point2D::distance(vertizes[2], vertizes[3]);
    float L4 = Point2D::distance(vertizes[3], vertizes[0]);
    return (L1 == L2) && (L2 == L3) && (L3 == L4);
}

std::ostream& operator<<(std::ostream& out, const Square& s) {
    out << "Color: " << s.getColor() << std::endl;
    out << "Vertices: " << std::endl;
    for (int i = 0; i < s.N_VERTIZES; i++) {
        out << s.vs[i] << std::endl;
    }
    return out;
}

double Square::area() const {
    double aux = Point2D::distance(vs[0], vs[1]);
    return aux * aux;
}

double Square::perimeter() const {
    double aux = Point2D::distance(vs[0], vs[1]);
    return 4 * aux;
}

void Square::print() const {
    std::cout << *this;
}