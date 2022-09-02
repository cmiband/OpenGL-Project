#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Macros.h"

class Application
{
private:
	GLFWwindow* window;

	int startWindow(int w, int h, const char* t);
	void Run();
public:
	Application(int width, int height, const char* title);
	~Application();
};

