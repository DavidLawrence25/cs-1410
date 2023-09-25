#include "labs/04_pig_game/pig_player.h"

#include <random>

bool rose::PigPlayer::CanMove() {
  return die_.get_value() != 1;
}

bool rose::PigPlayer::ShouldMove() {
  // Note: If the computer could be uncertain, put rng as a parameter
}

void rose::PigPlayer::RollDie(std::mt19937 rng) {
  die_.Roll(rng);
}
