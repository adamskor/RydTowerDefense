#ifndef LEVELHANDLER_HPP
#define LEVELHANDLER_HPP
#include <SFML/Graphics.hpp>
#include "DynamicObjects/Enemy.hpp"
#include "DynamicObjects/Tower.hpp"
#include <iostream>


class LevelHandler{
public:
  LevelHandler(std::map<std::string, sf::Texture*> textures,
               const sf::Vector2i& windowSize);
  ~LevelHandler() = default;
  void initPath();
  void AtoB(const sf::Vector2f& from, const sf::Vector2f& to);
public:
  void shutDown();
  void onRender(sf::RenderWindow* window);
  void onUpdate();
public:
  void nextLevel();
  void endLevel();
  void releaseEnemy();
private:
  sf::Vector2i windowSize;
  std::vector<sf::Vector2f> path;
  std::vector<Enemy*> enemies = {};
  std::vector<Tower*> towers = {};
  int healthPoints = 100;
  int level = 1;
  int nEnemies = 0;
  int deadCount = 0;
  int released = 0;
  float speed = 1.0;
  float releaseSpeed = 1.0;
  bool activeLevel = false;
  sf::Clock clock;
  sf::Clock speedClock;
protected:
  std::map<std::string, sf::Texture*> textures;



};



#endif
