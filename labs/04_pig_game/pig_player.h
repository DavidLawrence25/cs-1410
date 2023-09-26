#include <random>

#include "labs/04_pig_game/die.cc"

#ifndef CS1410_LABS_04PIGGAME_PIGPLAYER_H_
#define CS1410_LABS_04PIGGAME_PIGPLAYER_H_

namespace rose {

class PigPlayer {
 public:
  bool CanMove();
  bool ShouldMove();
  void RollDie(std::mt19937 rng);

 private:
  rose::Die die_ = {/*sides=*/6};
  int turn_total_ = 0;
  int game_total_ = 0;
};

}  // namespace rose

#endif  // CS1410_LABS_04PIGGAME_PIGPLAYER_H_
