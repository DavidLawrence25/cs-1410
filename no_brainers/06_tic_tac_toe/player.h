#include "no_brainers/06_tic_tac_toe/tile.h"

#include <string>
#include <vector>

#ifndef CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_
#define CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_

namespace rose {

class Player {
 public:
  Player(std::string name, Tile tile_type);

  std::string get_name();
  Tile get_tile_type();

  void set_name(std::string name);
  void set_tile_type(Tile tile_type);

  std::vector<int> RequestPosition();
  void PlaceTile();

 private:
  std::string name_;
  Tile tile_type_;
};

}

#endif  // CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_