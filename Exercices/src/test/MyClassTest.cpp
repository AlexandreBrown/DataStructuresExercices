#include <gtest/gtest.h>
#include "../main/MyClass.h"

namespace {
class MyClassTest : public testing::Test {

 public:
  MyClass myClass;

  void SetUp() override {
	myClass = MyClass();
  }
};
}

TEST_F(MyClassTest, ContainsCycle_returns_true_when_list_contains_cycle) {

  auto item = std::rand();
  auto list = std::forward_list<int>{std::rand(), item, std::rand(), item, std::rand()};

  auto containsCycle = myClass.ContainsCycle(list);

  ASSERT_TRUE(containsCycle);
}

TEST_F(MyClassTest, ContainsCycle_returns_false_when_list_contains_no_cycle) {

  auto list = std::forward_list<int>{std::rand(), std::rand()};

  auto containsCycle = myClass.ContainsCycle(list);

  ASSERT_FALSE(containsCycle);
}

TEST_F(MyClassTest, ContainsCycle_returns_false_when_list_is_empty) {

  auto list = std::forward_list<int>{};

  auto containsCycle = myClass.ContainsCycle(list);

  ASSERT_FALSE(containsCycle);
}

TEST_F(MyClassTest, Reverses_input_based_on_separator_space) {

  auto part1 = std::to_string(std::rand());
  auto part2 = std::to_string(std::rand());
  auto part3 = std::to_string(std::rand());
  auto input = part1 + " " + part2 + " " + part3;
  auto inputInReverse = part3 + " " + part2 + " " + part1;

  auto output = myClass.ReverseWords(input);

  ASSERT_EQ(inputInReverse, output);
}

TEST_F(MyClassTest, IsPalindrome_returns_true_when_word_is_same_when_reversing_characters) {

  auto palindrome = "laval";

  auto result = myClass.IsPalindrome(palindrome);

  ASSERT_TRUE(result);
}

TEST_F(MyClassTest, IsPalindrome_returns_false_when_word_is_not_same_when_reversing_characters) {

  auto palindrome = "lavals";

  auto result = myClass.IsPalindrome(palindrome);

  ASSERT_FALSE(result);
}