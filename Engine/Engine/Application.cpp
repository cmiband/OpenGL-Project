#include "Application.h"

Application::Application(int width, int height, const char* title) {
	if (startWindow(width, height, title) != 0) std::cout << "Error occured during creation of Application constructor" << std::endl;

	Run();
}

Application::~Application() {
	glfwTerminate();
};

int Application::startWindow(int w, int h, const char* t) {
	if (!glfwInit()) return -1;

	window = glfwCreateWindow(w, h, t, NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (GLEW_OK != glewInit()) {
		std::cout << "error" << std::endl;
		return -1;
	}

	return 0;
}

void Application::Run() {
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
