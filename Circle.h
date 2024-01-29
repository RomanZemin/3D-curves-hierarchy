#pragma once
#include"Curve.h"

class Circle : public Curve {
private:
    double radius;

public:
    Circle(double radius);
    double getRadius() const override;
    double getDerivative() const override;
    int getType() const override;
};