#include <unordered_map>
#include <algorithm>
#include "MyClass.h"
#include <stack>
#include <string>
#include <sstream>

bool MyClass::ContainsCycle(const std::forward_list<int> &list) const {

  auto items = std::unordered_map<int, bool>();

  return std::any_of(list.begin(), list.end(), [&](int item) {
	if (items.find(item) != items.end()) {
	  return true;
	}
	items.insert({item, true});

	return false;
  });
}

std::string MyClass::ReverseWords(const std::string &input) const {

  auto words = std::stack<std::string>();

  std::istringstream inputSplitBySpace{input};
  std::string word;

  while(inputSplitBySpace >> word) {
	words.push(word);
  }

  std::string reversedInput;

  while (!words.empty()) {
	reversedInput += words.top();
	words.pop();
	if (!words.empty()) {
	  reversedInput += " ";
	}
  }

  return reversedInput;
}
bool MyClass::IsPalindrome(const std::string &input) const {
  return input == ReverseCharacters(input);
}

std::string MyClass::ReverseCharacters(const std::string &input) const {

  auto characters = std::stack<std::string>();

  for(const auto& character : input) {
	characters.push(std::string{character});
  }

  std::string reversedInput;

  while (!characters.empty()) {
	reversedInput += characters.top();
	characters.pop();
  }

  return reversedInput;
}
