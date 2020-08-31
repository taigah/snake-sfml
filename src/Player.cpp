#include "Player.hpp"

Player::Player () {
  this->bodyParts.push_back(std::make_pair(0,0));
  this->bodyParts.push_back(std::make_pair(1,0));
  this->bodyParts.push_back(std::make_pair(2,0));
}

void Player::growTowards (Direction d) {
  auto head = this->bodyParts.back();
  auto next = head;
  switch (d) {
    case Up:
      next.second += -1;
      break;
    case Right:
      next.first += 1;
      break;
    case Down:
      next.second += 1;
      break;
    case Left:
      next.first += -1;
      break;
  }
  this->growTo(next);
}

void Player::growTo (Pos p) {
  this->bodyParts.push_back(p);
}

void Player::retractTail () {
  this->bodyParts.pop_front();
}

void Player::render (std::shared_ptr<sf::RenderWindow> window) {
  const auto X_UNIT = window->getSize().x / GRID_WIDTH;
  const auto Y_UNIT = window->getSize().y / GRID_HEIGHT;
  auto rectangle = sf::RectangleShape();
  rectangle.setSize(sf::Vector2f(
    X_UNIT,
    Y_UNIT
  ));
  rectangle.setFillColor(sf::Color::White);
  for (auto pos : this->bodyParts) {
    rectangle.setPosition(pos.first * X_UNIT, pos.second * Y_UNIT);
    window->draw(rectangle);
  }
}
