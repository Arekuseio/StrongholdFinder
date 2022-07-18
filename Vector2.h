#include <math.h>
#pragma once

class Vector2 {

	float x;

	float y;

public:
	Vector2() {
		this->x = 0.f;
		this->y = 0.f;
	}

	Vector2(const float& x, const float& y) {
		this->x = x;
		this->y = y;
	}

	Vector2(const Vector2& object) {
		this->x = object.GetX();
		this->y = object.GetY();
	}

	Vector2(float angle) {
		this->x = -1.f * sin(angle);
		this->y = 1.f * cos(angle);
	}

	float GetX() const {
		return this->x;
	}

	float GetY() const {
		return this->y;
	}
	
	Vector2 operator-(const Vector2& that) const {
		Vector2 new_vector(this->x - that.x, this->y - that.y);
		return new_vector;
	}

	Vector2 operator+(const Vector2& that) const {
		Vector2 new_vector(this->x + that.x, this->y + that.y);
		return new_vector;
	}
	
	float operator%(const Vector2& that) const {
		return (this->x * that.x) + (this->y * that.y);
	}

	~Vector2() { };
};