#ifndef GTESTSETUP_MYCLASS_H
#define GTESTSETUP_MYCLASS_H

#include <forward_list>

class MyClass {
 public:

  bool ContainsCycle(const std::forward_list<int> &input) const;

  std::string ReverseWords(const std::string &input) const;

  bool IsPalindrome(const std::string &input) const;
 private:

  std::string ReverseCharacters(const std::string &input) const;
};

#endif
