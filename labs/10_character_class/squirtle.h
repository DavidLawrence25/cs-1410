#include "pokemon.h"

#ifndef CS1410_LABS_10CHARACTERCLASS_SQUIRTLE_H_
#define CS1410_LABS_10CHARACTERCLASS_SQUIRTLE_H_

namespace rose {

class Squirtle : public Pokemon {
 public:
  Squirtle(size_t hp, size_t atk, size_t def, size_t speed)
      : Pokemon("Squirtle", {kWater}, hp, atk, def, speed) {}
};

}  // namespace rose

#endif  // CS1410_LABS_10CHARACTERCLASS_SQUIRTLE_H_
