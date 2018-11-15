//
// Created by jesse on 11/8/18.
//

#include "fontface.h"

namespace pie {

FontFace::FontFace(const std::string &path, size_t size) {
  if (FT_Init_FreeType(&ftlib_)) {
    std::cerr << "Failed to load freetype library" << std::endl;
    exit(10);
  }
  if (FT_New_Face(ftlib_, path.c_str(), 0, &face_)) {
    std::cerr << "Failed to load font at " << path << std::endl;
    exit(11);
  }
  FT_Set_Pixel_Sizes(face_, 0, size);
}

FontFace::~FontFace() {
  FT_Done_Face(face_);
  FT_Done_FreeType(ftlib_);
}

void FontFace::LoadChar(const char c) {
  if (FT_Load_Char(face_, static_cast<unsigned short>(c), FT_LOAD_RENDER)) {
    std::cerr << "Failed to load glyph" << std::endl;
    exit(12);
  }
}

const FT_Face& FontFace::face() const {
  return face_;
}

} // namespace pie
