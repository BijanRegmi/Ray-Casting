#include "light.hpp"
#include "ray.hpp"
#include "utils.hpp"
#include <SFML/System/Vector3.hpp>
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

light::light() {
  m_position = {-3.f, 3.f, -3.f};
  m_intensity = 1.0f;
};

bool light::calcIlluminance(sf::Vector3f &hitposition,
                            const sf::Vector3f &normal, unsigned int &color,
                            float &intensity) {

  Ray ray(hitposition, m_position); // Inorder to find angle the vector must go
                                    // from hitposition to light source
  sf::Vector3f ray_dir = normalize(ray.m_direction);

  float angle = std::acos(dot(normal, ray_dir));

  // If angle is greater than 90 degree
  float half_pi = M_PI / 2;
  if (angle > half_pi)
    return false;

  intensity = m_intensity * angle / half_pi;
  return true;
}
