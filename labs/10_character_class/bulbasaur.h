#include "pokemon.h"

#ifndef CS1410_LABS_10CHARACTERCLASS_BULBASAUR_H_
#define CS1410_LABS_10CHARACTERCLASS_BULBASAUR_H_

namespace rose {

class Bulbasaur : public Pokemon {
 public:
  Bulbasaur(size_t hp, size_t atk, size_t def, size_t speed)
      : Pokemon("Bulbasaur", {kGrass + kPoison}, hp, atk, def, speed) {}
};

}  // namespace rose

#endif  // CS1410_LABS_10CHARACTERCLASS_BULBASAUR_H_
