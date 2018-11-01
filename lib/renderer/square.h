//
// Created by jesse on 10/31/18.
//

#ifndef __PIE_LIB_RENDERER_SQUARE_H
#define __PIE_LIB_RENDERER_SQUARE_H

#include <iostream>

#include "lib/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include "lib/renderer/shape.h"
#include "lib/renderer/util/load_shader.h"
#include "lib/draw/drawable.h"
#include "lib/linmath.h"

namespace pie {

class Square : public Shape, public Drawable<GLFWwindow> {
 public:
  Square(double x, double y, double side);
  ~Square() override = default;

  void Draw(GLFWwindow*) const override;

  const GLuint& program() const;

 private:
  double side_;
  GLuint vertex_array_id_;
  GLuint vertex_buffer_;
  GLuint program_;

  // shader data
  GLint mvp_location_;
  GLint vpos_location_;
  GLint vcol_location_;

  //! Rendering details: (-1, -1) is the lower left corner
  struct vbuffer_ {
    float x, y;
    float r, g, b;
  };
  static constexpr vbuffer_ vertex_buffer_data_[3] {
      {-0.6f, -0.4f, 1.0f, 0.0f, 0.0f},
      {0.6f,  -0.4f, 0.0f, 1.0f, 0.0f},
      {0.0f,   0.6f, 0.0f, 0.0f, 1.0f}
  };

  static constexpr char const *vertex_shader_path_{"lib/renderer/shaders/vertex_shader_test.vertexshader"};
  static constexpr char const *fragment_shader_path_{"lib/renderer/shaders/fragment_shader_test.fragmentshader"};

};

}

#endif // __PIE_LIB_RENDERER_SQUARE_H
