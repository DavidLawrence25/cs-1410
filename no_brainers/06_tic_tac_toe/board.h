#include "no_brainers/06_tic_tac_toe/tile.h"

#ifndef CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_
#define CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_

namespace rose {

class Board {
 public:
  Board();
  Board(Tile tiles[9]);
  Board(Board &other);

  Tile *get_row(int index);
  Tile *get_column(int index);
  Tile get_tile(int index);
  Tile get_tile(int row, int column);

  void set_tile(int index, Tile tile);
  void set_tile(int row, int column, Tile tile);

  bool LineExists(Tile line_type);

 private:
  Tile tiles_[9];
};

}

#endif  // CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_
