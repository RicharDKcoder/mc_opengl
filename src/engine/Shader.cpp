#include "Shader.hpp"
#include <iostream>
#include <string>
#include "IOUtil.hpp"

Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::build(std::string vertexShaderPath, std::string fragmentShaderPath){
    this->vertexShaderPath = vertexShaderPath;
    this->fragmentShaderPath = fragmentShaderPath;

    std::string vertexShaderCode = IOUtil::readFile(this->vertexShaderPath);
    std::string fragmentShaderCode = IOUtil::readFile(this->fragmentShaderPath);

    const char* vertexShaderSource = vertexShaderCode.c_str();
    const char* fragmentShaderSource = fragmentShaderCode.c_str();

    this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(this->vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(this->vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(this->fragmentShader);


    glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(this->fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, this->vertexShader);
    glAttachShader(this->shaderProgram, this->fragmentShader);
    glLinkProgram(this->shaderProgram);
    // check for linking errors
    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(this->vertexShader);
    glDeleteShader(this->fragmentShader);
}

GLuint Shader::getShaderProgram(){
    return this->shaderProgram;
}