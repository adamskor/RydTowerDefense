#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP
#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class MainMenuState : public GameState{
public:
  MainMenuState(sf::RenderWindow* window, sf::Vector2i windowSize,
                                          sf::Vector2i aspectRatio);
  ~MainMenuState() = default;
public:
  void shutDown() override;
  void onRender() override;
  void onUpdate() override{};
  void onEvent(sf::Event& event) override{};
  void nextLevel() override{};
private:
  sf::Vector2i windowSize;
  sf::Vector2i aspectRatio;
  sf::RenderWindow* window;
  sf::RectangleShape* rect= nullptr;
};
#endif
