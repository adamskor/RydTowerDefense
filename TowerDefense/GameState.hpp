#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "StaticObjects/PlayingField.hpp"
#include "DynamicObjects/Enemy.hpp"

class GameState{
public:
  GameState();
  ~GameState() = default;
public:
  virtual void printInfo(){};
  virtual void onRender() = 0;
  virtual void onUpdate() = 0;
  virtual void onEvent(sf::Event& event) = 0;
public:
  int getNextState();
  void setNextState(int next);
  void loadTextures();
public:
  PlayingField* playingField = nullptr;
  std::vector<Enemy*> enemies = {nullptr};
protected:
  int nextState = 1;
  std::map<std::string, sf::Texture*> textures;
  std::string texturePath = "TowerDefense/Assets/Textures";

};

#endif
