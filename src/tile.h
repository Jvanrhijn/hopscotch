//
// Created by Guthorak on 10/22/18.
//

#ifndef __PIE_SRC_TILE_H
#define __PIE_SRC_TILE_H

#include <utility>
#include <vector>
#include <memory>

#include "optional.h"

namespace pie {

class Tile {
 public:
  Tile(size_t row, size_t column);
  bool IsSet() const;

 public:
  const std::pair<size_t, size_t> &coordinates() const;
  const Optional<size_t> &value() const;
  const std::vector<std::shared_ptr<Tile>> &reachables() const;

  void set_value(const size_t value);

 private:
  Optional<size_t> value_;
  std::vector<std::shared_ptr<Tile>> reachables_;
  std::pair<size_t, size_t> coordinates_;

};

#endif //__PIE_SRC_TILE_H

} //namespace pie