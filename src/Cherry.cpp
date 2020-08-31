#include "Cherry.hpp"

Cherry::Cherry () {
  this->resetPosition();
}

void Cherry::resetPosition () {
  this->position = std::make_pair(
    rand() % GRID_WIDTH,
    rand() % GRID_HEIGHT
  );
}

void Cherry::render (std::shared_ptr<sf::RenderWindow> window) {
  const auto X_UNIT = window->getSize().x / GRID_WIDTH;
  const auto Y_UNIT = window->getSize().y / GRID_HEIGHT;

  sf::RectangleShape cherry;
  cherry.setOrigin(X_UNIT / 4, Y_UNIT / 4);
  cherry.setFillColor(sf::Color::Red);
  cherry.setSize(sf::Vector2f(X_UNIT / 2, Y_UNIT / 2));
  cherry.setPosition(sf::Vector2f(
    X_UNIT * this->position.first + X_UNIT / 2,
    Y_UNIT * this->position.second + Y_UNIT / 2
  ));
  window->draw(cherry);
}
