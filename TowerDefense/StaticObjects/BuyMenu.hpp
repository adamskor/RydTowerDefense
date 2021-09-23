#pragma once
#include "../DynamicObjects/Enemy.hpp"
#include "PlayingField.hpp"
#include <SFML/Graphics.hpp>
class Button;
class AinaButton;

class BuyMenu{
public:
  BuyMenu(const std::map<std::string, sf::Texture*>& textures,
          const sf::Vector2i& windowSize, PlayingField*& playingfield);
  void updateEnemies(std::vector<Enemy*>& initEnemies);
  void initButtons();
  void onEvent(const sf::Event& event);
  void onRender(sf::RenderWindow* window);
  void onUpdate();

private:
  std::vector<Button*> buttons;
  std::vector<Enemy*> enemies;
  PlayingField* playingfield;
  std::map<std::string, sf::Texture*> textures;
  sf::Vector2i windowSize;
  int money = 1000;

};

class Button{
public:
  Button() = default;
  virtual void onEvent(const sf::Event& event) = 0;
  virtual void onRender(sf::RenderWindow* window) = 0;
  virtual void onUpdate() = 0;
};

class AinaButton : public Button{
public:
  AinaButton(sf::Vector2f position);
  bool isPressed(sf::Vector2f& mousePosition);
  void onEvent(const sf::Event& event) override{};
  void onRender(sf::RenderWindow* window) override;
  void onUpdate() override{};
private:
  sf::RectangleShape* button;
};
