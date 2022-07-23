#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>

class image : public sf::Sprite {
private:
  sf::Texture m_texture;
  sf::Image m_image;

public:
  image();
  image(int width, int height);

  void create(int width, int height);
  void display();

  sf::Vector2u getSize();
  void setPixel(int x, int y, unsigned int color);
};

#endif // IMAGE_H
