#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "Vector.hpp"
#include "Point.hpp"
#include <iostream>

class Figure {
protected:
  Vector<Point> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual Point calculate_centre() const = 0;
};

#endif // FIGURE_H_INCLUDED