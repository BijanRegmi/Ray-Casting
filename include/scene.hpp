#include "camera.hpp"
#include "image.hpp"
#include "sphere.hpp"
#include <SFML/Graphics.hpp>

class scene : public sf::Sprite {
private:
  sf::RenderTexture m_texture;
  Camera m_camera;
  Sphere sphere;

public:
  scene();
  scene(int width, int height);

  void create(int width, int height);

  void render(image *Image);
};
