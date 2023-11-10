#include <gtest/gtest.h>
#include "Octagon.hpp"
#include "functions.hpp"
#include "Point.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "Vector.hpp"
#include <string>
#define INACCURACY 1e-4

TEST(constructor_oct_test1, valid_data) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  EXPECT_NO_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8));
}

TEST(constructor_oct_test2, invalid_data) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 9 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  EXPECT_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8), std::invalid_argument);
}

TEST(calculate_centre_oct_test1, normal) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);

  Point centre = test.calculate_centre();

  EXPECT_TRUE(centre.get_x() - 10 < INACCURACY);
  EXPECT_TRUE(centre.get_y() - 13.4142 < INACCURACY);
}

TEST(operator_double_oct_test1, normal) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);

  double square = static_cast<double>(test);
  EXPECT_TRUE(square - 32.9706 < INACCURACY);
}

TEST(compare_operator_oct_test1, true_test) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);
  Octagon test1(p1, p2, p3, p4, p5, p6, p7, p8);

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_point_test1, false_test) {
  Point p1(1, 1);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Point pp1(5, 5);
  Point pp2(pp1.get_x() - (1 + std::sqrt(2)), pp1.get_y() + 1);
  Point pp3(pp2.get_x() - 1, pp2.get_y() + 1 + std::sqrt(2));
  Point pp4(pp3.get_x() + 1, pp3.get_y() + (1 + std::sqrt(2)));
  Point pp5(pp4.get_x() + 1 + std::sqrt(2), pp4.get_y() + 1);
  Point pp6(pp5.get_x() + 1 + std::sqrt(2), pp5.get_y() - 1);
  Point pp7(pp6.get_x() + 1, pp6.get_y() - (1 + std::sqrt(2)));
  Point pp8(pp7.get_x() - 1, pp7.get_y() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);
  Octagon test1(pp1, pp2, pp3, pp4, pp5, pp6, pp7, pp8);

  EXPECT_FALSE(test == test1);
}

TEST(constructor_test_point, normal) {
  Point test(3, 5);
  EXPECT_EQ(test.get_x(), 3);
  EXPECT_EQ(test.get_y(), 5);
}

TEST(equal_operator_test1_point, true_test) {
  Point test0(3.1, 5.2);
  Point test1(3.1, 5.2);

  EXPECT_TRUE(test0 == test1);
}

TEST(equal_operator_test2_point, false_test) {
  Point test0(3.1, 5.2);
  Point test1(2, 9);

  EXPECT_FALSE(test0 == test1);
}

TEST(line_len_test_point, normal) {
  Point p1(4, 5);
  Point p2(8, 9);

  double len = Point::line_len(p1, p2);

  EXPECT_TRUE(len - 5.65685 < INACCURACY);
}

TEST(constructor_test1_sqr, valid_data) {
  EXPECT_NO_THROW(Square(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1)));
}

TEST(constructor_test2_sqr, invalid_data) {
  EXPECT_THROW(Square(Point(1, 1), Point(1, 3), Point(5, 3), Point(5, 1)), std::invalid_argument);
}

TEST(calculate_centre_test_sqr, normal) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Point centre = test.calculate_centre();
  EXPECT_TRUE(std::abs(centre.get_x() - 2) < INACCURACY);
  EXPECT_TRUE(std::abs(centre.get_y() - 2) < INACCURACY);
}

TEST(operator_double_test_sqr, normal) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  double square = static_cast<double>(test);
  EXPECT_TRUE(std::abs(square - 4) < INACCURACY);
}

TEST(compare_operator_test1_sqr, true_test) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Square test1(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_test2_sqr, false_test) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Square test1(Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2));

  EXPECT_FALSE(test == test1);
}

TEST(constructor_test1_tr, valid_data) {
  EXPECT_NO_THROW(Triangle test(Point(0, 0), Point(5, std::sqrt(3) * 5), Point(10, 0)));
}

TEST(constructor_test2_tr, invalid_data_1) {
  EXPECT_THROW(Triangle test(Point(0, 0), Point(1, 1), Point(2, 2)), std::invalid_argument);
}

TEST(constructor_test3_tr, invalid_data_2) {
  EXPECT_THROW(Triangle test(Point(0, 0), Point(0, 2), Point(3, 1)), std::invalid_argument);
}

TEST(calculate_centre_test_tr, normal) {
  Triangle test(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));
  Point t = test.calculate_centre();
  EXPECT_TRUE((t.get_x() - 7) < INACCURACY);
  EXPECT_TRUE((t.get_y() - 4.88765) < INACCURACY);
}

TEST(operator_double_test_tr, normal) {
  Triangle test(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));
  EXPECT_TRUE((static_cast<double>(test) - 43.30127) < INACCURACY);
}

TEST(compare_operator_test1_tr, true_test) {
  Triangle test(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));
  Triangle test1(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_test2_tr, false_test) {
  Triangle test(Point(3, 3), Point(8, 3 + std::sqrt(3) * 5), Point(13, 3));
  Triangle test1(Point(2, 2), Point(7, 2 + std::sqrt(3) * 5), Point(12, 2));

  EXPECT_FALSE(test == test1);
}

TEST(constructor_test_vector, default_constructor_test) {
  Vector<std::string> vec; // TESTED

  EXPECT_EQ(vec.get_capacity(), 1);
  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_NO_THROW(vec[0]);
}
TEST(get_size_test_vector, non_empty_vector) {
  Vector<std::string> v{"123", "412", "12451", "12345", "123", "1234", "134", "1234", "412", "14"};
  size_t size = v.get_size(); // TESTED

  EXPECT_EQ(size, 10);
}
TEST(get_capacity_test_vector, empty_vector) {
  Vector<std::string> v;
  size_t capacity = v.get_capacity(); // TESTED

  EXPECT_EQ(capacity, 1);
}