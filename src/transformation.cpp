#include "transformation.hpp"
#include <cmath>
#include <iostream>

Transformation::Transformation() {
  // Initialize translation
  T[0] = 0;
  T[1] = 0;
  T[2] = 0;

  // Initialize rotation
  R[0] = 0;
  R[1] = 0;
  R[2] = 0;

  // Initialize scaling
  S[0] = 1;
  S[1] = 1;
  S[2] = 1;
};

Transformation::Transformation(float *translation, float *rotation,
                               float *scaling) {
  setTranslation(translation);
  setRotation(rotation);
  setScaling(scaling);
}

void Transformation::setTranslation(float *translation) {
  // Initialize translation
  T[0] = translation[0];
  T[1] = translation[1];
  T[2] = translation[2];
}

void Transformation::setRotation(float *rotation) {
  // Initialize rotation
  R[0] = rotation[0];
  R[1] = rotation[1];
  R[2] = rotation[2];
}

void Transformation::setScaling(float *scaling) {
  // Initialize scaling
  S[0] = scaling[0];
  S[1] = scaling[1];
  S[2] = scaling[2];
}

void Transformation::increase_translate(float translate_amt, bool x, bool y,
                                        bool z) {
  if (x)
    T[0] += translate_amt;

  if (y)
    T[1] += translate_amt;

  if (z)
    T[2] += translate_amt;
}
void Transformation::increase_rotation(float rotation_angle, bool x, bool y,
                                       bool z) {
  if (x)
    R[0] += rotation_angle;

  if (y)
    R[1] += rotation_angle;

  if (z)
    R[2] += rotation_angle;
}
void Transformation::increase_scaling(float scaling_factor, bool x, bool y,
                                      bool z) {

  if (x)
    S[0] += scaling_factor;

  if (y)
    S[1] += scaling_factor;

  if (z)
    S[2] += scaling_factor;
}

void Transformation::calculate_matrix() {
  float translation[4 * 4] = {1, 0, 0, T[0],
                              //
                              0, 1, 0, T[1],
                              //
                              0, 0, 1, T[2],
                              //
                              0, 0, 0, 1};

  float rotationX[4 * 4] = {1, 0, 0, 0,
                            //
                            0, std::cos(R[0]), -std::sin(R[0]), 0,
                            //
                            0, std::sin(R[0]), std::cos(R[0]), 0,
                            //
                            0, 0, 0, 1};

  float rotationY[4 * 4] = {std::cos(R[1]), 0, -std::sin(R[1]), 0,
                            //
                            0, 1, 0, 0,
                            //
                            std::sin(R[1]), 0, std::cos(R[1]), 0,
                            //
                            0, 0, 0, 1};

  float rotationZ[4 * 4] = {std::cos(R[2]), -std::sin(R[2]), 0, 0,
                            //
                            std::sin(R[2]), std::cos(R[2]), 0, 0,
                            //
                            0, 0, 1, 0,
                            //
                            0, 0, 0, 1};

  float scaling[4 * 4] = {S[0], 0, 0, 0,
                          //
                          0, S[1], 0, 0,
                          //
                          0, 0, S[2], 0,
                          //
                          0, 0, 0, 1};

  float temp_result[4 * 4];

  Matrix_multiplication(rotationX, scaling, 4, 4, 4, 4, temp_result);
  Matrix_multiplication(rotationY, temp_result, 4, 4, 4, 4, final_matrix);
  Matrix_multiplication(rotationZ, final_matrix, 4, 4, 4, 4, temp_result);
  Matrix_multiplication(translation, temp_result, 4, 4, 4, 4, final_matrix);
}

void Transformation::print_final() {
  Transformation::Matrix_print(final_matrix, 4, 4);
}

bool Transformation::Matrix_multiplication(float *matrix1, float *matrix2,
                                           int m1_r, int m1_c, int m2_r,
                                           int m2_c, float *result) {
  if (m1_c != m2_r)
    return false;

  // result[i][j] = mat1[i][[j]] * mat2[[i]][j]; Loop over double bracket
  // result dimension: m1_r*m2_c

  int val = 0;
  for (int i = 0; i < m1_r; ++i) {
    for (int j = 0; j < m2_c; ++j) {
      val = 0;
      for (int k = 0; k < m1_c; ++k) {
        val += (matrix1[i * m1_c + k] * matrix2[k * m2_c + j]);
      }
      result[i * m2_c + j] = val;
    }
  }

  return true;
}

void Transformation::Matrix_print(float *matrix, int m1_r, int m1_c) {
  for (int i = 0; i < m1_r; ++i) {
    for (int j = 0; j < m1_c; ++j) {
      std::cout << matrix[i * m1_c + j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "\n";
}
