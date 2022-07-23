#ifndef OBJECT_H
#define OBJECT_H

#include "ray.hpp"
#include <SFML/System/Utf.hpp>
#include <SFML/System/Vector3.hpp>
class Object {
public:
  Object();
  virtual ~Object();

  virtual bool didIntersect(Ray &shootingRay, sf::Vector3f &hitposition,
                            sf::Vector3f &normal, unsigned int &color) = 0;
};

#endif // OBJECT_H
