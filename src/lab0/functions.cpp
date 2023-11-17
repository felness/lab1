#include "functions.h"
inline double calculate_all_area(Vector<shared_ptr<Figure<double>>>& vec) {
  double area = 0;
  for (auto& el : vec) {
    area += static_cast<double>(*el);
  }

  return area;
}

inline void print_all_areas(Vector<shared_ptr<Figure<double>>>& vec) {
  cout << "areas of all figures: " << endl;
  
  for (auto& el : vec) {
    cout << static_cast<double>(*el) << ", ";
  }

  cout << endl;
}

inline void print_all_centres(Vector<shared_ptr<Figure<double>>>& vec) {
  cout << "centres of all figures: " << endl;

  for (auto& el : vec) {
    cout << el->calculate_centre() << ", ";
  }

  cout << endl;
}