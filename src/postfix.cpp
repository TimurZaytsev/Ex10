// Copyright 2020 TimurZaytsev

#include "postfix.h"
#include <string>
#include <utility>
#include <vector>

#include "MyStack.h"

std::string infix2postfix(std::string str1) {
  MyStack<char> stack(100);
  std::string str2;
  for (auto i = 0; i < str1.length(); i++) {
    if (str1[i] <= '9' && str1[i] >= '0') {
      while (str1[i] >= '0' && str1[i] <= '9' || str1[i] == '.') {
        str2 += str1[i];
        ++i;
      }
      --i;
      str2 = str2 + ' ';
    } else if (str1[i] == '(') {
      stack.push(str1[i]);
    } else if (str1[i] == '*' || str1[i] == '/') {
      if (stack.isEmpty()) {
        stack.push(str1[i]);
      } else if (stack.get() == '*' || stack.get() == '/') {
        str2 += stack.pop();
        str2 += ' ';
        stack.push(str1[i]);
      } else {
        stack.push(str1[i]);
      }
    } else if (str1[i] == '+' || str1[i] == '-') {
      if (!stack.isEmpty() && stack.get() != '(') {
        str2 = str2 + stack.pop();
        str2 = str2 + ' ';
      }
      stack.push(str1[i]);
    } else if (str1[i] == ')') {
      while (stack.get() != '(') {
        str2 = str2 + stack.pop();
        str2 = str2 + ' ';
      }
      stack.pop();
    }
  }
  while (!stack.isEmpty()) {
    str2 = str2 + stack.pop();
    str2 = str2 + ' ';
  }
  str2.erase(str2.length() - 1);
  return str2;
}
