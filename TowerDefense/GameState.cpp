#include "GameState.hpp"

GameState::GameState()
{
}

void GameState::setNextState(int next){
  nextState = next;
}


int GameState::getNextState(){
  return nextState;
}

void GameState::loadTextures(){
  sf::Texture* texture{new sf::Texture()};
  texture->loadFromFile("TowerDefense/Assets/Textures/PlayingField.png");
  textures["Background"] = texture;
}
