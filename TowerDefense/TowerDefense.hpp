#ifndef TOWERDEFENSE_HPP
#define TOWERDEFENSE_HPP
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <utility>
#include "MainMenuState.hpp"
#include "RunState.hpp"



class TowerDefense{
public:
  TowerDefense(sf::Vector2i windowSize,
               sf::Vector2i aspectRatio,
                        int framerate);
  ~TowerDefense() = default;
public:
  sf::RenderWindow* window = nullptr;
public:
  void start();
  void switchState(int newState);
  void run();
  GameState* getState(int newState);
private:
  GameState* currentState = nullptr;
  int currentSt = 1;
  sf::Vector2i windowSize;
  sf::Vector2i aspectRatio;
  int framerate = {};
};

#endif
