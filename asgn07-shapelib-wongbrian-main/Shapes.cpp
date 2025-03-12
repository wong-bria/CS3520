#include "Shapes.hpp"
using namespace std;



// TODO

// Shape implementation
Shape::~Shape() {
  // Empty destructor
}

// Circle implementation
Circle::Circle(const Vector2D& center, double radius) 
  : m_center(center), m_radius(radius) {}

Circle::~Circle() {
  std::cout << "Destroying: ";
  display(std::cout) << std::endl;
}

std::ostream& Circle::display(std::ostream& os) const {
  os << "Circle(" << m_center.getX() << "," << m_center.getY() << "; " << m_radius << ")";
  return os;
}

void Circle::translate(const Vector2D& v) {
  m_center.setX(m_center.getX() + v.getX());
  m_center.setY(m_center.getY() + v.getY());
}

// Triangle implementation
Triangle::Triangle(const Vector2D& a, const Vector2D& b, const Vector2D& c) {
  m_points[0] = a;
  m_points[1] = b;
  m_points[2] = c;
}

Triangle::~Triangle() {
  std::cout << "Destroying: ";
  display(std::cout) << std::endl;
}

std::ostream& Triangle::display(std::ostream& os) const {
  os << "Triangle(";
  for (int i = 0; i < 3; ++i) {
    os << m_points[i].getX() << "," << m_points[i].getY();
    if (i < 2) {
      os << "; ";
    }
  }
  os << ")";
  return os;
}

void Triangle::translate(const Vector2D& v) {
  for (int i = 0; i < 3; ++i) {
    m_points[i].setX(m_points[i].getX() + v.getX());
    m_points[i].setY(m_points[i].getY() + v.getY());
  }
}