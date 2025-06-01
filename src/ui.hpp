#pragma once

#include "GLFW/glfw3.h"

class UI
{
public:
    UI();
    UI(UI &&) = default;
    UI(const UI &) = default;
    UI &operator=(UI &&) = default;
    UI &operator=(const UI &) = default;
    ~UI();

    void init(GLFWwindow *mainWindow);
    void loop_start();
    void loop_end();
    void close();
private:
};