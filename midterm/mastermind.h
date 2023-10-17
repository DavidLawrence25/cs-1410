#include <random>
#include <string>

#ifndef CS1410_MIDTERM_MASTERMIND_H_
#define CS1410_MIDTERM_MASTERMIND_H_

namespace rose {

class Mastermind {
 public:
  Mastermind();

  int get_colors_correct(std::string guess);
  int get_positions_correct(std::string guess);
  char get_random_letter();
  std::string get_solution();

  void set_random_colors();
  void set_solution(std::string solution);

 private:
  std::mt19937 rng_;
  std::string solution_;
};

}

#endif  // CS1410_MIDTERM_MASTERMIND_H_