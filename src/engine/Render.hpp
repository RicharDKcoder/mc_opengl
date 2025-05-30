#pragma once
#include "Shader.hpp"
#include <string>

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
    virtual void render() = 0;

protected:
    GLuint  VBO, VAO, EBO;
    std::string vertexShaderPath, fragmentShaderPath;
    Shader shader;

    virtual void initData() = 0;
    virtual void initShader() = 0;
};