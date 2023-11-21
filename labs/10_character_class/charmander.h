#include "pokemon.h"

#ifndef CS1410_LABS_10CHARACTERCLASS_CHARMANDER_H_
#define CS1410_LABS_10CHARACTERCLASS_CHARMANDER_H_

namespace rose {

class Charmander : public Pokemon {
 public:
  Charmander(size_t hp, size_t atk, size_t def, size_t speed)
      : Pokemon("Charmander", {kFire}, hp, atk, def, speed) {}
};

}  // namespace rose

#endif  // CS1410_LABS_10CHARACTERCLASS_CHARMANDER_H_
