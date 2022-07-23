#include "app.hpp"
#include "image.hpp"
#include <iostream>

App::App(int width, int height, const char *title = "Ray Tracing") {
  running = true;
  m_window.create(sf::VideoMode(width, height), title);
  m_window.setFramerateLimit(FPS);
  m_scene.create(width, height);
  m_image.create(width, height);
}

void App::run() {
  while (running) {
    processEvent();
    m_window.clear();
    m_window.draw(m_scene);
    m_window.display();
  }

  m_window.close();
  std::cout << "Window closed" << std::endl;
}

void App::processEvent() {
  /*if (logger) {
    std::cout << "\033[2J\033[1;1HCameraPosition: (" << // _renderer->camera.x
              << ", " << // _renderer->camera.y << ", " << _renderer->camera.z
              << ")\n";
    std::cout << "LightDirection: (" << // _renderer->lightDirection.x << ", "
              << // _renderer->lightDirection.y << ", "
              << // _renderer->lightDirection.z << ")\n";
  }*/

  while (m_window.pollEvent(m_event)) {
    if (m_event.type == sf::Event::Closed) {
      running = false;
      break;
    }

    if (m_event.type == sf::Event::KeyPressed) {
      sf::Keyboard::Key key = m_event.key.code;

      if (key == sf::Keyboard::Escape) {
        // Quit of escape
        running = false;
        return;
      } else if (key == sf::Keyboard::Space) {
        // Render on space
        std::cout << "Rendering" << std::endl;
        m_scene.render(&m_image);
        return;
      } else if (key == sf::Keyboard::L) {
        // Toggle logger
        std::cout << "\033[2J\033[1;1H\n";
      }
    }
  }
};
