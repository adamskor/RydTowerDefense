#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy{
public:
  Enemy();
  void initPath();
  void onRender(sf::RenderWindow* window);
protected:
  std::vector<sf::Vector2f> path;
  sf::Vector2f startPoint = sf::Vector2f(0,0);
};

class Mohammed : public Enemy {
public:
  Mohammed();
  void onUpdate();
  void onRender(sf::RenderWindow* window);

private:
  sf::RectangleShape* rect;
  int step = 0;
  bool dead = false;
};

#endif
