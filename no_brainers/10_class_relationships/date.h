#include <ostream>

#ifndef CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_DATE_H_
#define CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_DATE_H_

namespace rose {

class Date {
 public:
  Date() {
    year_ = 1970;
    month_ = 1;
    day_ = 1;
  }

  Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
  }

  friend std::ostream &operator<<(std::ostream &out, Date &date);

 private:
  int year_;
  int month_;
  int day_;
};

std::ostream &operator<<(std::ostream &out, Date &date) {
  out << "Start Date: " << date.month_ << '-' << date.day_ << '-' << date.year_;
  return out;
}

}  // namespace rose

#endif  // CS1410_NOBRAINERS_10CLASSRELATIONSHIPS_DATE_H_
