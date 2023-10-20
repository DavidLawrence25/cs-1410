#include <time.h>

#include <iostream>
#include <random>

#include "custom_libraries/user_input.h"
#include "pokemon.h"

// Options the user can pick during battle.
enum BattleOption {
  kBattle,
  kQuit
};

int main() {
  const std::string kWinMessage = "You win\n";
  const std::string kLoseMessage = "You lose\n";

  std::random_device rd;
  std::mt19937 rng(rd());

  rose::Pokemon opponent = {/*name=*/"Pikachu", /*max_hp=*/10};

  std::string player_pokemon_name;
  std::cout << "Enter your Pokemon's name: ";
  std::cin >> player_pokemon_name;
  rose::Pokemon player = {/*name=*/player_pokemon_name, /*max_hp=*/10};

  BattleOption battle_option = kBattle;
  while (true) {
    std::cout << player.ToString() << '\n' << opponent.ToString() << '\n';

    battle_option = rose::MenuPrompt<BattleOption>(
        "(B)attle or (Q)uit: ", "Invalid input. Please try again\n",
        {{"b", kBattle}, {"B", kBattle}, {"q", kQuit}, {"Q", kQuit}});
    switch (battle_option) {
      case kBattle:
        rose::Pokemon::Battle(player, opponent, rng);
        break;
      case kQuit:
      default:
        std::cout << kLoseMessage;
        return 0;
    }

    if (player.is_dead()) {
      std::cout << kLoseMessage;
      return 0;
    } else if (opponent.is_dead()) {
      std::cout << kWinMessage;
      return 0;
    }
  }
}
