#pragma once

#include <cstdlib>
#include <memory>

#include "constants.hpp"
#include "utils.hpp"

class Cherry {
public:
  Pos position;

  Cherry();
  void resetPosition();
  void render(std::shared_ptr<sf::RenderWindow>);
};
