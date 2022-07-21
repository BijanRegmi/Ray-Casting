#ifndef UTILS_H
#define UTILS_H
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <iostream>

template <typename T> sf::Vector3<float> normalize(sf::Vector3<T> vec) {
  float mag = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
  return sf::Vector3<float>(vec.x / mag, vec.y / mag, vec.z / mag);
}

template <typename T> sf::Vector2<float> normalize(sf::Vector2<T> vec) {
  float mag = std::sqrt(vec.x * vec.x + vec.y * vec.y);
  return sf::Vector2<float>(vec.x / mag, vec.y / mag);
}

template <typename T> T dot(sf::Vector3<T> vec1, sf::Vector3<T> vec2) {
  return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

template <typename T> T dot(sf::Vector2<T> vec1, sf::Vector2<T> vec2) {
  return vec1.x * vec2.x + vec1.y * vec2.y;
}
#endif // UTILS_H
