#pragma once

#include <deque>
#include <memory>
#include <iostream>
#include "constants.hpp"
#include "utils.hpp"

class Player {
public:
  std::deque<Pos> bodyParts;

  Player();

  void retractTail();
  void growTowards(Direction);
  void render (std::shared_ptr<sf::RenderWindow>);

private:
  void growTo(Pos);
};
