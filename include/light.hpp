#ifndef LIGHT_H
#define LIGHT_H

#include "object.hpp"
#include <SFML/System/Vector3.hpp>
class light {
private:
  float m_intensity = 1;
  sf::Vector3f m_position;

public:
  light();

  bool calcIlluminance(sf::Vector3f &hitposition, const sf::Vector3f &normal,
                       unsigned int &color, float &intensity);
};

#endif
