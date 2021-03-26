// Copyright 2021 TimurZaytsev

#include <iostream>
#include "postfix.h"
#include "string"
#include "MyStack.h"


int main() {
  std::string str("1 + 2 * 3 / (4 - 5)");
  std::cout << infix2postfix(str) << std::endl;  // 1 2 3 * 4 5 - / +
  str = ("(1 + 2) / (3 + 4 * 5.5) - 6.6 * 7.7");
  std::cout << infix2postfix(str) << std::endl;  
  // 1 2 + 3 4 5.5 * + / 6.6 7.7 * -
  str = "(1 * (2 - 3) + 4) * (5.5 + 6 * 7) - 8";
  std::cout << infix2postfix(str);  // 1 2 3 - * 4 + 5.5 6 7 * + * 8 -
  return 0;
}
