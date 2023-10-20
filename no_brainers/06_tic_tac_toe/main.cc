#include <iostream>
#include <vector>

#include "board.h"
#include "custom_libraries/cyclic_int.h"
#include "player.h"
#include "tile.h"

int main() {
  std::vector<rose::Player> player_pool = {{rose::kCross}, {rose::kCircle}};
  rose::Board board;
  rose::CyclicInt turn = {0, 1};

  std::cout << "== TIC TAC TOE ==\n" << board.ToString();
  for (rose::CyclicInt turn = {0, 1}; board.TileExists(rose::kEmpty); ++turn) {
    rose::Player player = player_pool[turn.get_value()];
    rose::Tile tile_type = player.get_tile_type();
    player.PlaceTile(board, player.RequestIndex(board));
    std::cout << board.ToString();
    if (board.LineExists(tile_type)) {
      std::cout << "Player " << rose::kTileChar.at(tile_type) << " wins!\n";
      return 0;
    }
  }
  std::cout << "It's a tie. :L\n";
  return 0;
}
