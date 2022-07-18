#pragma once
#include "Point2D.h"
#include "Vector2.h"

class Line2D {

	Vector2 direction;

	Point2D point;

public:

	Line2D(const Vector2& direction, const Point2D& point) {
		this->direction = direction;
		this->point = point;
	}

	Line2D(const Vector2& direction) {
		this->direction = direction;
		this->point = Point2D(0.f, 0.f);
	}

	Vector2 GetDirection() const {
		return this->direction;
	}

	Point2D GetPoint() const {
		return this->point;
	}

	Point2D CalcIntersecPoint(const Line2D& other) {

		float a1, b1, c1, a2, b2, c2;

		a1 = direction.GetY();
		b1 = -direction.GetX();
		c1 = direction.GetX() * point.GetY() - direction.GetY() * point.GetX();

		a2 = other.direction.GetY();
		b2 = -other.direction.GetX();
		c2 = other.direction.GetX() * other.point.GetY() - other.direction.GetY() * other.point.GetX();

		float crossX = (b1 * c2 - b2 * c1) / (b2 * a1 - b1 * a2);
		float crossY = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);

		Point2D crossPoint(crossX, crossY);
		return crossPoint;
	}

	Line2D() { };

	~Line2D() { };
};