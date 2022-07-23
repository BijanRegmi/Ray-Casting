#include "ray.hpp"
#include "utils.hpp"

Ray::Ray() { calcDirection(); }

Ray::Ray(sf::Vector3f &origin, sf::Vector3f &dest) {
  m_origin = origin;
  m_dest = dest;

  calcDirection();
}

void Ray::calcDirection() { m_direction = m_dest - m_origin; }
