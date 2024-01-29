#include "Circle.h"
#include "Consts.h"
Circle::Circle(double radius) { this->radius = radius; }
double Circle:: getDerivative() const { return 2 * M_PI * radius; }
double Circle::getRadius() const { return radius; }
int Circle::getType() const { return 0; }