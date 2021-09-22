#include "LevelHandler.hpp"

LevelHandler::LevelHandler(std::map<std::string, sf::Texture*> textures,
                           const sf::Vector2i& windowSize)
: windowSize{windowSize}, textures{textures}{
  clock = sf::Clock();
  speedClock = sf::Clock();
  initPath();
}

void LevelHandler::shutDown(){

  for (size_t i = 0; i < enemies.size(); i++){
    if (enemies[i] != nullptr)
      delete enemies[i];
  }
}

void LevelHandler::onRender(sf::RenderWindow* window){
  if (activeLevel){
    for (size_t i = 0; i < enemies.size(); i++){
      if (enemies[i] != nullptr)
        enemies[i]->onRender(window);
    }
  }

}

void LevelHandler::onUpdate(){
  if (speedClock.getElapsedTime().asMilliseconds() > 30){
    speedClock.restart();
  }
  std::cout << speedClock.getElapsedTime().asMilliseconds() << std::endl;
  if (activeLevel){
    for (size_t i = 0; i < enemies.size(); i++){
      if (enemies[i] != nullptr)
        enemies[i]->onUpdate((int)speedClock.getElapsedTime().asMilliseconds());
      if (enemies[i]->getDead()){
        deadCount++;
      }
        if(enemies[i]->getWentThrough()){
          healthPoints -= 1;
          std::cout << healthPoints << std::endl;
          enemies[i]->resetWentThrough();
        }
      }
      if (deadCount == nEnemies){
        endLevel();
      } else {
        deadCount = 0;
      }
      if (clock.getElapsedTime().asSeconds() > 1*releaseSpeed){
        releaseEnemy();
        clock.restart();
      }
    }
}

void LevelHandler::releaseEnemy(){
  if (released == nEnemies){
    return;
  }
  enemies[released]->release();
  released++;
}


void LevelHandler::nextLevel(){
  if (!activeLevel){
    released = 0;
    activeLevel = true;
    nEnemies = 20*level + 20;
    for (int i = 0; i < nEnemies; i++){
      Enemy* tmp = new Mohammed(textures, path);
      enemies.push_back(tmp);
    }
  }
}

void LevelHandler::endLevel(){
  activeLevel = false;
  for (size_t i = 0; i < enemies.size(); i++){
    if (enemies[i] != nullptr)
      delete enemies[i];
  }
  enemies = {};
  level++;
}




























































































































































































































































































































































































































void LevelHandler::initPath(){
  std::vector<sf::Vector2f> pathVec = {};
  pathVec.push_back(sf::Vector2f(windowSize.x*0.639375, windowSize.y*0.996667));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.6425, windowSize.y*0.893333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.6475, windowSize.y*0.785556));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.649375, windowSize.y*0.71));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.650625, windowSize.y*0.608889));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.65125, windowSize.y*0.523333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.6525, windowSize.y*0.465556));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.649375, windowSize.y*0.446667));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.645, windowSize.y*0.432222));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.638125, windowSize.y*0.423333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.629375, windowSize.y*0.414444));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.6175, windowSize.y*0.41));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.59125, windowSize.y*0.414444));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.58375, windowSize.y*0.417778));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.573125, windowSize.y*0.426667));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.565625, windowSize.y*0.437778));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.559375, windowSize.y*0.452222));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.553125, windowSize.y*0.472222));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.548125, windowSize.y*0.492222));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.54375, windowSize.y*0.517778));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.54125, windowSize.y*0.54));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.539375, windowSize.y*0.715556));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.544375, windowSize.y*0.743333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.5525, windowSize.y*0.76));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.56625, windowSize.y*0.775556));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.58125, windowSize.y*0.776667));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.625625, windowSize.y*0.782222));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.61875, windowSize.y*0.923333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.166875, windowSize.y*0.923333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.159375, windowSize.y*0.805556));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.405, windowSize.y*0.8));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.404375, windowSize.y*0.568889));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.364375, windowSize.y*0.568889));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.36375, windowSize.y*0.773333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.31125, windowSize.y*0.775556));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.311875, windowSize.y*0.566667));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.255, windowSize.y*0.567778));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.255, windowSize.y*0.773333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.19875, windowSize.y*0.773333));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.196875, windowSize.y*0.566667));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.16375, windowSize.y*0.565556));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.16625, windowSize.y*0.0677778));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.47125, windowSize.y*0.0644444));
  pathVec.push_back(sf::Vector2f(windowSize.x*0.47375, windowSize.y*0.177778));

  for (size_t i = 0; i < pathVec.size() - 1; i++){
    AtoB(pathVec[i], pathVec[i + 1]);
  }
}

