#include "BuyMenu.hpp"

BuyMenu::BuyMenu(const std::map<std::string, sf::Texture*>& textures,
        const sf::Vector2i& windowSize, PlayingField*& playingfield) :
playingfield{playingfield}, windowSize{windowSize}, textures{textures}{
  initButtons();
}

void BuyMenu::initButtons(){
  Button* ainaButton = new AinaButton(sf::Vector2f(1400, 100));
  buttons.push_back(ainaButton);
}

void BuyMenu::updateEnemies(std::vector<Enemy*>& initEnemies){
  enemies = initEnemies;
}

void BuyMenu::onRender(sf::RenderWindow* window){
  for (size_t i = 0; i < buttons.size(); i++){
      buttons[i]->onRender(window);
  }
}

void BuyMenu::onEvent(const sf::Event& event){
  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == sf::Mouse::Left){
        for (size_t i = 0; i < buttons.size(); i++){
            if (buttons[i]->isPressed()){

            }
        }
      }
}



AinaButton::AinaButton(sf::Vector2f position){
  button = new sf::RectangleShape(sf::Vector2f(100, 50));
  button->setPosition(position);
}

void AinaButton::onRender(sf::RenderWindow* window){
  window->draw(*button);
}

bool AinaButton::isPressed(sf::Vector2f& mousePosition){
  if (mousePosition.x > button->getPosition().x &&
      mousePosition.x < button->getPosition().x + button->getSize().x &&
      mousePosition.y > button->getPosition().y &&
      mousePosition.y < button->getPosition().y + button->getSize().y){
        return true;
      } else {return false;}
}
