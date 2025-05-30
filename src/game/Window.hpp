#pragma once
#include <GLFW/glfw3.h>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


class Window
{
public:
    Window();
    Window(Window &&) = default;
    Window(const Window &) = default;
    Window &operator=(Window &&) = default;
    Window &operator=(const Window &) = default;
    ~Window();


    int init();

    bool shouldClose();

    void close();

    GLFWwindow* getHandler();

private:
    GLFWwindow* window;
};