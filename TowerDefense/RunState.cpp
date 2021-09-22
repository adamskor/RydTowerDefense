#include "RunState.hpp"

RunState::RunState(sf::RenderWindow* window, sf::Vector2i windowSize,
                                             sf::Vector2i aspectRatio) :
window{window}, windowSize{windowSize}, aspectRatio{aspectRatio}{
  loadTextures();
  playingField = new PlayingField(textures, windowSize, aspectRatio);
  levelhandler = new Level();
;}

void RunState::onRender(){
  playingField->onRender(window);

}

void RunState::onUpdate(){
  levelhandler->onUpdate();
}

void RunState::printInfo(){
  std::cout << nextState << std::endl;
  setNextState(0);
  std::cout << nextState << std::endl;
}
