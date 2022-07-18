#pragma once

class Point2D {

    float x;

    float y;

public:

    Point2D(const float& x, const float& y) {
        this->x = x;
        this->y = y;
    }

    Point2D() {
        this->x = 0.f;
        this->y = 0.f;
    }

    Point2D(const Point2D& object) {
        this->x = object.x;
        this->y = object.y;
    }

    float GetX() const {
        return this->x;
    }

    float GetY() const {
        return this->y;
    }

    ~Point2D() { };
};