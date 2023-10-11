#include "no_brainers/06_tic_tac_toe/tile.h"

#include <string>
#include <vector>

#ifndef CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_
#define CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_

namespace rose {

class Player {
 public:
  Player(Tile tile_type);

  Tile get_tile_type();

  void set_tile_type(Tile tile_type);

  int RequestIndex(Board &board);
  void PlaceTile(Board &board, int index);

 private:
  Tile tile_type_;
};

}

#endif  // CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_