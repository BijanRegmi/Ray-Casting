#include "camera.hpp"
#include "image.hpp"
#include "light.hpp"
#include "object.hpp"
#include "sphere.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class scene : public sf::Sprite {
private:
  sf::RenderTexture m_texture;
  Camera m_camera;
  std::vector<std::shared_ptr<Object>> objects;
  light m_light;

public:
  scene();
  scene(int width, int height);

  void create(int width, int height);

  void render(image *Image);
};
