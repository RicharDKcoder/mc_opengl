#include "Window.hpp"


#include <iostream>

Window::Window()
{
}

Window::~Window()
{
}


int Window::init(){
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    this->window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(this->window);
    return 1;
}

bool Window::shouldClose(){
    return glfwWindowShouldClose(this->window);
}

void Window::close(){
    glfwTerminate();
}


GLFWwindow* Window::getHandler(){
    return this->window;
}