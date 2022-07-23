#include "scene.hpp"
#include "ray.hpp"
#include "utils.hpp"
#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <ratio>

scene::scene() {}

scene::scene(int width, int height) { create(width, height); }

void scene::create(int width, int height) {
  sphere.setRadius(1.f);
  m_texture.create(width, height);
  this->setTexture(m_texture.getTexture());
}

void scene::render(image *Image) {
  auto t1 = std::chrono::high_resolution_clock::now();

  sf::Vector2u size = Image->getSize();

  Ray ray;
  sf::Vector3f hitposition, normal;
  unsigned int color;

  float xF = 2.f / (size.x - 1); // range is from 0 to size - 1
  float yF = 2.f / (size.y - 1);

  float minDist = 1e9;
  float maxDist = 0;

  for (unsigned int y = 0; y < size.y; y++) {
    for (unsigned int x = 0; x < size.x; x++) {
      float screenX = x * xF - 1.f;
      float screenY = 1.f - y * yF; // inverting the y axis

      m_camera.castRay(screenX, screenY, ray);

      bool intersect = sphere.didIntersect(ray, hitposition, normal, color);

      if (intersect) {
        float dist = magnitude(ray.m_origin - hitposition);
        if (dist > maxDist)
          maxDist = dist;
        if (dist < minDist)
          minDist = dist;
        int r = 255 - 255 * (dist - 2.f) / 0.82843;
        Image->setPixel(x, y, 0x000000ff | (r << 24));
      } else {
        Image->setPixel(x, y, 0x000000ff);
      }
    }
  }
  Image->display();
  std::cout << "Max: " << maxDist << "\tMin: " << minDist << std::endl;

  m_texture.clear();
  m_texture.draw(*Image);
  m_texture.display();
  this->setTexture(m_texture.getTexture());

  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms = t2 - t1;
  std::cout << "Rendering completed in: " << ms.count() << " milliseconds.\n";
}
