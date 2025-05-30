#pragma once
#include "Shader.hpp"


class Render
{
public:
    Render();
    Render(Render &&) = default;
    Render(const Render &) = default;
    Render &operator=(Render &&) = default;
    Render &operator=(const Render &) = default;
    ~Render();

    int init();
    void render();
private:
    Shader shader;

protected:
    unsigned int VBO, VAO, EBO;
    virtual void initData() = 0;
};