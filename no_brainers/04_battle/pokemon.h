#include <random>

#ifndef CS1410_NOBRAINERS_04BATTLE_POKEMON_H_
#define CS1410_NOBRAINERS_04BATTLE_POKEMON_H_

namespace rose {

// Represents a basic Pokemon that can battle other Pokemon.
class Pokemon {
 public:
  Pokemon(std::string name, int max_hp);

  bool is_dead();
  // Returns a user-friendly string representation of the Pokemon.
  // Includes Pokemon's name and health bar.
  std::string ToString();
  // Sets the Pokemon's strength to a random value.
  void RandomizeStrength(std::mt19937 &rng);
  // Simulates one battle turn between two Pokemon.
  static void Battle(Pokemon &pokemon0, Pokemon &pokemon1, std::mt19937 &rng);
  // Subtracts a certain number of damage points from the Pokemon's HP.
  void TakeDamage(int damage_points);

 private:
  std::string name_;
  int max_hp_;
  int hp_;
  int strength_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_04BATTLE_POKEMON_H_
