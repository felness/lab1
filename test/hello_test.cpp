#include <gtest/gtest.h>
#include <lib.h>

TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange 
  int first_number = -10;
  int second_number = -5;

  // act
  int res = gcd(first_number,second_number);

  // assert
  EXPECT_EQ(res, 5);
}
TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange 
  int first_number = -16;
  int second_number = 2;

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
TEST(sameValues,BasicAssertions){
  //arrange
  int first_number=5;
  int second_number=5;

  //act
  int res=gcd(first_number,second_number);
  
  //assert
  EXPECT_EQ(res,5);
}
