#include <stdlib.h>

#include <ostream>
#include <string>
#include <unordered_map>

#ifndef CS1410_LABS_10CHARACTERCLASS_POKEMON_H_
#define CS1410_LABS_10CHARACTERCLASS_POKEMON_H_

namespace rose {

const size_t kNumOfPokemonTypes = 18;

struct TypeSpecifier {
  unsigned int bit_field : kNumOfPokemonTypes;
};

enum PokemonType {
  kNormal = 1,
  kFire = 2,
  kWater = 4,
  kGrass = 8,
  kFlying = 16,
  kFighting = 32,
  kPoison = 64,
  kElectric = 128,
  kGround = 256,
  kRock = 512,
  kPsychic = 1024,
  kIce = 2048,
  kBug = 4096,
  kGhost = 8192,
  kSteel = 16384,
  kDragon = 32768,
  kDark = 65536,
  kFairy = 131072
};

const std::unordered_map<PokemonType, std::string> kTypeNames = {
    {kNormal, "Normal"}, {kFire, "Fire"},         {kWater, "Water"},
    {kGrass, "Grass"},   {kFlying, "Flying"},     {kFighting, "Fighting"},
    {kPoison, "Poison"}, {kElectric, "Electric"}, {kGround, "Ground"},
    {kRock, "Rock"},     {kPsychic, "Psychic"},   {kIce, "Ice"},
    {kBug, "Bug"},       {kGhost, "Ghost"},       {kSteel, "Steel"},
    {kDragon, "Dragon"}, {kDark, "Dark"},         {kFairy, "Fairy"}};

class Pokemon {
 public:
  Pokemon();
  Pokemon(std::string name, TypeSpecifier type_spec, size_t hp, size_t atk,
          size_t def, size_t speed);

  std::string name() { return name_; }
  size_t max_hp() { return max_hp_; }
  size_t hp() { return hp_; }
  size_t base_atk() { return base_atk_; }
  size_t atk() { return base_atk_ + atk_modifier_; }
  size_t base_def() { return base_def_; }
  size_t def() { return base_def_ + def_modifier_; }
  size_t base_speed() { return base_speed_; }
  size_t speed() { return base_speed_ + speed_modifier_; }
  float accuracy() { return accuracy_; }

  bool IsType(PokemonType type);

  friend std::ostream &operator<<(std::ostream &out, Pokemon &pokemon);

 protected:
  std::string name_;
  TypeSpecifier type_spec_;
  size_t max_hp_;
  size_t hp_;
  size_t base_atk_;
  int atk_modifier_;
  size_t base_def_;
  int def_modifier_;
  size_t base_speed_;
  int speed_modifier_;
  float accuracy_;
};

}  // namespace rose

#endif  // CS1410_LABS_10CHARACTERCLASS_POKEMON_H_
