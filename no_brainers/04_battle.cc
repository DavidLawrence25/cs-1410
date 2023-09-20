#include <time.h>

#include <iostream>
#include <random>
#include <sstream>

class Pokemon {
 public:
  Pokemon(std::string name, int max_hp = 10);

  bool is_dead();
  void randomize_strength(std::mt19937 &rng);
  std::string ToString();
  void Attack(Pokemon &target);
  void TakeDamage(int damage_points);

 private:
  std::string name_;
  int max_hp_;
  int hp_;
  int strength_;
};

int main() {
  Pokemon opponent = {"Pikachu"};
  std::string player_pokemon_name;

  std::cout << "Enter name player 1: ";
  std::cin >> player_pokemon_name;
  Pokemon player = {player_pokemon_name};
}

Pokemon::Pokemon(std::string name, int max_hp = 10) {
  name_ = name;
  max_hp_ = max_hp;
  hp_ = max_hp;
}

bool Pokemon::is_dead() {
  return hp_ < 1;
}

void Pokemon::randomize_strength(std::mt19937& rng) {
  std::uniform_int_distribution<int> strength_distribution(0, 16);
  strength_ = strength_distribution(rng);
}

std::string Pokemon::ToString() {
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

void Pokemon::Attack(Pokemon &target) {
  target.TakeDamage(0);  // TODO: Implement logic.
}

void Pokemon::TakeDamage(int damage_points) {
  if (hp_ > damage_points) {
    hp_ -= damage_points;
  } else {
    hp_ = 0;
  }
}
