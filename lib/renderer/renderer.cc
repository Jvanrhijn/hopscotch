//
// Created by jesse on 10/30/18.
//
#include "renderer.h"

namespace pie {

Renderer::Renderer(size_t width, size_t height)
  : width_(width), height_(height)
{
  // Initialize GLFW
  if(!glfwInit()) {
    throw RenderException("Failed to initialize OpenGL");
  }
  // set OpenGL version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  if (!(window_ = glfwCreateWindow(width, height, "Game", nullptr, nullptr))) {
    throw RenderException("Failed to create window");
  }
  // Output errors to stderr
  glfwMakeContextCurrent(window_);
  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    throw RenderException("Failed to load OpenGL");
  }
  glfwSwapInterval(1);
  glfwSetErrorCallback([](int err, const char* descr) {
    std::cerr << "GLFW ERROR: " << err << ": " << descr << std::endl;
  });
  // setup viewport
  glViewport(0, 0, width_, height_);
  // OpenGL options
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Renderer::~Renderer() {
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void Renderer::AddObject(std::shared_ptr<pie::Drawable<GLFWwindow>> object) {
  objects_.push_back(std::move(object));
}

void Renderer::Clear() {
  objects_.clear();
}

void Renderer::Loop() const {
  // see OpenGL docs for more information on how rendering works
  while(!glfwWindowShouldClose(window_)) {
    // Set background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (const auto& obj: objects_) {
      if (obj) {
        DrawObject(*obj);
      }
    }
    glfwSwapBuffers(window_);
    glfwWaitEvents();
  }
}

GLFWwindow *Renderer::window() const {
  return window_;
}

void Renderer::DrawObject(const Drawable<GLFWwindow>& object) const {
  object.Draw(window_);
}

}
