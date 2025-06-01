#pragma once
#include <glad/glad.h>
#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	void build(std::string vsPath, std::string fragPath);
	GLuint getId();
private:
	GLuint id;
};