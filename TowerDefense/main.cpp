#include <SFML/Graphics.hpp>
#include "TowerDefense.hpp"

int main(){
  TowerDefense TD = TowerDefense(sf::Vector2i(800, 400), sf::Vector2i(2, 1), 180);
  TD.start();
  return 0;
}
