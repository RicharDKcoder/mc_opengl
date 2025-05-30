#pragma once

#include "Window.hpp"

class Input
{
public:
    Input();
    Input(Input &&) = default;
    Input(const Input &) = default;
    Input &operator=(Input &&) = default;
    Input &operator=(const Input &) = default;
    ~Input();

    void init(Window window);

    void handler();
private:
    Window window;
};