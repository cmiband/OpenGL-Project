#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Application
{
private:
	GLFWwindow* window;

	int startWindow(int w, int h, std::string t);
	void Run();
public:
	Application(int width, int height, const std::string& title);
	~Application();
};

