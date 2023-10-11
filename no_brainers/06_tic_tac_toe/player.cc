#include "no_brainers/06_tic_tac_toe/player.h"

#include <sstream>
#include <string>
#include <vector>

#include "custom_libraries/user_input.h"
#include "no_brainers/06_tic_tac_toe/board.h"
#include "no_brainers/06_tic_tac_toe/tile.h"

rose::Player::Player(rose::Tile tile_type) {
  tile_type_ = tile_type;
}

rose::Tile rose::Player::get_tile_type() {
  return tile_type_;
}

void rose::Player::set_tile_type(rose::Tile tile_type) {
  tile_type_ = tile_type;
}

int rose::Player::RequestIndex(rose::Board &board) {
  std::stringstream prompt;
  prompt << rose::kTileChar.at(tile_type_);
  prompt << ": Select your move (press a number from 0-8, then press enter) ";
  return rose::GetInteger(prompt.str(), rose::Board::CanPlaceTile,
                          "Invalid move. Please try again\n",
                          "Invalid move. Please try again\n", board);
}

void rose::Player::PlaceTile(rose::Board &board, int index) {
  board.set_tile(index, tile_type_);
}
