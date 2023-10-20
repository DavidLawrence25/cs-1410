#include <string>
#include <vector>

#include "tile.h"

#ifndef CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_
#define CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_

namespace rose {

// Represents a Tic-Tac-Toe board.
class Board {
 public:
  Board();
  Board(std::vector<Tile> tiles);
  Board(Board &other);

  Tile get_tile(int index);
  Tile get_tile(int row, int column);

  void set_tile(int index, Tile tile);
  void set_tile(int row, int column, Tile tile);

  // Returns true if a tile of type `tile_type` exists on the board.
  bool TileExists(Tile tile_type);
  // Returns true if a line of three tiles of type `tile_type` exists on the
  // board. Lines may be horizontal, vertical, or diagonal.
  bool LineExists(Tile line_type);
  std::string ToString();

  // Returns true if `index` corresponds to an existing empty tile in `board`.
  static bool CanPlaceTile(int index, Board board);
  // Returns true if `index` is within the confines of a Tic-Tac-Toe board.
  static bool IsValidIndex(int index);

 private:
  std::vector<Tile> tiles_;
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_06TICTACTOE_BOARD_H_
