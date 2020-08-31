#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

using Pos = std::pair<unsigned int, unsigned int>;

enum Direction {
  Up = 1,
  Right = 2,
  Down = -1,
  Left = -2
};
