#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    GLFWwindow* get() const;
    bool isValid() const;

private:
    GLFWwindow* window_ = nullptr;
};

#endif
