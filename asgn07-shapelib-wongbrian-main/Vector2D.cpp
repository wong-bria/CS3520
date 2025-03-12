#include "Vector2D.hpp"
#include <stdexcept>
using namespace std;

// TODO

Vector2D::Vector2D() : m_x(0.0), m_y(0.0) {}

Vector2D::Vector2D(const Vector2D& v) : m_x(v.m_x), m_y(v.m_y) {}

Vector2D::Vector2D(double d1, double d2) : m_x(d1), m_y(d2) {}

void Vector2D::setX(double d) {
    m_x = d;
}

void Vector2D::setY(double d) {
    m_y = d;
}

double Vector2D::getX() const {
    return m_x;
}

double Vector2D::getY() const {
    return m_y;
}

double& Vector2D::operator[](size_t i) {
    if (i == 0) {
        return m_x;
    } else if (i == 1) {
        return m_y;
    } else {
        throw std::out_of_range("Index must be 0 or 1");
    }
}

const double& Vector2D::operator[](size_t i) const {
    if (i == 0) {
        return m_x;
    } else if (i == 1) {
        return m_y;
    } else {
        throw std::out_of_range("Index must be 0 or 1");
    }
}

Vector2D& Vector2D::operator=(const Vector2D& v) {
    if (this != &v) {
        m_x = v.m_x;
        m_y = v.m_y;
    }
    return *this;
}

bool Vector2D::operator==(const Vector2D& v) const {
    return m_x == v.m_x && m_y == v.m_y;
}

bool Vector2D::operator!=(const Vector2D& v) const {
    return !(*this == v);
}

Vector2D Vector2D::operator-() const {
    return Vector2D(-m_x, -m_y);
}

Vector2D& Vector2D::operator+=(const Vector2D& v) {
    m_x += v.m_x;
    m_y += v.m_y;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& v) const {
    return Vector2D(m_x + v.m_x, m_y + v.m_y);
}

Vector2D& Vector2D::operator-=(const Vector2D& v) {
    m_x -= v.m_x;
    m_y -= v.m_y;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v) const {
    return Vector2D(m_x - v.m_x, m_y - v.m_y);
}

Vector2D& Vector2D::operator*=(double d) {
    m_x *= d;
    m_y *= d;
    return *this;
}

Vector2D Vector2D::operator*(double d) const {
    return Vector2D(m_x * d, m_y * d);
}

Vector2D operator*(double d, const Vector2D& v) {
    return Vector2D(v.m_x * d, v.m_y * d);
}

Vector2D& Vector2D::operator/=(double d) {
    if (d == 0.0) {
        throw std::invalid_argument("Division by zero");
    }
    m_x /= d;
    m_y /= d;
    return *this;
}

Vector2D Vector2D::operator/(double d) const {
    if (d == 0.0) {
        throw std::invalid_argument("Division by zero");
    }
    return Vector2D(m_x / d, m_y / d);
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << v.m_x << "," << v.m_y;
    return os;
}
