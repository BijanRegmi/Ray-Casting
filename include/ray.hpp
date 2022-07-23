#ifndef RAY_H
#define RAY_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>

class Ray {
public:
  sf::Vector3f m_origin, m_dest, m_direction;

  Ray();
  Ray(sf::Vector3f &origin, sf::Vector3f &dest);
  void calcDirection();
};

#endif
