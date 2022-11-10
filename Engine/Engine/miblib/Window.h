#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
	GLFWwindow* m_window;

	int startWindow(int w, int h, const std::string& t);
public:
	Window(int width, int height, const std::string& title);
	~Window();

	inline int shouldClose() const { return glfwWindowShouldClose(m_window); };
	inline GLFWwindow* getGLFWwindow() const { return m_window; };
};

