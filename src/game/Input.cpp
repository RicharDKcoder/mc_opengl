#include "Input.hpp"

Input::Input()
{
}

Input::~Input()
{
}


void Input::init(Window window){
    this->window = window;
}


void Input::handler(){
    if(glfwGetKey(this->window.getHandler(), GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(this->window.getHandler(), true);
    }
        
}