#ifndef LEVELHANDLER_HPP
#define LEVELHANDLER_HPP
#include <SFML/Graphics.hpp>
#include "DynamicObjects/Enemy.hpp"


class LevelHandler{
public:
  LevelHandler();
  ~LevelHandler = default;
public:
  void onRender(sf::RenderWindow* window);
  void onUpdate();
public:
  void nextLevel();
  void releaseEnemy();
private:
  std::vector<Enemy*> enemies = {nullptr};
  int level = 1;
  bool activeLevel = false;
  sf::Clock clock;
protected:



};



#endif
