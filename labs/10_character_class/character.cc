#include "character.h"

namespace rose {

Character::Character(int base_attack, int base_defense, float base_accuracy) {
  base_attack_ = base_attack;
  base_defense_ = base_defense;
  base_accuracy_ = base_accuracy;
  InitStatuses();
}

int Character::attack() {
  int computed = base_attack_;
  if (statuses_[kTiny].modifier == 1) computed >> 1;
  computed -= statuses_[kAttackDown].modifier;
  computed += statuses_[kAttackUp].modifier;
  return computed > 0 ? computed : 0;
}

int Character::defense() {
  return statuses_[kStone].modifier == 1 ? 128 : base_defense_;
}

float Character::accuracy() {
  float computed = base_accuracy_;
  if (statuses_[kDizzy].modifier == 1) computed *= 0.5;
  return computed;
}

float Character::vulnerability() {
  return statuses_[kInvisible].modifier == 1 ? 0.0f : 1.0f;
}

void Character::InitStatuses() {
  static const Status kUnassigned = {0, 0};
  for (const StatusType type : kAllStatusTypes) {
    statuses_.insert({type, kUnassigned});
  }
}

void Character::ResetStatuses() {
  static const Status kUnassigned = {0, 0};
  for (const StatusType type : kAllStatusTypes) statuses_[type] = kUnassigned;
}

void Character::SetStatus(StatusType type, Status status) {
  statuses_[type] = status;
}

void Character::EndTurn() {
  static const Status kUnassigned = {0, 0};
  for (const StatusType type : kAllStatusTypes) {
    Status *status = &statuses_[type];
    --status->turn_modifier;
    if (status->turn_modifier < 1) {
      status->modifier = 0;
      status->turn_modifier = 0;
    }
  }
}

}  // namespace rose
