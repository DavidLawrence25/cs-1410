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

rose::Binary rose::Binary::operator+() {
  return *this;
}

rose::Binary rose::Binary::operator-() {
  return Binary(-value_);
}

rose::Binary rose::Binary::operator+(rose::Binary &other) {
  return Binary(value_ + other.value_);
}

rose::Binary rose::Binary::operator+(int other) {
  return Binary(value_ + other);
}

void rose::Binary::operator+=(rose::Binary &other) {
  value_ += other.value_;
}

void rose::Binary::operator+=(int other) {
  value_ += other;
}

rose::Binary rose::Binary::operator-(rose::Binary &other) {
  return Binary(value_ - other.value_);
}

rose::Binary rose::Binary::operator-(int other) {
  return Binary(value_ - other);
}

void rose::Binary::operator-=(rose::Binary &other) {
  value_ -= other.value_;
}

void rose::Binary::operator-=(int other) {
  value_ -= other;
}

rose::Binary rose::Binary::operator*(rose::Binary &other) {
  return Binary(value_ * other.value_);
}

rose::Binary rose::Binary::operator*(int other) {
  return Binary(value_ * other);
}

void rose::Binary::operator*=(rose::Binary &other) {
  value_ *= other.value_;
}

void rose::Binary::operator*=(int other) {
  value_ *= other;
}

rose::Binary rose::Binary::operator/(rose::Binary &other) {
  return Binary(value_ / other.value_);
}

rose::Binary rose::Binary::operator/(int other) {
  return Binary(value_ / other);
}

void rose::Binary::operator/=(rose::Binary &other) {
  value_ /= other.value_;
}

void rose::Binary::operator/=(int other) {
  value_ /= other;
}

rose::Binary rose::Binary::operator<<(rose::Binary &other) {
  return Binary(value_ << other.value_);
}

rose::Binary rose::Binary::operator<<(int other) {
  return Binary(value_ << other);
}

void rose::Binary::operator<<=(rose::Binary &other) {
  value_ <<= other.value_;
}

void rose::Binary::operator<<=(int other) {
  value_ <<= other;
}

rose::Binary rose::Binary::operator>>(rose::Binary &other) {
  return Binary(value_ >> other.value_);
}

rose::Binary rose::Binary::operator>>(int other) {
  return Binary(value_ >> other);
}

void rose::Binary::operator>>=(rose::Binary &other) {
  value_ >>= other.value_;
}

void rose::Binary::operator>>=(int other) {
  value_ >>= other;
}

bool rose::Binary::operator==(rose::Binary &other) {
  return value_ == other.value_;
}

bool rose::Binary::operator==(int other) {
  return value_ == other;
}

bool rose::Binary::operator!=(rose::Binary &other) {
  return value_ != other.value_;
}

bool rose::Binary::operator!=(int other) {
  return value_ != other;
}

bool rose::Binary::operator<(rose::Binary &other) {
  return value_ < other.value_;
}

bool rose::Binary::operator<(int other) {
  return value_ < other;
}

bool rose::Binary::operator<=(rose::Binary &other) {
  return value_ <= other.value_;
}

bool rose::Binary::operator<=(int other) {
  return value_ <= other;
}

bool rose::Binary::operator>(rose::Binary &other) {
  return value_ > other.value_;
}

bool rose::Binary::operator>(int other) {
  return value_ > other;
}

bool rose::Binary::operator>=(rose::Binary &other) {
  return value_ >= other.value_;
}

bool rose::Binary::operator>=(int other) {
  return value_ >= other;
}

rose::Binary operator+(int x, rose::Binary &y) {
  return rose::Binary(x + y.get_value());
}

void operator+=(int x, rose::Binary &y) {
  x += y.get_value();
}

rose::Binary operator-(int x, rose::Binary &y) {
  return rose::Binary(x - y.get_value());
}

void operator-=(int x, rose::Binary &y) {
  x -= y.get_value();
}

rose::Binary operator*(int x, rose::Binary &y) {
  return rose::Binary(x * y.get_value());
}

void operator*=(int x, rose::Binary &y) {
  x *= y.get_value();
}

rose::Binary operator/(int x, rose::Binary &y) {
  return rose::Binary(x / y.get_value());
}

void operator/=(int x, rose::Binary &y) {
  x /= y.get_value();
}

rose::Binary operator<<(int x, rose::Binary &y) {
  return rose::Binary(x << y.get_value());
}

void operator<<=(int x, rose::Binary &y) {
  x <<= y.get_value();
}

rose::Binary operator>>(int x, rose::Binary &y) {
  return rose::Binary(x >> y.get_value());
}

void operator>>=(int x, rose::Binary &y) {
  x >>= y.get_value();
}

bool operator==(int x, rose::Binary &y) {
  return x == y.get_value();
}

bool operator!=(int x, rose::Binary &y) {
  return x != y.get_value();
}

bool operator<(int x, rose::Binary &y) {
  return x < y.get_value();
}

bool operator<=(int x, rose::Binary &y) {
  return x <= y.get_value();
}

bool operator>(int x, rose::Binary &y) {
  return x > y.get_value();
}

bool operator>=(int x, rose::Binary &y) {
  return x >= y.get_value();
}

std::ostream &operator<<(std::ostream &out, rose::Binary &x) {
  out << x.ToString();
  return out;
}
