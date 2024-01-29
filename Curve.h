#pragma once
class Curve
{
public:
    virtual ~Curve();
    virtual double getRadius() const = 0;
    virtual double getDerivative() const = 0;
    virtual int getType() const = 0;
};