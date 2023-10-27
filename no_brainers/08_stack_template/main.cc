#include <iostream>

#include "stack.h"

int main() {
  std::cout << "== STACK VIA LINKED LIST ==\n";
  rose::Stack<std::string> stack;

  stack.Push("Raspberries");
  stack.Push("Cherries");
  stack.Push("Apples");
  stack.Push("Strawberries");
  stack.Push("Oranges");
  stack.Push("Pineapples");
  stack.Push("Lemons");
  stack.Push("Bananas");
  stack.Push("Avocados");
  stack.Push("Pears");
  stack.Push("Kiwis");
  stack.Push("Blueberries");
  stack.Push("Plums");

  std::cout << stack << '\n';

  for (int i = 0; i < 4; ++i) stack.Pop();

  std::cout << "-- AFTER REMOVING TOP 4 ITEMS --\n" << stack << '\n';

  return 0;
}
