#include <SFML/Graphics.hpp>
#include "TowerDefense.hpp"

int main(){
  TowerDefense TD = TowerDefense(sf::Vector2i(1600, 900), sf::Vector2i(19, 9), 60);
  TD.start();
  return 0;
}
