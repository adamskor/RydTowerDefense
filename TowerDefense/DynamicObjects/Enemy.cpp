#include "Enemy.hpp"

Enemy::Enemy(){

}

void Enemy::initPath(){
  sf::Vector2i c1{800, 900};
  sf::Vector2i c2{800, 600};
  sf::Vector2i c3{600, 600};
  sf::Vector2i c4{400, 600};
  sf::Vector2i c5{400, 450};
  sf::Vector2i c6{300, 300};
  sf::Vector2i c7{200, 300};
  sf::Vector2i c8{200,100};
  sf::Vector2i c9{50,50};
  float length = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
  float slope = (c2.y - c1.y)/(c2.x - c1.x + 0.000001);
  int steps = (int)(length);
  for (int x = 0; x < 1600; x++){
    for (int y = 0; y < 900; y++){
      path.push_back(sf::Vector2f(x,y));
    }
  }
}


Mohammed::Mohammed(){
  initPath();
  rect = new sf::RectangleShape(sf::Vector2f(50,50));
  rect->setPosition(startPoint);
  rect->setFillColor(sf::Color::Blue);
}

void Mohammed::onUpdate(){
  if (step != (int)path.size()){
    rect->setPosition(path[step]);
    step++;
  }
}

void Mohammed::onRender(sf::RenderWindow* window){
  window->draw(*rect);
}
