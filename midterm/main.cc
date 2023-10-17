#include <iostream>
#include <random>

#include "midterm/mastermind.cc"

void Menu();
void PlayGame();
void TestRandomColor(int &score);
void TestRandomCombination(int &score);
void TestGetPositionsCorrect(int &score);
void TestGetColorsCorrect(int &score);

template <class Type>
void CheckTest(std::string test_name, Type expected, Type reality, int &score);

int main() {
  int score = 0;
  TestRandomColor(score);
  TestRandomCombination(score);
  TestGetPositionsCorrect(score);
  TestGetColorsCorrect(score);
  std::cout << "\nScore: " << score << '\n';
  PlayGame();

  return 0;
}

void TestRandomColor(int &score) {
  rose::Mastermind game;
  int changes = 0;
  char previous_letter = 'E';

  for (int i = 0; i < 100; ++i) {
    char letter = game.get_random_letter();
    if (letter != previous_letter) {
      ++changes;
      previous_letter = letter;
    }
  }

  CheckTest("1. Get Random Letter Test", changes > 10, true, score);
}

void TestRandomCombination(int &score) {
  int mismatches = 0;
  rose::Mastermind game0;
  rose::Mastermind game1;

  for (int i = 0; i < 100; ++i) {
    game0.set_random_colors();
    game1.set_random_colors();

    if (game0.get_solution() != game1.get_solution()) ++mismatches;
  }

  CheckTest("2. Check Secret Combination", mismatches > 10, true, score);
}

void TestGetPositionsCorrect(int &score) {
  rose::Mastermind game;
  game.set_solution("ROBG");
  int positions_correct = game.get_positions_correct("ROBY");
  CheckTest("3. Check Positions Correct", positions_correct, 3, score);
}

void TestGetColorsCorrect(int &score) {
  rose::Mastermind game;
  game.set_solution("ROGB");
  int colors_correct = game.get_colors_correct("ROBY");
  CheckTest("4. Check Colors Correct", colors_correct, 1, score);

  game.set_solution("ROGR");
  if (game.get_colors_correct("ORYO") == 2) {
    ++score;
    std::cout << "Nice work on the challenge\n";
  }
}

template <class Type>
void CheckTest(std::string test_name, Type expected, Type reality, int &score) {
  if (expected == reality) {
    score += 5;
    std::cout << test_name << ": passed\n";
  } else {
    std::cout << test_name << ": failed\n";
  }
}

void PlayGame() {
  Menu();
  rose::Mastermind game;
  std::string guess;

  for (int i = 1; i < 11; ++i) {
    std::cout << "Guess #" << i << ": ";
    std::cin >> guess;

    int positions_correct = game.get_positions_correct(guess);
    int colors_correct = game.get_colors_correct(guess);

    if (positions_correct == 4) {
      std::cout << "Great Job: " << game.get_solution() << '\n';
      return;
    }
    std::cout << "Positions Correct: " << positions_correct << '\n';
    std::cout << "Colors Correct: " << colors_correct << '\n';
  }

  std::cout << "Sorry, the combination was: " << game.get_solution() << '\n';
}

void Menu() {
  std::cout << " __  __           _                      _           _\n";
  std::cout << "|  \\/  | __ _ ___| |_ ___ _ __ _ __ ___ (_)_ __   __| |\n";
  std::cout << "| |\\/| |/ _` / __| __/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` |\n";
  std::cout << "| |  | | (_| \\__ \\ ||  __/ |  | | | | | | | | | | (_| |\n";
  std::cout << "|_|  |_|\\__,_|___/\\__\\___|_|  |_| |_| |_|_|_| |_|\\__,_|\n";
  std::cout << "\n\nEnter four letters to guess: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, (P)urple\n\n";

  std::string str = "abcdefg"; // Unsure why this exists.
}
