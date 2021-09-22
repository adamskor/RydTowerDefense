#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>

class Enemy{
public:
  Enemy();
  void initPath();
  virtual void onRender(sf::RenderWindow* window) = 0;
  virtual void onUpdate() = 0;
  virtual void release() = 0;
  virtual void resetWentThrough() = 0;
  virtual void kill() = 0;
  virtual bool getWentThrough() = 0;
  virtual bool getDead() = 0;
protected:
  std::vector<sf::Vector2f> path;
  std::map<std::string, sf::Texture*> textures;
  sf::Vector2f startPoint = sf::Vector2f(0,0);
};

class Mohammed : public Enemy {
public:
  Mohammed(std::map<std::string, sf::Texture*> initTextures,
           const std::vector<sf::Vector2f>& initPath);
  void onUpdate();
  void onRender(sf::RenderWindow* window);
public:
  void release(){released = true;};
  void kill(){dead = true;};
  void resetWentThrough(){wentThrough = false;};
  bool getWentThrough(){return wentThrough;};
  bool getDead(){return dead;};
public:
  bool wentThrough = false;
private:
  std::unique_ptr<sf::Sprite> mohammed;
  int step = 0;
  bool dead = false;
  bool released = false;

};

#endif
