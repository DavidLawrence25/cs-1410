#include <string>

#ifndef CS1410_LABS_05BINARYNUMBER_BINARYNUMBER_H_
#define CS1410_LABS_05BINARYNUMBER_BINARYNUMBER_H_

namespace rose {

class Binary {
 public:
  Binary();
  Binary(int x);
  Binary(std::string s);

  int get_value();
  std::string ToString();

  Binary operator+();
  Binary operator-();

  Binary operator+(Binary other);
  Binary operator+(int other);
  void operator+=(Binary other);
  void operator+=(int other);

  Binary operator-(Binary other);
  Binary operator-(int other);
  void operator-=(Binary other);
  void operator-=(int other);

  Binary operator*(Binary other);
  Binary operator*(int other);
  void operator*=(Binary other);
  void operator*=(int other);

  Binary operator/(Binary other);
  Binary operator/(int other);
  void operator/=(Binary other);
  void operator/=(int other);

  Binary operator<<(Binary other);
  Binary operator<<(int other);
  void operator<<=(Binary other);
  void operator<<=(int other);

  Binary operator>>(Binary other);
  Binary operator>>(int other);
  void operator>>=(Binary other);
  void operator>>=(int other);

 private:
  int value_;
};

Binary operator+(int x, const Binary &y);
void operator+=(int x, const Binary &y);

Binary operator-(int x, const Binary &y);
void operator-=(int x, const Binary &y);

Binary operator*(int x, const Binary &y);
void operator*=(int x, const Binary &y);

Binary operator/(int x, const Binary &y);
void operator/=(int x, const Binary &y);

Binary operator<<(int x, const Binary &y);
void operator<<=(int x, const Binary &y);

Binary operator>>(int x, const Binary &y);
void operator>>=(int x, const Binary &y);

std::ostream &operator<<(std::ostream &out, Binary &x);

}

#endif  // CS1410_LABS_05BINARYNUMBER_BINARYNUMBER_H_