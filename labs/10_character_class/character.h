#include <stdlib.h>

#include <unordered_map>
#include <vector>

#ifndef CS1410_LABS_10CHARACTERCLASS_CHARACTER_H_
#define CS1410_LABS_10CHARACTERCLASS_CHARACTER_H_

namespace rose {

enum StatusType {
  kAsleep,
  kAttackDown,
  kAttackUp,
  kDizzy,
  kElectrified,
  kFrozen,
  kInjured,
  kInvisible,
  kPoisoned,
  kStone,
  kTiny
};

const std::vector<StatusType> kAllStatusTypes = {
    kAsleep, kAttackDown, kAttackUp, kDizzy, kElectrified, kFrozen, kInjured,
    kInvisible, kPoisoned, kStone, kTiny};

struct Status {
  size_t modifier;
  size_t turn_modifier;
};

class Character {
 public:
  Character(int base_attack, int base_defense, float base_accuracy);

  int attack();
  int defense();
  float accuracy();
  float vulnerability();

  void InitStatuses();
  void ResetStatuses();
  void SetStatus(StatusType type, Status status);
  void EndTurn();

 protected:
  int base_attack_;
  int base_defense_;
  float base_accuracy_;
  std::unordered_map<StatusType, Status> statuses_;
};

}  // namespace rose

#endif  // CS1410_LABS_10CHARACTERCLASS_CHARACTER_H_
