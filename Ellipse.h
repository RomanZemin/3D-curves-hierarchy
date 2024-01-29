#pragma once
#include"Curve.h"
class Ellipse : public Curve {
private:
    double radiusX;
    double radiusY;

public:
    Ellipse(double radiusX, double radiusY);
    double getRadius() const override;
    double getDerivative() const override;
    int getType() const override;
};