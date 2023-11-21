#include <iostream>
#include <vector>

#include "bulbasaur.h"
#include "charmander.h"
#include "squirtle.h"

int main() {
  std::vector<rose::Pokemon *> team = {};
  team.push_back(new rose::Bulbasaur(45, 49, 49, 45));
  team.push_back(new rose::Charmander(39, 52, 43, 65));
  team.push_back(new rose::Squirtle(44, 48, 65, 43));

  std::cout << "== YOUR POKEMON ==\n";
  for (rose::Pokemon *pokemon : team) std::cout << *pokemon << '\n';

  for (rose::Pokemon *pokemon : team) delete pokemon;
  return 0;
}
