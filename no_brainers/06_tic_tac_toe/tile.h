#include <unordered_map>

#ifndef CS1410_NOBRAINERS_06TICTACTOE_TILE_H_
#define CS1410_NOBRAINERS_06TICTACTOE_TILE_H_

namespace rose {

enum Tile {
  kEmpty,
  kCross,
  kCircle
};

const std::unordered_map<Tile, char> kTileChar = {
  {kEmpty, ' '},
  {kCross, 'X'},
  {kCircle, 'O'}
};

}

#endif  // CS1410_NOBRAINERS_06TICTACTOE_TILE_H_
