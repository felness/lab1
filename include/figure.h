#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include "Vector.h"
#include "Point.h"
#include <iostream>

class Figure {
protected:
  Vector<Point> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual Point calculate_centre() const = 0;
};

#endif // FIGURE_H_INCLUDED