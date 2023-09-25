#include <random>

#ifndef CS1410_LABS_04PIGGAME_DIE_H_
#define CS1410_LABS_04PIGGAME_DIE_H_

namespace rose {

class Die {
 public:
  Die(std::uniform_int_distribution<int> distribution);
  Die(std::uniform_int_distribution<int> distribution, int value);

  int get_value();
  int get_min_value();
  int get_max_value();
  void set_distribution(std::uniform_int_distribution<int> distribution);
  void Roll(std::mt19937 rng);

 private:
  std::uniform_int_distribution<int> distribution_;
  int value_;
};

}  // namespace rose

#endif  // CS1410_LABS_04PIGGAME_DIE_H_