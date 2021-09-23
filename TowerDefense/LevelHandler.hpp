#ifndef LEVELHANDLER_HPP
#define LEVELHANDLER_HPP
#include <SFML/Graphics.hpp>
#include "DynamicObjects/Enemy.hpp"
#include "DynamicObjects/Tower.hpp"
#include "StaticObjects/BuyMenu.hpp"
#include "StaticObjects/PlayingField.hpp"
#include "MathUtil.hpp"
#include <iostream>


class LevelHandler{
public:
  LevelHandler(const std::map<std::string, sf::Texture*>& textures,
               const sf::Vector2i& windowSize, PlayingField*& playingfield);
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
  MathUtil mathUtil = MathUtil();
private:
  sf::Vector2i windowSize;
  std::vector<sf::Vector2f> path;
  std::vector<Enemy*> enemies = {};
  BuyMenu* buymenu = nullptr;
  PlayingField* playingfield;
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
