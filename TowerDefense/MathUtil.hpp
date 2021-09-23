#ifndef MATHUTIL_HPP
#define MATHUTIL_HPP
#include <SFML/Graphics.hpp>
#include <vector>

class MathUtil{
public:
  MathUtil() = default;

  void AtoB(std::vector<sf::Vector2f>& path, const sf::Vector2f& from,
                                             const sf::Vector2f& to){
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

  std::vector<sf::Vector2f> AtoBVec(const sf::Vector2f& from, const sf::Vector2f& to){
    std::vector<sf::Vector2f> path = {};
    int xDistance = abs(from.x - to.x);
    int yDistance = abs(from.y - to.y);
    if (from.x == to.x && from.y == to.y){
      //path = {sf::Vector2f(0,0)};
      return path;
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
    return path;
  }


};

#endif
