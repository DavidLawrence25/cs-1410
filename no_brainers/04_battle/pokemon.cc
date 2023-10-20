#include "pokemon.h"

#include <random>
#include <sstream>

rose::Pokemon::Pokemon(std::string name, int max_hp) {
  name_ = name;
  max_hp_ = max_hp;
  hp_ = max_hp;
}

bool rose::Pokemon::is_dead() {
  return hp_ < 1;
}

// Returns a user-friendly string representation of the Pokemon.
// Example: `Pikachu: @@@@@@****`
std::string rose::Pokemon::ToString() {
  int hp_lost = max_hp_ - hp_;
  std::stringstream str;
  str << name_ << ": ";
  for (int i = 0; i < hp_; ++i) {
    str << '@';
  }
  for (int i = 0; i < hp_lost; ++i) {
    str << '*';
  }
  return str.str();
}

// Sets the Pokemon's strength to a uniformly random value.
// The possible range of values is [0, 4].
void rose::Pokemon::RandomizeStrength(std::mt19937& rng) {
  std::uniform_int_distribution<int> strength_distribution(0, 4);
  strength_ = strength_distribution(rng);
}

// Simulates one battle turn between two Pokemon.
// Randomizes both Pokemon's strength values, then damages the weaker Pokemon
// based on the difference between those strength values.
void rose::Pokemon::Battle(Pokemon &pokemon0, Pokemon &pokemon1,
                           std::mt19937 &rng) {
  pokemon0.RandomizeStrength(rng);
  pokemon1.RandomizeStrength(rng);

  int strength_difference = pokemon0.strength_ - pokemon1.strength_;

  if (strength_difference >= 0) {
    pokemon1.TakeDamage(strength_difference);
  } else {
    pokemon0.TakeDamage(-strength_difference);
  }
}

// Subtracts a certain number of damage points from the Pokemon's HP.
// Ensures HP will never drop below 0.
void rose::Pokemon::TakeDamage(int damage_points) {
  if (hp_ > damage_points) {
    hp_ -= damage_points;
  } else {
    hp_ = 0;
  }
}
