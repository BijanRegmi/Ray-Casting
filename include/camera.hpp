#ifndef CAMERA_H
#define CAMERA_H

#include "ray.hpp"
#include <SFML/System/Vector3.hpp>
class Camera {
private:
  sf::Vector3f cameraPosition;      // co-ordinate
  sf::Vector3f cameraLookAt;        // co-ordinate
  sf::Vector3f cameraUp;            // direction vector
  sf::Vector3f cameraPrincipleAxis; // direction vector
  float cameraLength;
  float cameraHorizontalSize;
  float cameraAspectRatio; // width/height

  sf::Vector3f screenU;      // direction vector
  sf::Vector3f screenV;      // direction vector
  sf::Vector3f screenCenter; // co-ordinate

  void initialize();

public:
  Camera();

  void castRay(float screenX, float screenY, Ray &ray);
};

#endif // CAMERA_H
