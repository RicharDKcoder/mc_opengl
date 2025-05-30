#pragma once

#include <glad/glad.h>

class Shader
{
public:
    Shader();
    Shader(Shader &&) = default;
    Shader(const Shader &) = default;
    Shader &operator=(Shader &&) = default;
    Shader &operator=(const Shader &) = default;
    ~Shader();

    void init(const char* vertexShaderSource, const char* fragmentShaderSource);
    void build();
    unsigned int getShaderProgram();

private:
    const char* vertexShaderSource;
    const char* fragmentShaderSource;

    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
};