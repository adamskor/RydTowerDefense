#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "StaticObjects/PlayingField.hpp"
#include "LevelHandler.hpp"


class GameState{
public:
  GameState();
  ~GameState();;
public:
  virtual void printInfo(){};
  virtual void onRender() = 0;
  virtual void onUpdate() = 0;
  virtual void onEvent(sf::Event& event) = 0;
  virtual void shutDown() = 0;
  virtual void nextLevel() = 0;
public:
  int getNextState();
  void setNextState(int next);
  void loadTextures();
public:
  PlayingField* playingField = nullptr;
  LevelHandler* levelhandler = nullptr;

protected:
  std::unique_ptr<sf::Texture> texture = {};
  int nextState = 1;
  std::map<std::string, sf::Texture*> textures;
  std::string texturePath = "TowerDefense/Assets/Textures";

};

#endif
