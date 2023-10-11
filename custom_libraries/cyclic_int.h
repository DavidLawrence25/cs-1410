#ifndef CS1410_CUSTOMLIBRARIES_CYCLICINT_H_
#define CS1410_CUSTOMLIBRARIES_CYCLICINT_H_

namespace rose {

class CyclicInt {
 public:
  CyclicInt(int min, int max) {
    if (min <= max) {
      min_ = min;
      max_ = max;
    } else {
      min_ = max;
      max_ = min;
    }
    value_ = min_;
  }

  CyclicInt(CyclicInt &other) {
    min_ = other.min_;
    max_ = other.max_;
    value_ = other.value_;
  }

  int get_value() {
    return value_;
  }

  CyclicInt &operator++() {
    ++value_;
    if (value_ > max_) value_ = min_;
    return *this;
  }

  CyclicInt &operator--() {
    --value_;
    if (value_ < min_) value_ = max_;
    return *this;
  }

 private:
  int min_;
  int max_;
  int value_;
};

}

#endif  // CS1410_CUSTOMLIBRARIES_CYCLICINT_H_