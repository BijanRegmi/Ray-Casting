#ifndef OBJ_SPHERE_H
#define OBJ_SPHERE_H

#include "object.hpp"

class Sphere : public Object {
private:
  float radius;

public:
  Sphere();
  Sphere(float r);

  void setRadius(float r);
  virtual bool didIntersect(Ray &shootingRay, sf::Vector3f &hitposition,
                            sf::Vector3f &normal, unsigned int &color);
};

#endif
