#pragma once
#include "Curve.h"
class Spiral : public Curve {
private:
    double radius;
    double step;

public:
    Spiral(double radius, double step);
    double getRadius() const override;
    double getDerivative() const override;
    int getType() const override;

};