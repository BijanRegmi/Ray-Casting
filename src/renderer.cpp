#ifndef RENDERER_H
#define RENDERER_H
#include "utils.cpp"
#include <SFML/Graphics.hpp>

class Renderer {
  int imageSize = 0;

  sf::Image image;
  sf::Sprite sprite;
  sf::Texture texture;

public:
  sf::Vector3<float> lightDirection;
  sf::Vector3<float> camera;
  sf::Vector3<float> light;

  sf::Vector2<float> viewPortSize = {2.f, 2.f};

public:
  Renderer() {}

  void setImageSize(int imageSize) {
    this->imageSize = imageSize;
    image.create(imageSize, imageSize);
    texture.create(imageSize, imageSize);
    sprite.setTexture(texture);
  }

  void setCameraPosition(float x, float y, float z) {
    camera.x = x;
    camera.y = y;
    camera.z = z;
  }

  void setLightDirection(float x, float y, float z) {
    lightDirection.x = x;
    lightDirection.y = y;
    lightDirection.z = z;
    light = normalize(lightDirection);
  }

  void moveCamera(float x, float y, float z) {
    camera.x += x;
    camera.y += y;
    camera.z += z;
  }

  void rotateLight(float x, float y, float z) {
    lightDirection.x += x;
    lightDirection.y += y;
    lightDirection.z += z;
    light = normalize(lightDirection);
  }

  void setViewPortSize(float width, float height) {
    viewPortSize.x = width;
    viewPortSize.y = height;
  }

  void render() {
    for (int y = 0; y < imageSize; y++) {
      for (int x = 0; x < imageSize; x++) {
        sf::Vector3<float> cord(viewPortSize.x * ((float)x / imageSize - 0.5f),
                                viewPortSize.y * ((float)y / imageSize - 0.5f),
                                -1.f);

        image.setPixel(x, y, sf::Color(drawPixel(cord)));
      }
    }

    texture.loadFromImage(image);
  }

  sf::Sprite *getSprite() { return &sprite; }

protected:
  virtual sf::Uint32 drawPixel(sf::Vector3<float> rayDirection) const = 0;
};
#endif
