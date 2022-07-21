#include "circle.cpp"
#include "sphere.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

class rayTracer {
  int FPS = 60;

  sf::RenderWindow window;
  sf::Event event;

  Renderer *_renderer;
  bool attached = false, logger = false;

public:
  rayTracer(int size, const char *title = "Ray Tracing") {
    window.create(sf::VideoMode(size, size), title);
    window.setFramerateLimit(FPS);
  }

  void attachRenderer(Renderer *renderer) {
    attached = true;
    _renderer = renderer;
  }

  void run() {
    while (this->window.isOpen()) {
      processEvent();
      window.clear();
      window.draw(*(_renderer->getSprite()));
      window.display();
    }
  }

private:
  void processEvent() {
    if (logger) {
      std::cout << "\033[2J\033[1;1HCameraPosition: (" << _renderer->camera.x
                << ", " << _renderer->camera.y << ", " << _renderer->camera.z
                << ")\n";
      std::cout << "LightDirection: (" << _renderer->lightDirection.x << ", "
                << _renderer->lightDirection.y << ", "
                << _renderer->lightDirection.z << ")\n";
    }

    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }

      if (event.type == sf::Event::KeyPressed) {
        sf::Keyboard::Key key = event.key.code;

        if (key == sf::Keyboard::Escape) {
          // Quit of escape
          window.close();
          return;
        } else if (key == sf::Keyboard::Space && attached) {
          // Render on space
          _renderer->render();
          return;
        } else if (key == sf::Keyboard::L) {
          // Toggle logger
          logger ^= true;
          std::cout << "\033[2J\033[1;1H\n";
        }

        if (event.key.control) {
          // Camera controls
          switch (key) {
          case sf::Keyboard::Left:
            _renderer->moveCamera(-0.1f, 0.f, 0.f);
            _renderer->render();
            break;
          case sf::Keyboard::Right:
            _renderer->moveCamera(+0.1f, 0.f, 0.f);
            _renderer->render();
            break;
          case sf::Keyboard::Up:
            if (event.key.shift)
              _renderer->moveCamera(0.f, 0.f, -0.1f);
            else
              _renderer->moveCamera(0.f, -0.1f, 0.f);
            _renderer->render();
            break;
          case sf::Keyboard::Down:
            if (event.key.shift)
              _renderer->moveCamera(0.f, 0.f, +0.1f);
            else
              _renderer->moveCamera(0.f, +0.1f, 0.f);
            _renderer->render();
            break;
          default:
            break;
          }

        } else {
          // Light controls
          switch (key) {
          case sf::Keyboard::Left:
            _renderer->rotateLight(-1.f, 0.f, 0.f);
            _renderer->render();
            break;
          case sf::Keyboard::Right:
            _renderer->rotateLight(+1.f, 0.f, 0.f);
            _renderer->render();
            break;
          case sf::Keyboard::Up:
            if (event.key.shift)
              _renderer->rotateLight(0.f, 0.f, -1.f);
            else
              _renderer->rotateLight(0.f, +1.f, 0.f);
            _renderer->render();
            break;
          case sf::Keyboard::Down:
            if (event.key.shift)
              _renderer->rotateLight(0.f, 0.f, +1.f);
            else
              _renderer->rotateLight(0.f, -1.f, 0.f);
            _renderer->render();
            break;
          default:
            break;
          }
        }
      }
    }
  }
};

int main() {
  rayTracer window(600, "Sphere");

  Circle sphere;
  sphere.setRadius(0.5f);
  sphere.setImageSize(600);
  sphere.setCameraPosition(0.f, 0.f, 1.f);
  sphere.setLightDirection(0.f, 0.f, -3.f);

  window.attachRenderer(&sphere);
  window.run();
}
