#include "image.hpp"

image::image() {}

image::image(int width, int height) { create(width, height); }

void image::create(int width, int height) {
  m_image.create(width, height);
  m_texture.create(width, height);
  this->setTexture(m_texture);
  m_texture.loadFromImage(m_image);
}

void image::display() { m_texture.loadFromImage(m_image); }

sf::Vector2u image::getSize() { return m_image.getSize(); }

void image::setPixel(int x, int y, unsigned int color) {
  m_image.setPixel(x, y, sf::Color(color));
}
