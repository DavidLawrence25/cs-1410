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

// Returns the position of the line in the Periodic Table file
// containing the element with an atomic number of `number`.
// Returns -1 if no such element exists.
int TableReader::FindLineByNumber(std::string number) {
  std::ifstream table(table_path_);
  bool found_number = false;
  std::string this_number;
  int line = -1;

  while (table.good() && !found_number) {
    line = table.tellg();
    std::getline(table, this_number, ',');
    found_number = (this_number == number);
    std::getline(table, this_number);
  }

  return found_number ? PurifyPosition(line, number) : -1;
}

// Returns the position of the line in the Periodic Table file
// containing the element represented by `symbol`.
// Returns -1 if no such element exists.
int TableReader::FindLineBySymbol(std::string symbol) {
  std::ifstream table(table_path_);
  bool found_symbol = false;
  std::string this_symbol;
  std::string this_number;
  int line = -1;

  while (table.good() && !found_symbol) {
    line = table.tellg();
    std::getline(table, this_number, ',');
    std::getline(table, this_symbol, ',');
    std::getline(table, this_symbol, ',');
    found_symbol = (this_symbol == symbol);
    std::getline(table, this_symbol);
  }

  return found_symbol ? PurifyPosition(line, this_number) : -1;
}

// Returns the element at `position` in the file as an Element object.
// Returns a made-up element called Nullium if `position` is invalid.
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
  std::getline(table, mass_as_string);
  float mass = StringToDouble(mass_as_string);

  return {number, name, symbol, mass};
}

// Returns a modified version of `position` that
// can be safely passed into `ParseLine`.
// Purpose of existence and proof of algorithm's
// legitimacy are both unknown.
int TableReader::PurifyPosition(int position, std::string atomic_number) {
  int number = StringToInt(atomic_number);
  return number == 1 ? 0 : position + number - 118;
}

}  // namespace rose
