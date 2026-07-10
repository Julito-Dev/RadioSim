# pragma once
# include <cmath>
# include <iostream>

class Vector2d {
    public:
        float x, y;

    Vector2d(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2d operator+(const Vector2d& other) const {
        return Vector2d(x + other.x, y + other.y);
    }

    Vector2d operator-(const Vector2d& other) const {
        return Vector2d(x - other.x, y - other.y);
    }

    Vector2d operator*(float scalar) const {
        return Vector2d(x * scalar, y * scalar);
    }

    Vector2d operator+=(const Vector2d& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    float magnitude() const {
        return std::sqrt((x*x) + (y*y));
    }

    float distanceTo(const Vector2d& other) const {
        return (*this - other).magnitude();
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    Vector2d normalized() const {
        float mag = this -> magnitude();
        if (mag == 0){
            return Vector2d(0.0f, 0.0f);
        }
        else{
            return Vector2d(x/mag, y/mag);
        }
    }

    
};