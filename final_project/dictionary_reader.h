#include <random>
#include <string>

#ifndef CS1410_FINALPROJECT_DICTIONARYREADER_H_
#define CS1410_FINALPROJECT_DICTIONARYREADER_H_

namespace rose {

extern const std::string kLegalWordsPath;

struct Dictionary {
  std::string file_path;
  size_t length;
};

class DictionaryReader {
 public:
  bool IsLegal(std::string word);
  std::string GetRandomSolution(Dictionary &dict, std::mt19937 &rng);
};

}  // namespace rose

#endif  // CS1410_FINALPROJECT_DICTIONARYREADER_H_
