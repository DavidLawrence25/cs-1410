#include "no_brainers/06_tic_tac_toe/tile.h"

#include <string>
#include <vector>

#ifndef CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_
#define CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_

namespace rose {

// Represents a player of the game Tic-Tac-Toe.
class Player {
 public:
  Player(Tile tile_type);

  Tile get_tile_type();

  void set_tile_type(Tile tile_type);

  // Gets an index on the interval [0, 8] from the user. The corresponding tile
  // in `board` is guaranteed to be `kEmpty`.
  int RequestIndex(Board &board);
  // Sets the tile at `index` in `board` to the player's tile.
  void PlaceTile(Board &board, int index);

 private:
  Tile tile_type_;
};

}

#endif  // CS1410_NOBRAINERS_06TICTACTOE_PLAYER_H_