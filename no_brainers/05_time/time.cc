#include "time.h"

#include <iostream>
#include <string>

rose::Time::Time() {
  hours_ = 0;
  minutes_ = 0;
  seconds_ = 0;
}

rose::Time::Time(int seconds) {
  hours_ = 0;
  minutes_ = 0;
  seconds_ = seconds;
  Adjust();
}

rose::Time::Time(int hours, int minutes, int seconds) {
  hours_ = hours;
  minutes_ = minutes;
  seconds_ = seconds;
  Adjust();
}

rose::Time rose::Time::operator+(Time other) {
  int hours = hours_ + other.hours_;
  int minutes = minutes_ + other.minutes_;
  int seconds = seconds_ + other.seconds_;

  rose::Time time = {hours, minutes, seconds};
  time.Adjust();

  return time;
}

rose::Time rose::Time::operator+(int seconds) {
  rose::Time time = {hours_, minutes_, seconds_ + seconds};
  time.Adjust();

  return time;
}

void rose::Time::operator+=(int seconds) {
  seconds_ += seconds;
  Adjust();
}

std::ostream &rose::operator<<(std::ostream &out, rose::Time &time) {
  out << std::to_string(time.get_hours()) << ':';
  if (time.get_minutes() < 10) out << '0';
  out << std::to_string(time.get_minutes()) << ':';
  if (time.get_seconds() < 10) out << '0';
  out << std::to_string(time.get_seconds());
  return out;
}

int rose::Time::get_hours() {
  return hours_;
}

int rose::Time::get_minutes() {
  return minutes_;
}

int rose::Time::get_seconds() {
  return seconds_;
}

// Adjusts the time such that `seconds_ < 60` and `minutes_ < 60`.
// Example: `21:69:420 -> 22:16:00`
void rose::Time::Adjust() {
  div_t minutes_and_seconds = div(seconds_, 60);
  div_t hours_and_minutes = div(minutes_and_seconds.quot + minutes_, 60);
  hours_ += hours_and_minutes.quot;
  minutes_ = hours_and_minutes.rem;
  seconds_ = minutes_and_seconds.rem;
}
