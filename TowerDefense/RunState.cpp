#include "RunState.hpp"

RunState::RunState(sf::RenderWindow* window, sf::Vector2i windowSize,
                                             sf::Vector2i aspectRatio) :
window{window}, windowSize{windowSize}, aspectRatio{aspectRatio}{
  loadTextures();
  playingField = new PlayingField(textures, windowSize, aspectRatio);
  enemies = new Enemy();
}

void RunState::onRender(){
  playingField->onRender(window);
  for (size_t i = 0; i < enemies.size(); i++){
    enemies[i]->onRender(window);
  }
}

void RunState::printInfo(){
  std::cout << nextState << std::endl;
  setNextState(0);
  std::cout << nextState << std::endl;
}
