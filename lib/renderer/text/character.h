//
// Created by jesse on 11/8/18.
//

#ifndef __PIE_LIB_RENDERER_CHARACTER_H
#define __PIE_LIB_RENDERER_CHARACTER_H

#include "glad.h"
#include <GLFW/glfw3.h>

#include "renderer/drawable.h"
#include "renderer/text/fontface.h"
#include "renderer/shader.h"
#include "renderer/linmath.h"

namespace pie {

class Character : public Drawable<GLFWwindow> {
 public:
  Character(FontFace &face, char c, const Color &color, const VFShader &sp);
  Character(const Character &) = default;
  ~Character() override = default;

  //! Returns character width in pixels
  double Width() const;

  //! Returns character height in pixels
  double Height() const;

  void Draw(GLFWwindow *window) const override;

  //! Scale the text isotropically
  void Scale(float scale);

  // expose some glyph metrics
  GLuint advance() const;
  std::pair<int, int> bearing() const;

  std::pair<float, float> location() const;

 private:
  void BuildVertices();

 private:

  VFShader shader_;

  Color color_;

  float angle_;
  float scale_;

  GLuint tex_id_;
  GLuint advance_;
  std::pair<int, int> size_;
  std::pair<int, int> bearing_;

  static float vertex_data_[96];

  // vertex array object
  GLuint vao_;
  // vertex buffer object
  GLuint vbo_;

};

} // namespace pie

#endif //PIE_CHARACTER_H
