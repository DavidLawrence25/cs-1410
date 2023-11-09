#include <stdlib.h>

#include <ostream>
#include <string>

#ifndef CS1410_LABS_09PERIODICTABLE_TABLEREADER_H_
#define CS1410_LABS_09PERIODICTABLE_TABLEREADER_H_

namespace rose {

// Represents an element in the Periodic Table of Elements.
struct Element {
  size_t number;
  std::string name;
  std::string symbol;
  double mass;

  friend std::ostream &operator<<(std::ostream &out, const Element &element);
};

// Represents an object that can read the Periodic Table of Elements.
class TableReader {
 public:
  TableReader(std::string table_path);

  // Returns the position of the line containing the element
  // with an atomic number of `number`.
  int FindLineByNumber(std::string number);
  // Returns the position of the line containing the element
  // represented by `symbol`.
  int FindLineBySymbol(std::string symbol);
  // Returns the element at `position` in the file as an Element object.
  Element ParseLine(int position);
  // Returns a modified version of `position` that
  // can be safely passed into `ParseLine`.
  int PurifyPosition(int position, std::string atomic_number);

 private:
  std::string table_path_;
};

}  // namespace rose

#endif  // CS1410_LABS_09PERIODICTABLE_TABLEREADER_H_
