#include "Application.h"

#include "MEngine.h"

Application::Application(int width, int height, const std::string& title) {
	if (startWindow(width, height, title) != 0) {
		std::cout << "Error occured during creation of Application constructor" << std::endl;
		glfwTerminate();
	}

	Run();
}

Application::~Application() {
	glfwTerminate();
};

int Application::startWindow(int w, int h, const std::string &t) {
	if (!glfwInit()) return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(w, h, t.c_str(), NULL, NULL);
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
	EntityContainer entities;
	Triangle triangle(math::Vector2<float>{-0.5f, -0.5f}, 0.5f, math::Color4<float>{1.0f, 0.5f, 0.5f, 1.0f});
	Square square(math::Vector2<float>{0.0f, 0.0f}, 0.5f, math::Color4<float>{0.7f, 0.6f, 0.5f, 1.0f});

	Renderer render;

	triangle.UnbindPropeties();
	square.UnbindPropeties();

	while (!glfwWindowShouldClose(window))
	{
		render.Clear();
		square.Draw(render);

		triangle.Draw(render);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
