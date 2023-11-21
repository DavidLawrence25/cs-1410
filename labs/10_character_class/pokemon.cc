#include "pokemon.h"

#include <bit>
#include <iomanip>
#include <sstream>

namespace rose {

Pokemon::Pokemon() {
  name_ = "Unnamed";
  type_spec_ = {kNormal};
  max_hp_ = 1;
  hp_ = 1;
  base_atk_ = 0;
  atk_modifier_ = 0;
  base_def_ = 0;
  def_modifier_ = 0;
  base_speed_ = 1;
  speed_modifier_ = 0;
  accuracy_ = 0.0f;
}

Pokemon::Pokemon(std::string name, TypeSpecifier type_spec, size_t hp,
                 size_t atk, size_t def, size_t speed) {
  name_ = name;
  type_spec_ = type_spec;
  max_hp_ = hp;
  hp_ = hp;
  base_atk_ = atk;
  atk_modifier_ = 0;
  base_def_ = def;
  def_modifier_ = 0;
  base_speed_ = speed;
  speed_modifier_ = 0;
  accuracy_ = 1.0f;
}

bool Pokemon::IsType(PokemonType type) {
  auto spec_number = std::bit_cast<uint32_t>(type_spec_);
  uint32_t type_number = type;
  return std::popcount(spec_number & type_number) == 1;
}

std::ostream &operator<<(std::ostream &out, Pokemon &pokemon) {
  const size_t kMaxSpecNumber = 1 + (1 << (kNumOfPokemonTypes - 1));
  std::stringstream type_repr;
  size_t types_found = 0;
  for (size_t i = 1; i < kMaxSpecNumber && types_found < 2; i <<= 1) {
    auto type = static_cast<PokemonType>(i);
    if (!pokemon.IsType(type)) continue;
    ++types_found;
    type_repr << kTypeNames.at(type) << ' ';
  }
  std::stringstream hp_repr;
  hp_repr << pokemon.hp() << '/' << pokemon.max_hp();

  out << pokemon.name() << "\n-----------------\n";
  out << type_repr.str() << "\n-----------------\n";
  out << "HP      | " << std::setw(7) << hp_repr.str() << '\n';
  out << "Attack  | " << std::setw(7) << pokemon.atk() << '\n';
  out << "Defense | " << std::setw(7) << pokemon.def() << '\n';
  out << "Speed   | " << std::setw(7) << pokemon.speed() << '\n';

  return out;
}

}  // namespace rose
