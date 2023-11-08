#include "table_reader.h"

#include <fstream>

#include "custom_libraries/number_utils.h"

namespace rose {

std::ostream &operator<<(std::ostream &out, const Element &element) {
  out << "Number: " << element.number << '\n';
  out << "Name: " << element.name << '\n';
  out << "Symbol: " << element.symbol << '\n';
  out << "Mass: " << element.mass << '\n';
  return out;
}

TableReader::TableReader(std::string table_path) {
  table_path_ = table_path;
}

int TableReader::FindLineByNumber(std::string number) {
  std::ifstream table(table_path_);
  bool found_number = false;
  std::string this_number;
  int line = -1;

  while (table.good() && !found_number) {
    line = table.tellg();
    std::getline(table, this_number, ',');
    found_number = (this_number == number);
    std::getline(table, this_number, '\n');
  }

  return found_number ? line : -1;
}

int TableReader::FindLineBySymbol(std::string symbol) {
  std::ifstream table(table_path_);
  bool found_symbol = false;
  std::string this_symbol;
  int line = -1;

  while (table.good() && !found_symbol) {
    line = table.tellg();
    for (size_t i = 0; i < 3; ++i) std::getline(table, this_symbol, ',');
    found_symbol = (this_symbol == symbol);
    std::getline(table, this_symbol, '\n');
  }

  return found_symbol ? line : -1;
}

Element TableReader::ParseLine(int position) {
  if (position < 0) return {0, "Nullium", "Nu", 0.0};

  std::string number_as_string;
  std::string name;
  std::string symbol;
  std::string mass_as_string;

  std::ifstream table(table_path_);
  table.seekg(position);

  std::getline(table, number_as_string, ',');
  size_t number = StringToInt(number_as_string);
  std::getline(table, name, ',');
  std::getline(table, symbol, ',');
  std::getline(table, mass_as_string, '\n');
  float mass = StringToDouble(mass_as_string);

  return {number, name, symbol, mass};
}

}  // namespace rose
