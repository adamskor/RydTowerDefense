#include "Enemy.hpp"

Enemy::Enemy(){}

Mohammed::Mohammed(const std::map<std::string, sf::Texture*>& initTextures,
                   const std::vector<sf::Vector2f>& initPath){
  path = initPath;
  textures = initTextures;
  mohammed = std::make_unique<sf::Sprite>(*textures["Mohammed"]);
  mohammed->setPosition(-500,-500);
  mohammed->setScale(sf::Vector2f(0.2,0.2));
}

void Mohammed::onUpdate(const int ms){
  if (ms > 5){
    if (dead){
      return;
    }
    if (step != (int)path.size() && released && !dead){
      this->setPosition(path[step]);
      step++;
    }
    if (step == (int)path.size()){
      wentThrough = true;
      dead = true;
    }
  }
}

void Mohammed::setPosition(sf::Vector2f& position){
  auto sizeX = mohammed->getTexture()->getSize().x*mohammed->getScale().x;
  auto sizeY = mohammed->getTexture()->getSize().y*mohammed->getScale().y;
  mohammed->setPosition(position.x - sizeX/2, position.y - sizeY/2);
}

void Mohammed::onRender(sf::RenderWindow* window){
  if(!dead){
    window->draw(*mohammed);
  }
}