void LevelHandler::AtoB(const sf::Vector2f& from, const sf::Vector2f& to){
  int xDistance = abs(from.x - to.x);
  int yDistance = abs(from.y - to.y);
  if (from.x == to.x && from.y == to.y){
    return;
  }
  int longest = std::max(xDistance, yDistance);
  int shortest = std::min(xDistance, yDistance);
  float slope = (float)shortest/longest;
  if (longest == xDistance){
    int y = 0;
    if (from.x - to.x >= 0 && from.y - to.y > 0){
      for (int lng = from.x; lng > from.x - xDistance ; lng--){
        path.push_back(sf::Vector2f((float)lng, (float)y*slope + from.y));
        y--;
      }
    }
    if (from.x - to.x >= 0 && from.y - to.y < 0){
      for (int lng = from.x; lng > from.x - xDistance ; lng--){
        path.push_back(sf::Vector2f((float)lng, (float)y*slope + from.y));
        y++;
      }
    }
    if (from.x - to.x >= 0 && from.y - to.y == 0){
      for (int lng = from.x; lng > from.x - xDistance ; lng--){
        path.push_back(sf::Vector2f((float)lng, (float)from.y));
      }
    }
    if (from.x - to.x < 0 && from.y - to.y > 0){
      for (int lng = from.x; lng < from.x + xDistance ; lng++){
        path.push_back(sf::Vector2f((float)lng, (float)y*slope + from.y));
        y--;
      }
    }
    if (from.x - to.x < 0 && from.y - to.y < 0){
      for (int lng = from.x; lng < from.x + xDistance ; lng++){
        path.push_back(sf::Vector2f((float)lng, (float)y*slope + from.y));
        y++;
      }
    }
    if (from.x - to.x < 0 && from.y - to.y == 0){
      for (int lng = from.x; lng < from.x + xDistance ; lng++){
        path.push_back(sf::Vector2f((float)lng, (float)from.y));
      }
    }
  }
  if (longest == yDistance){
    int x = 0;
    if (from.y - to.y >= 0 && from.x - to.x > 0){
      for (int lng = from.y; lng > from.y - yDistance ; lng--){
        path.push_back(sf::Vector2f((float)x*slope + from.x, (float)lng));
        x--;
      }
    }
    if (from.y - to.y >= 0 && from.x - to.x < 0){
      for (int lng = from.y; lng > from.y - yDistance ; lng--){
        path.push_back(sf::Vector2f((float)x*slope + from.x, (float)lng));
        x++;
      }
    }
    if (from.y - to.y >= 0 && from.x - to.x == 0){
      for (int lng = from.y; lng > from.y - yDistance ; lng--){
        path.push_back(sf::Vector2f((float)from.x, (float)lng));
      }
    }
    if (from.y - to.y < 0 && from.x - to.x > 0){
      for (int lng = from.y; lng < from.y + yDistance ; lng++){
        path.push_back(sf::Vector2f((float)x*slope + from.x, (float)lng));
        x--;
      }
    }
    if (from.y - to.y < 0 && from.x - to.x < 0){
      for (int lng = from.y; lng < from.y + yDistance ; lng++){
        path.push_back(sf::Vector2f((float)x*slope + from.x, (float)lng));
        x++;
      }
    }
    if (from.y - to.y < 0 && from.x - to.x == 0){
      for (int lng = from.y; lng < from.y + yDistance ; lng++){
        path.push_back(sf::Vector2f((float)from.x, (float)lng));
      }
    }
  }
}
