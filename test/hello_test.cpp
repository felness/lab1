#include <gtest/gtest.h>
#include "Octal.h"
#include "Octal_builder.h"
#include <string>

TEST(ErrorTest, BasicAssertions) {
  int n = 3;
  char z = 'X';

  EXPECT_THROW(Octal test_obj(n, z), std::invalid_argument);
}

TEST(firstConstructorTest, BasicAssertions) {
  Octal test_obj {};

  EXPECT_EQ(test_obj.getArray(), nullptr);
  EXPECT_EQ(test_obj.getSize(), 0);
}

TEST(SecondConstructorTest2, BasicAssertions) {
  int n = 5;
  char value = '6';

  Octal test_obj(n, value);
  int test_size = test_obj.getSize(); 
  unsigned char* test_arr = test_obj.getArray();
  
  unsigned char ans_arr [] = "66666";
  int ans_size = 5;
  Octal ans = Builder().size(ans_size).arr(ans_arr).build();

  EXPECT_EQ(test_size, ans.getSize());
  for (int i = 0; i < test_size; i++){
    EXPECT_EQ(test_arr[i], ans.getArray()[i]);
  }

}

TEST(String_to_ConstructorTest, BasicAssertions) {

  Octal test_obj("33333");
  int test_size = test_obj.getSize(); 
  unsigned char* test_arr = test_obj.getArray();
  
  unsigned char ans_arr [] = "33333";
  int ans_size = 5;
  Octal ans = Builder().size(ans_size).arr(ans_arr).build();

  EXPECT_EQ(test_size, ans.getSize());
  for (int i = 0; i < test_size; i++){
    EXPECT_EQ(test_arr[i], ans.getArray()[i]);
  }
}

TEST(String_to_ConstructorError, BasicAssertions) {

  EXPECT_THROW(Octal obj{"klioform"};, std::invalid_argument);

}

TEST(Copy_Constructor, BasicAssertions){
  unsigned char ans_arr[] = "55555";
  int ans_size = 5;
  Octal ans = Builder().size(ans_size).arr(ans_arr).build();

  Octal test {ans};
  int test_size = test.getSize();

  EXPECT_EQ(test_size, ans.getSize());

  for (int i = 0; i<test_size; i++){
    EXPECT_EQ(test.getArray()[i], ans.getArray()[i]);
  }
}

TEST(SumTest, BasicAssertions){
  int FirstNumber_size = 3;
  int SecondNumber_size = 3;

  unsigned char FirstNum[] = "200";
  unsigned char SecondNum[] = "200";

  Octal First = Builder().size(FirstNumber_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNumber_size).arr(SecondNum).build();

  unsigned char ans_arr[] = "400";
  int ans_size = 3; 


  Octal res {First.operator+(Second)};
  
  EXPECT_EQ(res.getSize(), ans_size);
  for (int i = 0; i < res.getSize(); i++){
    EXPECT_EQ(res.getArray()[i], ans_arr[ans_size - i - 1]);
  }
}


TEST(SumTest2, BasicAssertions){
  int FirstNumber_size = 3;
  int SecondNumber_size = 1;

  unsigned char FirstNum[] = "120";
  unsigned char SecondNum[] = "1";

  Octal First = Builder().size(FirstNumber_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNumber_size).arr(SecondNum).build();

  unsigned char ans_arr[] = "121";
  int ans_size = 3; 


  Octal res {First.operator+(Second)};
  
  EXPECT_EQ(res.getSize(), ans_size);
  for (int i = 0; i < res.getSize(); i++){
    EXPECT_EQ(res.getArray()[i], ans_arr[ans_size - i - 1]);
  }
}

TEST(DifferenceTest, BasicAssertions){
  int FirstNumber_size = 3;
  int SecondNumber_size = 2;

  unsigned char FirstNum[] = "310";
  unsigned char SecondNum[] = "10";

  Octal Firstly = Builder().size(FirstNumber_size).arr(FirstNum).build();
  Octal Secondly = Builder().size(SecondNumber_size).arr(SecondNum).build();

  unsigned char ans_arr[] = "300";
  int ans_size = 3; 


  Octal res {Firstly.operator-(Secondly)};
  
  EXPECT_EQ(res.getSize(), ans_size);
  for (int i = 0; i < res.getSize(); i++){
    EXPECT_EQ(res.getArray()[i], ans_arr[ans_size - i - 1]);
  }
}
TEST(DifferenceOtherTest,BasicAssertions){
  int first_number_size=3;
  int second_number_size = 3;
  
  unsigned char FirstNum[] = "455";
  unsigned char SecondNum[] = "310";

  Octal Firstly = Builder().size(first_number_size).arr(FirstNum).build();
  Octal Secondly = Builder().size(second_number_size).arr(SecondNum).build();

  unsigned char ans_arr[] = "145";
  int ans_size = 3; 


  Octal res {Firstly.operator-(Secondly)};
  
  EXPECT_EQ(res.getSize(), ans_size);
  for (int i = 0; i < res.getSize(); i++){
    EXPECT_EQ(res.getArray()[i], ans_arr[ans_size - i - 1]);
  }
}

TEST(DifferenceTestError, BasicAssertions){
  int FirstNum_size = 3;
  int SecondNum_size = 2;

  unsigned char FirstNum[] = "110";
  unsigned char SecondNum[] = "10";

  Octal First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  EXPECT_THROW(Second.operator-(First);, std::logic_error);
}

TEST(EqualTest, BasicAssertions){
  int FirstNum_size = 3;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "700";
  unsigned char SecondNum[] = "700";

  Octal First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.equal(Second);

  EXPECT_EQ(ans, 1);  
}

TEST(EqualTest2, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "30";
  unsigned char SecondNum[] = "400";

  Octal First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.equal(Second);

  EXPECT_EQ(ans, 0);  
}

TEST(MoreTest, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "20";
  unsigned char SecondNum[] = "300";

  Octal First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.more(Second);

  EXPECT_EQ(ans, 0);  
}

TEST(MoreTest2, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Octal First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = Second.more(First);

  EXPECT_EQ(ans, 1);  
}

TEST(LessTest, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Octal First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = Second.less(First);

  EXPECT_EQ(ans, 0);  
}

TEST(LessTest1, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Octal First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Octal Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.less(Second);

  EXPECT_EQ(ans, 1);  
}