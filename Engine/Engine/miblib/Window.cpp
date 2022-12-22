#include "Window.h"

#include "miblib.h"
#include <math.h>
#include <corecrt_math_defines.h>

Window::Window(int width, int height, const std::string& title) {
	if (startWindow(width, height, title) != 0) {
		std::cout << "Error occured during creation of Window constructor" << std::endl;
		glfwTerminate();
	}
}

Window::~Window() {
	glfwTerminate();
	delete m_window;
};

int Window::startWindow(int w, int h, const std::string& t) {
	if (!glfwInit()) return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_window = glfwCreateWindow(w, h, t.c_str(), NULL, NULL);
	if (!m_window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_window);

	if (GLEW_OK != glewInit()) {
		std::cout << "error" << std::endl;
		return -1;
	}

	return 0;
}