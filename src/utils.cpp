#include "utils.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <iostream>

sf::Vector3f normalize(sf::Vector3f vec) {
  float mag = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
  return sf::Vector3<float>(vec.x / mag, vec.y / mag, vec.z / mag);
}

sf::Vector2f normalize(sf::Vector2f vec) {
  float mag = std::sqrt(vec.x * vec.x + vec.y * vec.y);
  return sf::Vector2<float>(vec.x / mag, vec.y / mag);
}

float dot(sf::Vector3f vec1, sf::Vector3f vec2) {
  return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

float dot(sf::Vector2f vec1, sf::Vector2f vec2) {
  return vec1.x * vec2.x + vec1.y * vec2.y;
}

sf::Vector3f cross(sf::Vector3f vec1, sf::Vector3f vec2) {
  float x = vec1.y * vec2.z - vec1.z * vec2.y;
  float y = vec1.z * vec2.x - vec1.x * vec2.z;
  float z = vec1.x * vec2.y - vec1.y * vec2.x;
  return sf::Vector3f(x, y, z);
}

float magnitude(sf::Vector3f vec) {
  return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
