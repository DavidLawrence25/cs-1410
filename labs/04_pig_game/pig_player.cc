#include "labs/04_pig_game/pig_player.h"

#include <random>

int rose::PigPlayer::get_die_value() {
  return die_.get_value();
}

int rose::PigPlayer::get_turn_total() {
  return turn_total_;
}

int rose::PigPlayer::get_game_total() {
  return game_total_;
}

// Returns true if the reward for a successful roll outweighs the risk.
// The threshold used here originates from a risk-reward analysis.
// When using a D6, the threshold is...
// 6 * (6 + 1)
// ----------- - 1 = 20
//      2
// The threshold is the turn total at which the expected value
// of rolling the die is exactly zero.
// Will return false regardless if stopping would guarantee a win.
bool rose::PigPlayer::ShouldMove(int goal) {
  return turn_total_ + game_total_ < goal
  && turn_total_ < die_.get_sides() * (die_.get_sides() + 1) * 0.5 - 1;
}

// Rolls the die and sets/resets the turn total accordingly.
// The turn total resets to 0 if the player rolled a 1.
void rose::PigPlayer::RollDie(std::mt19937 &rng) {
  die_.Roll(rng);
  if (die_.get_value() == 1) {
    turn_total_ = 0;
  } else {
    turn_total_ += die_.get_value();
  }
}

// Adds the turn total to the game total and resets the turn total.
void rose::PigPlayer::EndTurn() {
  game_total_ += turn_total_;
  turn_total_ = 0;
}
