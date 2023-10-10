#include "no_brainers/06_tic_tac_toe/tile.h"

#include <vector>

#ifndef CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_
#define CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_

namespace rose {

class Board {
 public:
  Board();
  Board(std::vector<Tile> tiles);
  Board(Board &other);

  Tile get_tile(int index);
  Tile get_tile(int row, int column);

  void set_tile(int index, Tile tile);
  void set_tile(int row, int column, Tile tile);

  bool LineExists(Tile line_type);

 private:
  std::vector<Tile> tiles_;
};

}

#endif  // CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_
