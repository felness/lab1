#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "Vector.hpp"
#include "Point.hpp"
#include <iostream>
#include "/home/fltww/l_3/labs_oop/src/lab0/Vector.cpp"
class Figure {
protected:
  Vector<Point> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual Point calculate_centre() const = 0;
};

#endif 