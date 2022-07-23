#include "camera.hpp"
#include "utils.hpp"
#include <SFML/System/Vector3.hpp>
#include <iostream>

Camera::Camera() {
  cameraPosition = {0.f, 0.f, -3.f};
  cameraLookAt = {0.f, 0.f, 0.f};
  cameraUp = {0.f, 1.f, 0.f};

  cameraLength = 1.f;
  cameraHorizontalSize = 1.f;
  cameraAspectRatio = 1.6f;

  initialize();
}

void Camera::initialize() {
  cameraPrincipleAxis = normalize(cameraLookAt - cameraPosition);

  screenU = normalize(cross(cameraUp, cameraPrincipleAxis));
  screenV = normalize(cross(cameraPrincipleAxis, screenU));
  screenCenter = cameraPosition + cameraLength * cameraPrincipleAxis;

  screenU = screenU * cameraHorizontalSize;
  screenV = screenV * (cameraHorizontalSize / cameraAspectRatio);

  std::cout << "\n\t**CAMERA INITIALIZED TO THESE POINTS**\n";
  PRINT_VEC(cameraPosition);
  PRINT_VEC(cameraLookAt);
  PRINT_VEC(cameraPrincipleAxis);
  PRINT_VEC(screenU);
  PRINT_VEC(screenV);
  PRINT_VEC(screenCenter);
  std::cout << "\n";
}

void Camera::castRay(float screenX, float screenY, Ray &ray) {
  // First moving along u axis then along v axis
  sf::Vector3f worldCord = screenCenter + screenX * screenU + screenY * screenV;

  ray.m_origin = cameraPosition;
  ray.m_dest = worldCord;
  ray.calcDirection();
}
