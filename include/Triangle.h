#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "figure.h"

class Triangle : public Figure {
public:
  Triangle(const Point& p1, const Point& p2, const Point& p3);

  friend std::ostream& operator<<(std::ostream& os, Triangle& rhs);
  friend std::istream& operator>>(std::istream& os, Triangle& rhs);

  friend bool operator==(const Triangle& lhs, const Triangle& rhs);

  Point calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(const Point& p1, const Point& p2, const Point& p3) noexcept;
};

#endif // TRIANGLE_H_INCLUDED