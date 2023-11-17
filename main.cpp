#include <iostream>
#include <memory>
#include "Vector.h"
#include "Octagon.h"
#include "Square.h"
#include <Triangle.h>
#include "functions.h"
#include "Point.h"
#include "/home/fltww/l_3/labs_oop/src/lab0/functions.cpp"
#include "/home/fltww/l_3/labs_oop/src/lab0/Point.cpp"
#include "/home/fltww/l_3/labs_oop/src/lab0/Vector.cpp"
#include "/home/fltww/l_3/labs_oop/src/lab0/Triangle.cpp"
#include "/home/fltww/l_3/labs_oop/src/lab0/Square.cpp"
using namespace std;
using triangle = Triangle<double>;
using square = Square<double>;
using point = Point<double>;

int main() {
  shared_ptr<triangle> t1 = make_shared<triangle>(point(1, 1), point(6, 1 + sqrt(3) * 5), point(11, 1));
  shared_ptr<triangle> t0 = make_shared<triangle>(point(0, 0), point(5, sqrt(3) * 5), point(10, 0));
  shared_ptr<square> s0 = make_shared<square>(point(1, 1), point(1, 3), point(3, 3), point(3, 1)); 
  shared_ptr<square> s1 = make_shared<square>(point(3, 3), point(3, 5), point(5, 5), point(5, 3));
  Vector<shared_ptr<Figure<double>>> v = {t1, t0, s0, s1};
  print_all_areas(v);
  print_all_centres(v);
  double all_area = calculate_all_area(v);
  cout << "Sum of areas: " << all_area << endl;
}