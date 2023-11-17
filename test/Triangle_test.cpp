#include <gtest/gtest.h>
#include "Triangle.hpp"

#define INACCURACY 1e-5

TEST(constructor_test1_triangle, valid_data) {
  EXPECT_NO_THROW(Triangle test(Point(0, 0), Point(5, std::sqrt(3) * 5), Point(10, 0)));
}

TEST(constructor_test2_triangle, invalid_data_1) {
  EXPECT_THROW(Triangle test(Point(0, 0), Point(1, 1), Point(2, 2)), std::invalid_argument);
}

TEST(constructor_test3_triangle, invalid_data_2) {
  EXPECT_THROW(Triangle test(Point(0, 0), Point(0, 2), Point(3, 1)), std::invalid_argument);
}

TEST(calculate_centre_test_triangle, normal) {
  Triangle test(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));
  Point t = test.calculate_centre();
  EXPECT_TRUE((t.get_x() - 7) < INACCURACY);
  EXPECT_TRUE((t.get_y() - 4.88765) < INACCURACY);
}

TEST(operator_double_test_triangle, normal) {
  Triangle test(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));
  EXPECT_TRUE((static_cast<double>(test) - 43.30127) < INACCURACY);
}

TEST(compare_operator_test1_triangle, true_test) {
  Triangle test(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));
  Triangle test1(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_test2_triangle, false_test) {
  Triangle test(Point(3, 3), Point(8, 3 + std::sqrt(3) * 5), Point(13, 3));
  Triangle test1(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));

  EXPECT_FALSE(test == test1);
}

