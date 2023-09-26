#include <random>

#include "labs/04_pig_game/die.cc"

#ifndef CS1410_LABS_04PIGGAME_PIGPLAYER_H_
#define CS1410_LABS_04PIGGAME_PIGPLAYER_H_

namespace rose {

// Represents a player of the game Pig.
class PigPlayer {
 public:
  int get_die_value();
  int get_turn_total();
  int get_game_total();

  // Returns true if the reward for a successful roll outweighs the risk.
  bool ShouldMove(int goal);
  // Rolls the die and sets/resets the turn total accordingly.
  void RollDie(std::mt19937 &rng);
  // Adds the turn total to the game total and resets the turn total.
  void EndTurn();

 private:
  rose::Die die_ = {/*sides=*/6};
  int turn_total_ = 0;
  int game_total_ = 0;
};

}  // namespace rose

#endif  // CS1410_LABS_04PIGGAME_PIGPLAYER_H_
