#ifndef RUNSTATE_HPP
#define RUNSTATE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameState.hpp"
#include "StaticObjects/PlayingField.hpp"

class RunState : public GameState{
public:
  RunState(sf::RenderWindow* window, sf::Vector2i windowSize,
                                     sf::Vector2i aspectRatio);
  ~RunState() = default;
public:
  void printInfo() override;
  void onRender() override;
  void onUpdate() override;
  void shutDown() override;
  void onEvent(sf::Event& event) override{};
  void nextLevel() override;
private:
  sf::Vector2i windowSize;
  sf::Vector2i aspectRatio;
  sf::RenderWindow* window;
};

#endif
