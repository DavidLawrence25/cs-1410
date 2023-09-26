#include "labs/04_pig_game/pig_player.h"

#include <random>

bool rose::PigPlayer::CanMove() {
  return die_.get_value() != 1;
}

bool rose::PigPlayer::ShouldMove() {
  int n = die_.get_sides() * (die_.get_sides() + 1) * 0.5 - 1;
  return turn_total_ < n;
}

void rose::PigPlayer::RollDie(std::mt19937 rng) {
  die_.Roll(rng);
}
