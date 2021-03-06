//
// Created by Guthorak on 10/22/18.
//

#ifndef __PIE_SRC_TILE_H
#define __PIE_SRC_TILE_H

#include <utility>
#include <vector>
#include <memory>

#include "optional.h"
#include "renderer/drawable.h"

namespace pie {

//! Class representing a single Tile on the game board
class Tile {
 public:
  Tile(size_t row, size_t column);

  Tile() = default;

  //! Returns true if the tile has a value
  bool IsSet() const;

  // getters
  const std::pair<size_t, size_t> &coordinates() const;
  const Optional<size_t> &value() const;
  const std::vector<std::shared_ptr<Tile>> &reachables() const;

  // setters
  void set_value(size_t value);
  void set_coordinates(size_t, size_t);

  //! Adds tile to list of reachable tiles from this
  void add_reachable(std::shared_ptr<Tile> tile);

 private:
  Optional<size_t> value_;
  std::vector<std::shared_ptr<Tile>> reachables_;
  std::pair<size_t, size_t> coordinates_;

};

} //namespace pie

#endif //__PIE_SRC_TILE_H

