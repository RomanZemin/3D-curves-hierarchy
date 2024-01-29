#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <omp.h>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Spiral.h"


int main() {
    srand(time(0));

    std::vector<Curve*> curves;

    // ��������� ��������� ���������� �������
    for (int i = 0; i < 10; i++) {
        int type = rand() % 3;
        double radiusX = (rand() % 10) + 1;
        double radiusY = (rand() % 10) + 1;
        double radius = (rand() % 10) + 1;
        double step = (rand() % 10) + 1;

        if (type == 0) {
            curves.push_back(new Circle(radius));
        }
        else if (type == 1) {
            curves.push_back(new Ellipse(radiusX, radiusY));
        }
        else if (type == 2) {
            curves.push_back(new Spiral(radius, step));
        }
    }

    // �������� ���������� � ����������� ���� ������
    for (const auto& curve : curves) {
        std::cout << "Radius: " << curve->getRadius() << ", Derivative: " << curve->getDerivative() << ", Type: " << curve->getType() << std::endl;
    }

    std::vector<Circle*> circles;

    // ��������� ������ ��������� ������� �� ������� ����������
    for (const auto& curve : curves) {
        if (dynamic_cast<Circle*>(curve) != nullptr) {
            circles.push_back(dynamic_cast<Circle*>(curve));
        }
    }

    // ��������� ������ ��������� �� ����������� ��������
    std::sort(circles.begin(), circles.end(), [](Circle* a, Circle* b) {
        return a->getRadius() < b->getRadius();
        });

    // ��������� ����� ����� �������� ������ �� ������ ����������
    double sum = 0;

    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < circles.size(); i++) {
        sum += circles[i]->getRadius();
    }

    std::cout << "Sum of radii: " << sum << std::endl;

    // ����������� ���������� ������
    for (const auto& curve : curves) {
        delete curve;
    }

    return 0;
}