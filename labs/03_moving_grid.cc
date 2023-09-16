#include <iostream>

#include "custom_libraries/user_input.h"

enum InputOptions {
  kNorth,
  kSouth,
  kEast,
  kWest,
  kQuit
};

// Prints the menu and returns the option the user picks.
InputOptions GetOption();

// Represents a point in the 2D cartesian coordinate system.
// Would make more sense as a class, but for the purposes of
// this assignment, it needs to be a struct.
struct Point {
  int x;
  int y;

  // Moves the point in a cardinal direction by one unit.
  void Move(InputOptions direction);
  // Returns a string containing an ordered pair.
  std::string ToString();
};

int main() {
  Point point = {0, 0};

  while (true) {
    InputOptions choice = GetOption();
    if (choice == kQuit) break;
    point.Move(choice);
    std::cout << "Position: " << point.ToString() << '\n';
  }

  return 0;
}

// Prints the menu and returns the option the user picks.
// Shorthand for a specific `rose::MenuPrompt` function call.
InputOptions GetOption() {
  return rose::MenuPrompt<InputOptions>(
      "1. North\n2. South\n3. East\n4. West\n5. Quit\n", "Invalid input.\n",
      {{"1", kNorth}, {"2", kSouth}, {"3", kEast}, {"4", kWest}, {"5", kQuit}});
}

// Moves the point in a cardinal direction by one unit.
// Assumes `direction` represents a cardinal direction.
void Point::Move(InputOptions direction) {
  switch (direction) {
    case kNorth:
      ++y;
      break;
    case kSouth:
      --y;
      break;
    case kEast:
      ++x;
      break;
    case kWest:
      --x;
      break;
  }
}

// Returns a string containing an ordered pair.
// Results are formatted like this: "(x, y)"
std::string Point::ToString() {
  std::string result = "(, )";
  result.insert(3, std::to_string(y));
  result.insert(1, std::to_string(x));
  return result;
}
