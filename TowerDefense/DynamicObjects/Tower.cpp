#include "Tower.hpp"

Tower::Tower(){

}

Aina::Aina(sf::Vector2f& position,
           const std::map<std::string, sf::Texture*>& initTextures){
  textures = initTextures;
  aina = std::make_unique<sf::Sprite>(*textures["Aina"]);
  aina->setScale(0.1, 0.1);
  aina->setPosition(position);
}

void Aina::setPosition(sf::Vector2f& position){
  auto sizeX = aina->getTexture()->getSize().x*aina->getScale().x;
  auto sizeY = aina->getTexture()->getSize().y*aina->getScale().y;
  aina->setPosition(position.x - sizeX/2, position.y - sizeY/2);
}
