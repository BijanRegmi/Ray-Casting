#include "renderer.cpp"
#include "utils.cpp"

class Circle : public Renderer {
private:
  float radius;

public:
  Circle() : Renderer() {}
  Circle(float r) : Renderer() { radius = r; }

  void setRadius(float r) { radius = r; }

  sf::Uint32 drawPixel(sf::Vector3<float> rayDirection) const {

    if (rayDirection.x * rayDirection.x + rayDirection.y * rayDirection.y <=
        radius * radius)
      return 0x00ff00ff;
    return 0x000000ff;
  }
};
