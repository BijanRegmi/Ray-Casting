#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>

#define PRINT_VEC(vec)                                                         \
  std::cout << #vec << ": (" << vec.x << ", " << vec.y << ", " << vec.z        \
            << ")\n";

sf::Vector3f normalize(sf::Vector3f vec);
sf::Vector2f normalize(sf::Vector2f vec);

float dot(sf::Vector3f vec1, sf::Vector3f vec2);
float dot(sf::Vector2f vec1, sf::Vector2f vec2);

sf::Vector3f cross(sf::Vector3f vec1, sf::Vector3f vec2);

float magnitude(sf::Vector3f vec);

#endif // UTILS_H
