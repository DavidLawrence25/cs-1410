#include <string>

#ifndef CS1410_LABS_05BINARYNUMBER_BINARYNUMBER_H_
#define CS1410_LABS_05BINARYNUMBER_BINARYNUMBER_H_

namespace rose {

// An admittedly overcomplicated wrapper around an integer
// that can convert its value to and from a binary string.
class Binary {
 public:
  Binary();
  Binary(int x);
  Binary(std::string s);
  Binary(Binary &other);

  int get_value();
  std::string ToString();

  Binary operator+();
  Binary operator-();

  Binary operator+(Binary &other);
  Binary operator+(int other);
  void operator+=(Binary &other);
  void operator+=(int other);

  Binary operator-(Binary &other);
  Binary operator-(int other);
  void operator-=(Binary &other);
  void operator-=(int other);

  Binary operator*(Binary &other);
  Binary operator*(int other);
  void operator*=(Binary &other);
  void operator*=(int other);

  Binary operator/(Binary &other);
  Binary operator/(int other);
  void operator/=(Binary &other);
  void operator/=(int other);

  Binary operator<<(Binary &other);
  Binary operator<<(int other);
  void operator<<=(Binary &other);
  void operator<<=(int other);

  Binary operator>>(Binary &other);
  Binary operator>>(int other);
  void operator>>=(Binary &other);
  void operator>>=(int other);

  bool operator==(Binary &other);
  bool operator==(int other);

  bool operator!=(Binary &other);
  bool operator!=(int other);

  bool operator<(Binary &other);
  bool operator<(int other);
  bool operator<=(Binary &other);
  bool operator<=(int other);

  bool operator>(Binary &other);
  bool operator>(int other);
  bool operator>=(Binary &other);
  bool operator>=(int other);

 private:
  int value_;
};

}

#endif  // CS1410_LABS_05BINARYNUMBER_BINARYNUMBER_H_