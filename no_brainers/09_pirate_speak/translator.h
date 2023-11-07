#include <string>

#ifndef CS1410_NOBRAINERS_09PIRATESPEAK_TRANSLATOR_H_
#define CS1410_NOBRAINERS_09PIRATESPEAK_TRANSLATOR_H_

namespace rose {

// Represents a simple device to translate English to "pirate speak".
class Translator {
 public:
  Translator(std::string dictionary_path);
  // Returns the "pirate speak"-equivalent of the given English `word`.
  std::string TranslateWordToPirate(std::string word);
  // Returns the "pirate speak"-equivalent of the given English `sentence`.
  std::string TranslateSentenceToPirate(std::string sentence);
  // Adds a translation to the dictionary.
  void AddTranslation(std::string english, std::string pirate);

 private:
  std::string dictionary_path_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_09PIRATESPEAK_TRANSLATOR_H_
