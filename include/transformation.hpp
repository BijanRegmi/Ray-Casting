#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

class Transformation {
private:
  // Translation
  float T[3];

  // Rotation angle
  float R[3];

  // Scaling factor
  float S[3];

  // Final translation matrix
  float final_matrix[4 * 4];

public:
  Transformation();
  Transformation(float *translation, float *rotation, float *scaling);

  void setTranslation(float *translation);
  void setRotation(float *rotation);
  void setScaling(float *scaling);

  void increase_translate(float translate_amt, bool x, bool y, bool z);
  void increase_rotation(float rotation_angle, bool x, bool y, bool z);
  void increase_scaling(float scaling_factor, bool x, bool y, bool z);

  void calculate_matrix();
  void print_final();

  static bool Matrix_multiplication(float *matrix1, float *matrix2, int m1_r,
                                    int m1_c, int m2_r, int m2_c,
                                    float *result);
  static void Matrix_print(float *matrix, int m1_r, int m1_c);
};

#endif
