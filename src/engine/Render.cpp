#include "Render.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

Render::Render()
{
}

Render::~Render()
{
}

int Render::init(){
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    this->initData();
    this->initShader();
    return 1;
}