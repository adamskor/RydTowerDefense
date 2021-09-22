#include <SFML/Graphics.hpp>
#include "TowerDefense.hpp"

int main(){
  TowerDefense TD = TowerDefense(sf::Vector2i(1600, 900), sf::Vector2i(16, 9), 200);
  TD.start();
  return 0;
}
