#include <gtest/gtest.h>
#include <lib.h>

TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange 
  int first_number = 1;
  int second_number = 9;

  // act
  int res = gcd(first_number,second_number);

  // assert
  EXPECT_EQ(res, 1);
}
TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange 
  int first_number = 2;
  int second_number = 10;

  // act
  int res = gcd(first_number,second_number);

  // assert
  EXPECT_EQ(res, 2);
}
TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  // arrange 
  int first_number = 3;
  int second_number = 15;

  // act
  int res = gcd(first_number,second_number);

  // assert
  EXPECT_EQ(res, 3);
}