#include "PlayingField.hpp"


PlayingField::PlayingField(std::map<std::string, sf::Texture*> textures,
                           sf::Vector2i initWindowSize,
                           sf::Vector2i aspectRatio) :
textures{textures}, aspectRatio{aspectRatio}{
  windowSize = initWindowSize;
  field = new sf::Sprite(*textures["Background"]);
  field->setPosition(0,0);
  field->setScale(sf::Vector2f((float)windowSize.x/1920,
                               (float)windowSize.y/1080));
  initSquares();
}

void PlayingField::onRender(sf::RenderWindow* window){
  window->draw(*field);
  if (buyMode){
    for (size_t i = 0; i < squares.size(); i++){
      squares[i]->onRender(window);
    }
  }
}

void PlayingField::switchBuymode(){
  if(buyMode){
    buyMode = false;
  }
  else{
    buyMode = true;
  }
}

void PlayingField::initSquares(){
  int numberX = 50;
  int numberY = 30;
  float sizeX = (windowSize.x - windowSize.x/5)/numberX;
  float sizeY = windowSize.y/numberY;
  for (int x = 0; x < numberX; x++){
    for (int y = 0; y <numberY; y++){
      squares.push_back(new Squares(sf::Vector2f(sizeX, sizeY),
                                    sf::Vector2f(x*sizeX, y*sizeY)));
    }
  }
}

Squares::Squares(sf::Vector2f size, sf::Vector2f position){
  rect = new sf::RectangleShape(size);
  rect->setPosition(position);
  rect->setFillColor(sf::Color::Transparent);
  rect->setOutlineColor(sf::Color::Black);
  rect->setOutlineThickness(1);
}

void Squares::onRender(sf::RenderWindow* window){
  window->draw(*rect);
}

void Squares::switchOccupied(){
  if (occupied){
    occupied = false;
  }
  else{
    occupied = true;
  }
}
