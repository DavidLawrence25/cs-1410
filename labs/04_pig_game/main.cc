#include <time.h>
#include <windows.h>

#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

#include "custom_libraries/user_input.h"
#include "labs/04_pig_game/pig_player.cc"

// Types of turns specified by the player in control.
enum TurnType {
  kHuman,
  kComputer
};

// Options the human player can pick on their turn.
enum MenuOption {
  kRoll,
  kStop
};

// Prints the menu and returns the option the user picks.
MenuOption GameMenu(rose::PigPlayer human, rose::PigPlayer computer);

int main() {
  const int kGoal = 100;
  const std::string kWinMessage = "You win!\n";
  const std::string kLoseMessage = "You lose.\n";
  const std::string kHumanTurnMessage = "-- YOUR TURN --\n\n";
  const std::string kComputerTurnMessage = "-- COMPUTER'S TURN --\n\n";

  std::random_device rd;
  std::mt19937 rng(rd());

  rose::PigPlayer human;
  rose::PigPlayer computer;
  TurnType turn = kHuman;
  MenuOption option;

  std::cout << "== GAME OF PIG ==\n\n" << kHumanTurnMessage;
  while (human.get_game_total() < kGoal
      && computer.get_game_total() < kGoal) {
    Sleep(250);  // Optional delay to make the game a little easier to follow.

    if (turn == kComputer) {
      if (!computer.ShouldMove(kGoal)) {
        computer.EndTurn();
        turn = kHuman;
        std::cout << "Computer ended their turn.\n\n" << kHumanTurnMessage;
        continue;
      }

      computer.RollDie(rng);
      std::cout << "Computer rolled a " << computer.get_die_value() << ".\n";
      if (computer.get_die_value() == 1) {
        turn = kHuman;
        std::cout << '\n' << kHumanTurnMessage;
      }
      continue;
    }

    option = GameMenu(human, computer);
    std::cout << '\n';
    switch (option) {
      case kRoll:
        human.RollDie(rng);
        std::cout << "You rolled a " << human.get_die_value() << ".\n\n";
        if (human.get_die_value() == 1) {
          turn = kComputer;
          std::cout << kComputerTurnMessage;
        }
        break;
      case kStop:
        human.EndTurn();
        turn = kComputer;
        std::cout << "You ended your turn.\n\n" << kComputerTurnMessage;
        break;
      default:
        break;
    }
  }

  if (human.get_game_total() >= 100) {
    std::cout << kWinMessage;
  } else {
    std::cout << kLoseMessage;
  }

  return 0;
}

// Prints the menu and returns the option the user picks.
// Shorthand for a specific `rose::MenuPrompt` function call.
MenuOption GameMenu(rose::PigPlayer human, rose::PigPlayer computer) {
  std::stringstream prompt;
  prompt << "Turn Total: " << human.get_turn_total() << "\nGame Total: "
  << std::left << std::setw(4) << human.get_game_total()
  << "Computer Game Total: " << computer.get_game_total()
  << "\n(R)oll or (S)top: ";

  return rose::MenuPrompt<MenuOption>(
      prompt.str(), "Invalid input. Please try again\n",
      {{"r", kRoll}, {"R", kRoll}, {"s", kStop}, {"S", kStop}});
}
