#ifndef APP_H
#define APP_H

#include "camera.hpp"
#include "image.hpp"
#include "scene.hpp"
#include <SFML/Graphics.hpp>

class App {
private:
  const int FPS = 60;
  sf::RenderWindow m_window;
  sf::Event m_event;

  scene m_scene;
  image m_image;
  bool running = false, logger = false;

private:
  void processEvent();

public:
  App(int width, int height, const char *title);
  void run();
};

#endif // APP_H
