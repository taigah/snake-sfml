#include <SFML/Graphics.hpp>
#include <memory>
#include <ctime>
#include "constants.hpp"
#include "Player.hpp"
#include "Cherry.hpp"

int main () {
  srand(time(nullptr));

  auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Snake");

  while (window->isOpen()) {
    auto player = std::make_shared<Player>();
    Cherry cherry;
    Direction d = Down;

    while (window->isOpen()) {
      bool hasChangedDirection = false;
      Direction newDirection;
      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window->close();
        } else if (event.type == sf::Event::KeyPressed) {
          switch (event.key.code) {
            case sf::Keyboard::Up:
              newDirection = Up;
              hasChangedDirection = true;
              break;
            case sf::Keyboard::Right:
              newDirection = Right;
              hasChangedDirection = true;
              break;
            case sf::Keyboard::Down:
              newDirection = Down;
              hasChangedDirection = true;
              break;
            case sf::Keyboard::Left:
              newDirection = Left;
              hasChangedDirection = true;
              break;
          }
        }
      }

      if (hasChangedDirection && d + newDirection != 0) {
        d = newDirection;
      }

      player->growTowards(d);
      auto head = player->bodyParts.back();
      if (head.first < 0 || head.first >= GRID_WIDTH
          || head.second < 0 || head.second >= GRID_HEIGHT) {
        break;
      }
      int i = 0;
      for (auto pos : player->bodyParts) {
        if (pos == head) i++;
      }
      if (i > 1) {
        break;
      }
      if (player->bodyParts.back() == cherry.position) {
        cherry.resetPosition();
      } else {
        player->retractTail();
      }

      window->clear(sf::Color::Black);
      
      player->render(window);
      cherry.render(window);

      window->display();

      sf::sleep(sf::seconds(0.1));
    }
  }

  return 0;
}
