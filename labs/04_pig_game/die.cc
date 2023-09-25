#include "labs/04_pig_game/die.h"

#include <random>

rose::Die::Die(std::uniform_int_distribution<int> distribution) {
  distribution_ = distribution;
}

rose::Die::Die(std::uniform_int_distribution<int> distribution, int value) {
  distribution_ = distribution;
  value_ = value;
}

int rose::Die::get_value() {
  return value_;
}

int rose::Die::get_min_value() {
  return distribution_.min();
}

int rose::Die::get_max_value() {
  return distribution_.max();
}

void rose::Die::set_distribution(
    std::uniform_int_distribution<int> distribution) {
  distribution_ = distribution;
}

void rose::Die::Roll(std::mt19937 rng) {
  value_ = distribution_(rng);
}
