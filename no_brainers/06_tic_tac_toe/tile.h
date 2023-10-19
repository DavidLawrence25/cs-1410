#include <unordered_map>

#ifndef CS1410_NOBRAINERS_06TICTACTOE_TILE_H_
#define CS1410_NOBRAINERS_06TICTACTOE_TILE_H_

namespace rose {

// Represents a Tic-Tac-Toe tile.
enum Tile {
  kEmpty,
  kCross,
  kCircle
};

// Maps Tic-Tac-Toe tiles to the appropriate character
const std::unordered_map<Tile, char> kTileChar = {
  {kEmpty, ' '},
  {kCross, 'X'},
  {kCircle, 'O'}
};

}  // namespace rose

#endif  // CS1410_NOBRAINERS_06TICTACTOE_TILE_H_
