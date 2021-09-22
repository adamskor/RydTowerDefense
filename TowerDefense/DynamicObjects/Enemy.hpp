#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy{
public:
  Enemy();
  void initPath();
  virtual void onRender(sf::RenderWindow* window) = 0;
protected:
  std::vector<sf::Vector2f> path;
  sf::Vector2f startPoint = sf::Vector2f(0,0);
};

class Mohammed : public Enemy {
public:
  Mohammed();
  void onUpdate();
  void onRender(sf::RenderWindow* window);
public:
  void release(){released = true;};
  void kill(){dead = true;};
private:
  sf::RectangleShape* rect;
  int step = 0;
  bool dead = false;
  bool released = false;
};

#endif
