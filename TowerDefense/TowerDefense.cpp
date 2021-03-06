#include "TowerDefense.hpp"

TowerDefense::TowerDefense(sf::Vector2i windowSize,
                           sf::Vector2i aspectRatio,
                                    int frameRate):
windowSize{windowSize}, aspectRatio{aspectRatio}, framerate{framerate}
{
  window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y),
                                    "RydTowerDefense");

  //sf::Style::Fullscreen

  window->setFramerateLimit(frameRate);

}

void TowerDefense::start(){
  currentSt = 1;
  currentState = getState(1);
  run();
}

void TowerDefense::run(){
  while (currentSt != -1 && window->isOpen()){
    sf::Event event;
    window->clear();
    while (window->pollEvent(event)){
      currentState->onEvent(event);
      if (event.type == sf::Event::Closed){
        window->close();
      }
      if (event.type == sf::Event::KeyPressed){
        currentState->nextLevel();
      }
    }
    currentState->onRender();
    currentState->onUpdate();
    window->display();
  }
}

void TowerDefense::switchState(int newState){
  if(currentState){
    currentState->shutDown();
    currentState = getState(newState);
    currentSt = newState;
    run();
  }
}

GameState* TowerDefense::getState(int stateID){
  GameState* newState = nullptr;
  switch(stateID){
    case 0 : newState = new MainMenuState(window, windowSize, aspectRatio);
             break;

    case 1 : newState = new RunState(window, windowSize, aspectRatio);
             break;


  }
  return newState;
}
