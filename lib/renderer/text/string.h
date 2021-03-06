//
// Created by jesse on 11/10/18.
//

#ifndef PIE_STRING_H
#define PIE_STRING_H

#include <string>
#include <algorithm>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "../drawable.h"
#include "../text/charmap.h"
#include "../text/character.h"

namespace pie {

class String : public Drawable<GLFWwindow> {
 public:
  String(std::string text, const charmap& char_map, float scale=1.0f);

  void Center();

  void Draw(GLFWwindow*) const override;

  void Rotate(float angle) override;

 private:
  std::string text_;

  std::vector<Character> characters_;

  float scale_;

};

} // namespace pie

#endif //PIE_STRING_H
