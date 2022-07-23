#include "scene.hpp"
#include "object.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "utils.hpp"

#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

#include <chrono>
#include <iostream>
#include <memory>

scene::scene() {}

scene::scene(int width, int height) { create(width, height); }

void scene::create(int width, int height) {
  m_texture.create(width, height);
  this->setTexture(m_texture.getTexture());
  objects.push_back(std::make_shared<Sphere>(Sphere(1.f)));
}

void scene::render(image *Image) {
  auto t1 = std::chrono::high_resolution_clock::now();

  sf::Vector2u size = Image->getSize();

  Ray ray;
  sf::Vector3f hitposition, normal;
  unsigned int color;
  float intensity;

  float xF = 2.f / (size.x - 1); // range is from 0 to size - 1
  float yF = 2.f / (size.y - 1);

  for (unsigned int y = 0; y < size.y; y++) {
    for (unsigned int x = 0; x < size.x; x++) {
      float screenX = x * xF - 1.f;
      float screenY = 1.f - y * yF; // inverting the y axis

      m_camera.castRay(screenX, screenY, ray);

      for (auto obj : objects) {
        bool intersect = obj->didIntersect(ray, hitposition, normal, color);

        if (intersect) {
          bool illum =
              m_light.calcIlluminance(hitposition, normal, color, intensity);
          if (illum) {
            int r = 255 - 255 * intensity;
            Image->setPixel(x, y, 0x000000ff | (r << 24));
          } else {
            Image->setPixel(x, y, 0x000000ff);
          }
        } else {
          Image->setPixel(x, y, 0x000000ff);
        }
      }
    }
  }
  Image->display();

  m_texture.clear();
  m_texture.draw(*Image);
  m_texture.display();
  this->setTexture(m_texture.getTexture());

  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ms = t2 - t1;
  std::cout << "Rendering completed in: " << ms.count() << " milliseconds.\n";
}
