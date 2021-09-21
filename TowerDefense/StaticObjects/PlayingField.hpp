#ifndef PLAYINGFIELD_HPP
#define PLAYINGFIELD_HPP
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
struct Squares;

class PlayingField{
public:
  PlayingField() = default;
  PlayingField(std::map<std::string, sf::Texture*> textures,
               sf::Vector2i initWindowSize,
               sf::Vector2i aspectRatio);
public:
  void onRender(sf::RenderWindow* window);
public:
  void initSquares();
  void initPath();
  void switchBuymode();
private:
  std::vector<sf::Vector2i> path;
  std::map<std::string, sf::Texture*> textures;
  sf::Sprite* field = nullptr;
  bool buyMode = false;
  std::vector<Squares*> squares;
  sf::Vector2i windowSize;
  sf::Vector2i aspectRatio;

};

class Squares{
public:
  Squares(sf::Vector2f size, sf::Vector2f position);

  void onRender(sf::RenderWindow* window);

  void switchOccupied();

  sf::RectangleShape* rect;
  bool occupied = false;

};

#endif
