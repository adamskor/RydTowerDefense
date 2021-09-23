#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tower{
public:
  Tower();



};

class Aina : public Tower {
public:
  Aina(sf::Vector2f& position,
       const std::map<std::string, sf::Texture*>& initTextures);
  void setPosition(sf::Vector2f& position);

protected:
  std::map<std::string, sf::Texture*> textures;
  std::unique_ptr<sf::Sprite> aina;
  int cost = 50;
};
