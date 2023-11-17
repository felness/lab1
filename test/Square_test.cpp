#include <gtest/gtest.h>

#include "Square.hpp"

#define INACCURACY 1e-5

TEST(constructor1_test_square, valid_data) {
  EXPECT_NO_THROW(Square(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1)));
}

TEST(constructor2_test_square, invalid_data) {
  EXPECT_THROW(Square(Point(1, 1), Point(1, 3), Point(5, 3), Point(5, 1)), std::invalid_argument);
}

TEST(calculate_centre_test_square, normal) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Point centre = test.calculate_centre();
  EXPECT_TRUE(std::abs(centre.get_x() - 2) < INACCURACY);
  EXPECT_TRUE(std::abs(centre.get_y() - 2) < INACCURACY);
}

TEST(operator1_double_test_square, normal) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  double square = static_cast<double>(test);
  EXPECT_TRUE(std::abs(square - 4) < INACCURACY);
}

TEST(compare_operator_test1_square, true_test) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Square test1(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_test2_square, false_test) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Square test1(Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2));

  EXPECT_FALSE(test == test1);
}
