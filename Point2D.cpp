#include "Point2D.h"
#include <cmath>

bool operator== (const Point2D &a, const Point2D &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!= (const Point2D &a, const Point2D &b) {
    return !(a == b);
}

double distance(const Point2D &a, const Point2D &b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(){
    return 0;
}