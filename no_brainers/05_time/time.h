#include <iostream>

#ifndef CS1410_NOBRAINERS_05TIME_TIME_H_
#define CS1410_NOBRAINERS_05TIME_TIME_H_

namespace rose {

// Represents a simple time in the format HH:MM:SS.
class Time {
 public:
  Time();
  Time(int seconds);
  Time(int hours, int minutes, int seconds);

  Time operator+(Time other_time);
  Time operator+(int seconds);
  void operator+=(int seconds);

  int get_hours();
  int get_minutes();
  int get_seconds();

 private:
  int hours_;
  int minutes_;
  int seconds_;

  // Adjusts the time such that `seconds_ < 60` and `minutes_ < 60`.
  void Adjust();
};

std::ostream &operator<<(std::ostream &out, Time &time);

}

#endif  // CS1410_NOBRAINERS_05TIME_TIME_H_
