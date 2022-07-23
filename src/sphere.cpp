#include "sphere.hpp"
#include "object.hpp"
#include "ray.hpp"
#include "utils.hpp"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

Sphere::Sphere() : Object() {}

Sphere::Sphere(float r) : Object() { radius = r; }

void Sphere::setRadius(float r) { radius = r; }

bool Sphere::didIntersect(Ray &shootingRay, sf::Vector3f &hitposition,
                          sf::Vector3f &normal, unsigned int &color) {

  float a = dot(shootingRay.m_direction, shootingRay.m_direction);
  float b = 2.f * dot(shootingRay.m_direction, shootingRay.m_origin);
  float c = dot(shootingRay.m_origin, shootingRay.m_origin) - radius * radius;

  float discriminant = b * b - 4 * a * c;

  if (discriminant < 0)
    return false;

  // Calculate the hitposition
  float s_dis = std::sqrt(discriminant);
  float t[] = {(-b + s_dis) / (2.f * a), (-b - s_dis) / (2.f * a)};

  // If either one is less part of sphere is behind the camera
  if (t[0] < 0 || t[1] < 0)
    return false;

  float tmin = std::min(t[0], t[1]);
  hitposition = shootingRay.m_origin + shootingRay.m_direction * tmin;

  return true;
}
