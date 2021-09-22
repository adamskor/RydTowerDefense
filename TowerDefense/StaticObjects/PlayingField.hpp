#ifndef PLAYINGFIELD_HPP
#define PLAYINGFIELD_HPP
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <memory>
struct Squares;

class PlayingField{
public:
  PlayingField() = default;
  PlayingField(std::map<std::string, sf::Texture*> textures,
               sf::Vector2i initWindowSize,
               sf::Vector2i aspectRatio);
  ~PlayingField();
public:
  void shutDown();
  void onRender(sf::RenderWindow* window);
public:
  void initSquares();
  void initPath();
  void switchBuymode();
private:
  std::vector<sf::Vector2i> path;
  std::map<std::string, sf::Texture*> textures;
  std::unique_ptr<sf::Sprite> field;
  bool buyMode = false;
  std::vector<std::unique_ptr<Squares>> squares;
  sf::Vector2i windowSize;
  sf::Vector2i aspectRatio;

};

class Squares{
public:
  Squares(sf::Vector2f size, sf::Vector2f position);
  void shutDown();
  void onRender(sf::RenderWindow* window);

  void switchOccupied();

  sf::RectangleShape* rect;
  bool occupied = false;

};

#endif
