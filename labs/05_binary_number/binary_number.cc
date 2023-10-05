#include "labs/05_binary_number/binary_number.h"

rose::Binary::Binary() {
  value_ = 0;
}

rose::Binary::Binary(int x) {
  value_ = x;
}

rose::Binary::Binary(std::string s) {
  int x = 0;
  bool is_negative = false;
  bool seen_first_char = false;

  for (char c : s) {
    if (!seen_first_char) {
      is_negative ^= c == '-';
      seen_first_char = true;
      continue;
    }

    x <<= 1;
    if (c == '1') {
      ++x;
    } else if (c != '0') {
      value_ = -1;
      return;
    }
  }

  value_ = x;
}

int rose::Binary::get_value() {
  return value_;
}

std::string rose::Binary::ToString() {
  int x = abs(value_);
  std::string s = "";

  do {
    s.insert(0, x % 2 == 1 ? "1" : "0");
    x >>= 1;
  } while (x > 0);

  if (value_ < 0) s.insert(0, "-");
  return s;
}
