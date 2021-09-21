#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, sf::Vector2i windowSize,
                                                       sf::Vector2i aspectRatio) :
window{window}, windowSize{windowSize}, aspectRatio{aspectRatio}{
  rect = new sf::RectangleShape(sf::Vector2f(100,100));
  rect->setPosition(500,500);
  rect->setFillColor(sf::Color::Blue);
}

void MainMenuState::onRender(){
  window->draw(*rect);
}
