#include <string>

#ifndef CS1410_NOBRAINERS_09PIRATESPEAK_TRANSLATOR_H_
#define CS1410_NOBRAINERS_09PIRATESPEAK_TRANSLATOR_H_

namespace rose {

class Translator {
 public:
  std::string TranslateWordToPirate(std::string word);
  std::string TranslateSentenceToPirate(std::string sentence);
  void AddTranslation(std::string english, std::string pirate);

 private:
  std::string dictionary_path_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_09PIRATESPEAK_TRANSLATOR_H_
