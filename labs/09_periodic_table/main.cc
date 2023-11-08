#include <iostream>

#include "custom_libraries/user_input.h"
#include "table_reader.h"

typedef void (*MenuAction)(rose::TableReader&);

MenuAction Menu();
void Quit(rose::TableReader &table_reader);
void SearchNumber(rose::TableReader &table_reader);
void SearchSymbol(rose::TableReader &table_reader);

int main() {
  rose::TableReader table_reader = {"labs/09_periodic_table/elements.csv"};

  std::cout << "== PERIODIC TABLE LOOKUP ==\n";
  while (true) (*Menu())(table_reader);
}

MenuAction Menu() {
  return rose::MenuPrompt<MenuAction>(
      "1. Search by Atomic Number\n2. Search by Symbol\n3. Quit\n> ",
      "That's not an option. Please try again.\n",
      {{"1", SearchNumber}, {"2", SearchSymbol}, {"3", Quit}});
}

void Quit(rose::TableReader &table_reader) {
  std::exit(0);
}

void SearchNumber(rose::TableReader &table_reader) {
  int number = rose::GetInteger("Enter the Atomic Number: ",
                                "That's not an integer. Please try again.\n");
  int position = table_reader.FindLineByNumber(std::to_string(number));
  std::cout << '\n' << table_reader.ParseLine(position) << '\n';
}

void SearchSymbol(rose::TableReader &table_reader) {
  std::string symbol;
  std::cin.ignore();

  std::cout << "Enter the Symbol: ";
  std::getline(std::cin, symbol);
  int position = table_reader.FindLineBySymbol(symbol);
  std::cout << '\n' << table_reader.ParseLine(position) << '\n';
}
