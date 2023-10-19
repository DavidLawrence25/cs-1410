#include "labs/04_pig_game/die.h"

#include <random>

rose::Die::Die(int sides) {
  distribution_ = std::uniform_int_distribution<int>{1, sides};
}

rose::Die::Die(int sides, int value) {
  distribution_ = std::uniform_int_distribution<int>{1, sides};
  value_ = value;
}

int rose::Die::get_value() {
  return value_;
}

int rose::Die::get_sides() {
  return distribution_.b();
}

void rose::Die::set_distribution(
    std::uniform_int_distribution<int> distribution) {
  distribution_ = distribution;
}

// Sets value by rolling the die.
void rose::Die::Roll(std::mt19937 &rng) {
  value_ = distribution_(rng);
}
