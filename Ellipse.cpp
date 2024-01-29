#include "Ellipse.h"
#include "Consts.h"

double Ellipse::getRadius() const { return (radiusX + radiusY) / 2; }
double Ellipse::getDerivative() const { return M_PI * (radiusX + radiusY); }
int Ellipse::getType() const { return 1; }
Ellipse::Ellipse(double radiusX, double radiusY) { this->radiusX = radiusX; this->radiusY = radiusY; }