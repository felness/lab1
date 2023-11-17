#include <gtest/gtest.h>
#include "Triangle.h"
#include "Vector.h"
#include "Point.h"
#include "/home/fltww/l_3/labs_oop/src/lab0/Point.cpp"
#include "/home/fltww/l_3/labs_oop/src/lab0/Triangle.cpp"
#include "/home/fltww/l_3/labs_oop/src/lab0/Vector.cpp"
#define INACCURACY 1e-5

TEST(constructor_test1_triangle, valid_data) {
  EXPECT_NO_THROW(Triangle<double> test(Point<double>(0, 0), Point<double>(5, std::sqrt(3) * 5), Point<double>(10, 0)));
}

TEST(constructor_test2_triangle, invalid_data_1) {
  EXPECT_THROW(Triangle<double> test(Point<double>(0, 0), Point<double>(1, 1), Point<double>(2, 2)), std::invalid_argument);
}

TEST(constructor_test3_triangle, invalid_data_2) {
  EXPECT_THROW(Triangle<double> test(Point<double>(0, 0), Point<double>(0, 2), Point<double>(3, 1)), std::invalid_argument);
}

TEST(calculate_centre_test_triangle, normal) {
  Triangle<double> test(Point<double>(2, 2), Point<double>(7, 2 + std::sqrt(3) * 5), Point<double>(12, 2));
  Point<double> t = test.calculate_centre();
  EXPECT_TRUE((t.get_x() - 7) < INACCURACY);
  EXPECT_TRUE((t.get_y() - 4.88765) < INACCURACY);
}

TEST(operator_double_test_triangle, normal) {
  Triangle<double> test(Point<double>(2, 2), Point<double>(7, 2 + std::sqrt(3) * 5), Point<double>(12, 2));
  EXPECT_TRUE((static_cast<double>(test) - 43.30127) < INACCURACY);
}

TEST(compare_operator_test1_triangle, true_test) {
  Triangle<double> test(Point<double>(2, 2), Point<double>(7, 2 + std::sqrt(3) * 5), Point<double>(12, 2));
  Triangle<double> test1(Point<double>(2, 2), Point<double>(7, 2 + std::sqrt(3) * 5), Point<double>(12, 2));

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_test2_triangle, false_test) {
  Triangle<double> test(Point<double>(3, 3), Point<double>(8, 3 + std::sqrt(3) * 5), Point<double>(13, 3));
  Triangle<double> test1(Point<double>(2, 2), Point<double>(7, 2 + std::sqrt(3) * 5), Point<double>(12, 2));

  EXPECT_FALSE(test == test1);
}

