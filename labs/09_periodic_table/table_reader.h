#include <stdlib.h>

#include <ostream>
#include <string>

#ifndef CS1410_LABS_09PERIODICTABLE_TABLEREADER_H_
#define CS1410_LABS_09PERIODICTABLE_TABLEREADER_H_

namespace rose {

struct Element {
  size_t number;
  std::string name;
  std::string symbol;
  double mass;

  friend std::ostream &operator<<(std::ostream &out, const Element &element);
};

class TableReader {
 public:
  TableReader(std::string table_path);

  int FindLineByNumber(std::string number);
  int FindLineBySymbol(std::string symbol);
  Element ParseLine(int position);

 private:
  std::string table_path_;
};

}  // namespace rose

#endif  // CS1410_LABS_09PERIODICTABLE_TABLEREADER_H_