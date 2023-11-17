#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include "Vector.h"
#include "Figure.h"
using namespace std;
inline double calculate_all_area(Vector<shared_ptr<Figure<double>>>& vec);

inline void print_all_areas(Vector<std::shared_ptr<Figure<double>>>& vec);

inline void print_all_centres(Vector<std::shared_ptr<Figure<double>>>& vec);

#endif