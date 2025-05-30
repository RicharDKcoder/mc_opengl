#pragma once

#include <glad/glad.h>
#include <string>

class Shader
{
public:
    Shader();
    Shader(Shader &&) = default;
    Shader(const Shader &) = default;
    Shader &operator=(Shader &&) = default;
    Shader &operator=(const Shader &) = default;
    ~Shader();

    void build(std::string vertexShaderPath, std::string fragmentShaderPath);
    GLuint getShaderProgram();

private:
    std::string vertexShaderPath;
    std::string fragmentShaderPath;

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
};