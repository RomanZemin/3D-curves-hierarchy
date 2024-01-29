#include "Spiral.h"

Spiral::Spiral(double radius, double step){ this->radius = radius; this->step = step; }
double Spiral::getRadius() const { return radius; }
double Spiral::getDerivative() const { return step; }
int Spiral::getType() const { return 2; }