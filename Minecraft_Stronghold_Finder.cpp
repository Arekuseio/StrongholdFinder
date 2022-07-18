#include <iostream>
#include "2DLine.h"

#ifndef PI

#define PI 3.141592653589

#endif // PI


class Finder {

    Line2D firstThrow;
    
    Line2D secondThrow;

public:

    Finder(const Vector2& firstVector, const Point2D& firstPoint, 
            const Vector2& secondVector, const Point2D& secondPoint) {

        this->firstThrow = Line2D(firstVector, firstPoint);

        this->secondThrow = Line2D(secondVector, secondPoint);
    }

    Finder(const Finder& object) {
        this->firstThrow = object.firstThrow;
        this->secondThrow = object.secondThrow;
    }

    Point2D FindStronghold() {
        Point2D strongholdPoint = firstThrow.CalcIntersecPoint(secondThrow);

        return strongholdPoint;
    }

    ~Finder() { };
};

int main()
{
    float angle1, angle2, point1x, point1y, point2x, point2y;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введи координаты (X, Z) и угол первого броска: " << std::endl;
    std::cin >> point1x >> point1y >> angle1;
    std::cout << "Введи координаты (X, Z) и угол второго броска: " << std::endl;
    std::cin >> point2x >> point2y >> angle2;

    angle1 = angle1 / 180.f * PI;
    angle2 = angle2 / 180.f * PI;

    Vector2 firstvec(angle1); Vector2 secondvec(angle2);
    Point2D first(point1x, point1y); Point2D second(point2x, point2y);

    Finder A(firstvec, first, secondvec, second);
    Point2D point = A.FindStronghold();
    std::cout << "Координаты крепости: " << point.GetX() << " " << point.GetY();

    std::cin >> angle1;
    return 0;
}
