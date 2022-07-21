#include "renderer.cpp"
#include "utils.cpp"

class Sphere : public Renderer {
private:
  float radius;

public:
  Sphere() : Renderer() {}
  Sphere(float r) : Renderer() { radius = r; }

  void setRadius(float r) { radius = r; }

  sf::Uint32 drawPixel(sf::Vector3<float> rayDirection) const {
    float a = dot(rayDirection, rayDirection);
    float b = 2.f * dot(rayDirection, camera);
    float c = dot(camera, camera) - radius * radius;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0.f)
      return 0x000000ff;

    // If it hits the sphere
    float t[] = {(-b + std::sqrt(discriminant)) / (2.f * a),
                 (-b - std::sqrt(discriminant)) / (2.f * a)};

    float dist = std::min(t[0], t[1]); // closest one to the camera

    sf::Vector3<float> hitposition = camera + rayDirection * dist;
    hitposition = normalize(hitposition); // normal at that point
    float lightIntensity = std::max(dot(hitposition, -light), 0.f);
    return 0xaaaaaa00 | (int(255 * lightIntensity));
  }
};
