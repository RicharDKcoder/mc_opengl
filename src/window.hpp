#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class Window
{
public:
	Window();
	~Window();

	bool init();
	GLFWwindow* getId();
	bool shouldClose();
	void processInput();
	void swapBuffers();
	void close();
private:
	GLFWwindow* id;
};


