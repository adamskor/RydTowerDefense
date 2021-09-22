#include "GameState.hpp"

GameState::GameState()
{
}

GameState::~GameState(){
  delete playingField;
  delete levelhandler;
  //TODO: Empty texture map
  //for (size_t i = 0; i < map.size(); i++){
  //  delete textures.at(i).second;
  //}
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
