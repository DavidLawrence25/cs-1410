#include <iostream>

#include "custom_libraries/user_input.h"
#include "translator.h"

typedef void (*MenuAction)(rose::Translator&);

MenuAction Menu();
void AddWord(rose::Translator &translator);
void Quit(rose::Translator &translator);
void Translate(rose::Translator &translator);

int main() {
  rose::Translator translator = {"no_brainers/09_pirate_speak/pirate.csv"};
  while (true) {
    (*Menu())(translator);
    std::cout << '\n';
  }
}

MenuAction Menu() {
  std::cout << "Ahoy matey, ye be choozen yer menu.\n";
  return rose::MenuPrompt<MenuAction>(
      "1. Translate\n2. Add to Dictionary\n3. Quit\n",
      "Avast, me matey. That be not an option.\n",
      {{"1", Translate}, {"2", AddWord}, {"3", Quit}});
}

void AddWord(rose::Translator &translator) {
  std::string english;
  std::string pirate;
  std::cin.ignore();

  std::cout << "Enter yer English word: ";
  std::getline(std::cin, english);
  std::cout << "Enter th pirate bilge: ";
  std::getline(std::cin, pirate);

  translator.AddTranslation(english, pirate);
}

void Quit(rose::Translator &translator) {
  std::exit(0);
}

void Translate(rose::Translator &translator) {
  std::string english;
  std::cin.ignore();

  std::cout << "Enter yer English words: ";
  std::getline(std::cin, english);

  std::cout << "Here it be in pirate speak: ";
  std::cout << translator.TranslateSentenceToPirate(english) << '\n';
}
