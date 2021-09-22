#include "Enemy.hpp"

Enemy::Enemy(){}

Mohammed::Mohammed(std::map<std::string, sf::Texture*> initTextures,
                   const std::vector<sf::Vector2f>& initPath){
  path = initPath;
  textures = initTextures;
  mohammed = std::make_unique<sf::Sprite>(*textures["Mohammed"]);
  mohammed->setPosition(-50,-50);
  mohammed->setScale(sf::Vector2f(0.2,0.2));
}

void Mohammed::onUpdate(const int ms){
  if (ms > 20){
    if (dead){
      return;
    }
    if (step != (int)path.size() && released && !dead){
      mohammed->setPosition(path[step]);
      step++;
    }
    if (step == (int)path.size()){
      wentThrough = true;
      dead = true;
    }
  }
}

void Mohammed::onRender(sf::RenderWindow* window){
  if(!dead){
    window->draw(*mohammed);
  }
}
