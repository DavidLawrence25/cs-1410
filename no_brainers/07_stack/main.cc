#include <iostream>

#include "no_brainers/07_stack/stack.cc"

int main() {
  std::cout << "== STACK VIA LINKED LIST ==\n";
  rose::Stack stack;

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
