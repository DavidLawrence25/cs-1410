#include <iostream>

#include "custom_libraries/user_input.h"

enum InputOptions {
  kNorth,
  kSouth,
  kEast,
  kWest,
  kQuit
};

InputOptions GetOption();

struct Point {
 public:
  int x;
  int y;

  void Move(InputOptions direction);
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

InputOptions GetOption() {
  return rose::MenuPrompt<InputOptions>(
      "1. North\n2. South\n3. East\n4. West\n5. Quit\n", "Invalid input.\n",
      {{"1", kNorth}, {"2", kSouth}, {"3", kEast}, {"4", kWest}, {"5", kQuit}});
}

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

std::string Point::ToString() {
  std::string result = "(, )";
  result.insert(3, std::to_string(y));
  result.insert(1, std::to_string(x));
  return result;
}
